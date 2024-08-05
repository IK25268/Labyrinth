#include <cmath>
#include <iostream>
#include <fstream>
#include "WaveAlg.hpp"

Labyrinth WaveAlg::CalcLabyrinth(Labyrinth labyrinth)
{
	CalcWave(labyrinth);
	DrawRoute(labyrinth);
	return labyrinth;
}

void WaveAlg::CalcWave(Labyrinth& labyrinth)
{
	labyrinth.ReturnCells()[labyrinth.GetHero()].first = 0;
	waveCells.push(labyrinth.GetHero());
	while (waveCells.size() != 0)
	{
		CalcCell(labyrinth);
	}
}

void WaveAlg::CalcCell(Labyrinth& labyrinth)
{
	unsigned int cell = waveCells.front();
	for (int y = -1; y < 2; y++)
	{
		for (int x = -1; x < 2; x++)
		{
			unsigned int nextCell = (cell + y * (labyrinth.GetCols())) + x;
			if ((labyrinth.ReturnCells()[nextCell].first == -1) && (labyrinth.ReturnCells()[nextCell].second != '1') && (!((y == 0) && (x == 0))))
			{
				labyrinth.ReturnCells()[nextCell].first = labyrinth.ReturnCells()[cell].first + 1;
				waveCells.push(nextCell);
				if (labyrinth.ReturnCells()[nextCell].second == '3')
				{
					while (waveCells.size() != 0)
					{
						waveCells.pop();
					}
				}
			}
		}
	}
	if (waveCells.size() != 0) waveCells.pop();
}

void WaveAlg::DrawRoute(Labyrinth& labyrinth)
{
	unsigned int cell = labyrinth.GetExit();
	int level = labyrinth.ReturnCells()[cell].first;
	while (level > 0)
	{
		char iter = 0;
		unsigned int nextCell = 0;
		for (iter = 0; level == labyrinth.ReturnCells()[cell].first; iter++)
		{
			nextCell = ((cell + iterY[iter] * (labyrinth.GetCols())) + iterX[iter]);
			if (labyrinth.ReturnCells()[nextCell].first == (level - 1))
			{
				level--;
				if (labyrinth.ReturnCells()[cell].second == '0') labyrinth.ReturnCells()[cell].second = '*';
			}
		}
		cell = nextCell;
	}
}

int WaveAlg::CalcPos(Labyrinth& labyrinth, unsigned int x, unsigned int y)
{
	return y * labyrinth.GetCols() + x;
}