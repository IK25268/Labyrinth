#pragma once
#ifndef __WaveAlg_hpp
#define __WaveAlg_hpp
#include <queue>
#include <array>
#include "Labyrinth.hpp"

class WaveAlg final {

private:
	std::queue<unsigned int> waveCells;
	std::array<const int, 8> iterX = { -1, 0, 0, 1, -1, -1, 1, 1 };
	std::array<const int, 8> iterY = { 0, -1, 1, 0, -1, 1, -1, 1 };
	void CalcWave(Labyrinth& labyrinth);
	void CalcCell(Labyrinth& labyrinth);
	void DrawRoute(Labyrinth& labyrinth);
	int CalcPos(Labyrinth& labyrinth, unsigned int x, unsigned int y);
public:
	Labyrinth CalcLabyrinth(Labyrinth labyrinth);
};

#endif