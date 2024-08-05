#include <cmath>
#include <iostream>
#include <fstream>
#include "Labyrinth.hpp"

std::map<unsigned int, std::pair<int, char>>& Labyrinth::ReturnCells()
{
	return cells;
}

void Labyrinth::SetCell(unsigned int pos, int level, char type)
{
	cells[pos] = { level, type };
}

unsigned int Labyrinth::GetCols()
{
	return cols;
}

unsigned int Labyrinth::GetRows()
{
	return rows;
}

unsigned int Labyrinth::GetHero()
{
	return hero;
}

unsigned int Labyrinth::GetExit()
{
	return exit;
}

void Labyrinth::SetCols(unsigned int _cols)
{
	cols = _cols;
}

void Labyrinth::SetRows(unsigned int _rows)
{
	rows = _rows;
}

void Labyrinth::SetHero(unsigned int _hero)
{
	hero = _hero;
}

void Labyrinth::SetExit(unsigned int _exit)
{
	exit = _exit;
}
