#pragma once
#ifndef __Labyrinth_hpp
#define __Labyrinth_hpp
#include <map>

class Labyrinth final {
private:
	std::map<unsigned int, std::pair<int, char>> cells = {};
	unsigned int cols = 0;
	unsigned int rows = 0;
	unsigned int hero = 0;
	unsigned int exit = 0;
public:
	//Labyrinth() : cols(0), rows(0), hero(0), exit(0) {};
	std::map<unsigned int, std::pair<int, char>>& ReturnCells();
	void SetCell(unsigned int pos, int level, char type);
	unsigned int GetCols();
	unsigned int GetRows();
	unsigned int GetHero();
	unsigned int GetExit();
	void SetCols(unsigned int _cols);
	void SetRows(unsigned int _rows);
	void SetHero(unsigned int _hero);
	void SetExit(unsigned int _exit);
};

#endif