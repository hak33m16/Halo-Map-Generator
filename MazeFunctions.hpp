#ifndef MAZE_FUNCTIONS_HPP_
#define MAZE_FUNCTIONS_HPP_

/*******************************************************************************************
* Name:             Jay Seong                                                              *
* Description:      Randomly generates a perfect maze using depth-first search algorithm   *
* Date:             02/11/2010                                                             *
* Data Structures:  Double array of structs for cells, stack for back-tracking             *
* Others:           fstream is used to save maze into a file                               *
*                                                                                          *
* NOTE: Transcribed from a YouTube video https://www.youtube.com/watch?v=EvAzVhAii_o by    *
* Stephen Pendley to distribute for public use.  All credit for this version of the code   *
* and it's original goes to Jay Seong.                                                     *
*******************************************************************************************/

#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <stack>
#include <fstream>
#include "stdafx.h" //http://sourceforge.net/p/wpbdc/website/ci/master/tree/Judge/StdAfx.h

using namespace std;

/********************************
* USED FOR THE SIZE OF THE MAZE *
*   Must be an odd number for   *
*    maze traversal reasons     *
********************************/
#define SIZE 19

// CELL STRUCTURE
struct Cell
{
	bool visited;
	bool top_wall;
	bool bot_wall;
	bool left_wall;
	bool right_wall;
	char display;
};

namespace MazeFunctions {

	// FUNCTION DECLARATIONS
	void Initialize(Cell Level[][SIZE]);
	void ClearScreen();
	void Redraw(Cell Level[][SIZE]);
	void GenerateMaze(Cell Level[][SIZE], int &posX, int &posY, int &goalX, int &goalY);
	void SaveMaze(Cell Level[][SIZE]);

}

#endif