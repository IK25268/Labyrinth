#include <iostream>
#include "WaveAlg.hpp"
#include "Labyrinth.hpp"
#include "RWFile.hpp"

int main()
{
	Labyrinth labyrinth(RWFile::ReadFile("input.txt"));
	WaveAlg waveAlg;
	labyrinth = waveAlg.CalcLabyrinth(labyrinth);
	RWFile::WriteFile(labyrinth, "output.txt");
	return 0;
}