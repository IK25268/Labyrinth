#pragma once
#ifndef __RWFile_hpp
#define __RWFile_hpp
#include <string>
#include "Labyrinth.hpp"
class RWFile final
{
public:
	static void WriteFile(Labyrinth labyrinth, const char* outputName);
	static Labyrinth ReadFile(const char* inputName);
};

#endif
