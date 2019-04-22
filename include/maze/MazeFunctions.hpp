#ifndef MAZE_FUNCTIONS_HPP_
#define MAZE_FUNCTIONS_HPP_

#include <iostream>
#include <random>

#include "Cell.hpp"
#include "DirectionHelper.hpp"

namespace MazeFunctions {

	static std::mt19937 mtEngine(1339);
	static std::uniform_int_distribution<int> mazeDist(0, 19);
	static std::uniform_int_distribution<int> choiceDist(0, 3);

	// Made from pseudo-algorithm described here:
	// http://people.cs.ksu.edu/~ashley78/wiki.ashleycoleman.me/index.php/Hunt_and_Kill_Algorithm.html

	void printMaze(Cell maze[20][20], int size);
	bool inRange(int value, int rangeMin, int rangeMax);
	void buildTheWall(Cell maze[20][20], int size);
	std::pair<int, int> findUnvisitedNeighbor(Cell maze[20][20], int size, std::pair<int, int> pos);
	std::pair<int, int> findNewStartingPoint(Cell maze[20][20], int size);
	void init(Cell maze[20][20], int size);
	void reseed(int seed, Cell maze[20][20], int size);

}

#endif