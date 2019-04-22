#include "maze/MazeFunctions.hpp"

namespace MazeFunctions {

	void printMaze(Cell maze[20][20], int size) {
		for (int y = 0; y < size; ++ y) {

			std::vector<Cell> row;
			for (int x = 0; x < size; ++ x) {

				row.push_back(maze[x][y]);

			}

			for (auto cell : row) {
				std::string symbol = cell.getWall(Direction::North)->getActive() ? "---" : "|  ";
				std::cout << symbol;
			}

			std::cout << "|\n";

			for (auto cell : row) {
				char leftSymbol = cell.getWall(Direction::West)->getActive() ? '|' : ' ';
				char middleSymbol = cell.getVisited() ? ' ' : 'u';
				//char rightSymbol = cell.getWall(Direction::East)->getActive() ? '|' : ' ';

				std::cout << leftSymbol << middleSymbol << " ";// << rightSymbol;

			}

			std::cout << "|\n";

			if ( y == size - 1 ) {
				for (auto cell : row) {
					std::string symbol = cell.getWall(Direction::South)->getActive() ? "---" : "|  ";
					std::cout << symbol;
				}
				std::cout << "|\n";
			}
	
		}
	}

	bool inRange(int value, int rangeMin, int rangeMax) {
		return value >= rangeMin && value <= rangeMax;
	}

	void buildTheWall(Cell maze[20][20], int size) {
		for (int x = 0; x < size; ++x) {
			for (int y = 0; y < size; ++y) {

				// check for existing walls
				// N, E, S, W
				for (int dir = 0; dir < 4; ++dir) {

					Direction currentDir = static_cast<Direction>(dir);
					int dx = DirectionHelper::getInstance().VELOCITIES[currentDir].first;
					int dy = DirectionHelper::getInstance().VELOCITIES[currentDir].second;

					bool needNewWall = true;
					// this theoretical cell exists
					if (inRange(x + dx, 0, size - 1) && inRange(y + dy, 0, size - 1)) {

						// compute the value of adjacent wall in the other object
						// i.e. if 0/North to this wall, then adjacent wall would be 2/South,
						// so retrieve it
						Direction adjacentWall = static_cast<Direction>((dir + 2) % 4);

						// if the wall is not null (has been created)
						std::shared_ptr<Wall> spAdjWall = maze[x + dx][y + dy].getWall(adjacentWall);
						if (spAdjWall) {
							//std::cout << "Not recreating " << DIRECTIONSTRINGS[currentDir] << " wall for cell(" << x << ", " << y << ")\n";
							//std::cout << "Instead, using " << DIRECTIONSTRINGS[adjacentWall] << " wall from cell(" << x + dx << ", " << y + dy << ")\n";
							// replace our shared ptr with this same one
							maze[x][y].setWall(currentDir, spAdjWall);//.getWall(currentDir) = spAdjWall;
							needNewWall = false;
						}

					}

					// this theoretical cell doesn't exist, or the wall doesn't yet, so we must create the wall
					if (needNewWall) {
						// for some reason, we cant use make_shared on rhs???
						std::shared_ptr<Wall> newWall(new Wall);
						maze[x][y].setWall(currentDir, newWall);
						//std::cout << "Created " << DIRECTIONSTRINGS[currentDir] << " wall for cell (" << x << ", " << y << ")\n";
					}

				}

			}
		}
	}

	std::pair<int, int> findUnvisitedNeighbor(Cell maze[20][20], int size, std::pair<int, int> pos) {
		//std::cout << "finding unvisited neighbor\n";

		std::array<Direction, 4> directions = { Direction::North, Direction::East, Direction::South, Direction::West };
		std::shuffle(directions.begin(), directions.end(), mtEngine);

		for (auto &d : directions) {

			int newX = pos.first + DirectionHelper::getInstance().VELOCITIES[d].first;
			int newY = pos.second + DirectionHelper::getInstance().VELOCITIES[d].second;

			// Must verify that we don't perform an invalid access on the array
			if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
				// Verify that this position in the maze has not been visited
				if (!maze[newX][newY].getVisited()) {

					// Connect the two by removing their shared wall
					maze[pos.first][pos.second].getWall(d)->setActive(false);
					maze[newX][newY].setVisited(true);

					// Return the new position
					return std::make_pair(newX, newY);

				}
			}

		}

		// No valid neighbor
		return std::make_pair(-1, -1);
	}

	std::pair<int, int> findNewStartingPoint(Cell maze[20][20], int size) {
		//std::cout << "finding new starting point\n";
		for (int y = 0; y < size; ++y) {
			for (int x = 0; x < size; ++x) {

				// If the cell is unvisited
				if ( !maze[x][y].getVisited() ) {

					std::array<Direction, 4> directions = { Direction::North, Direction::East, Direction::South, Direction::West };
					std::shuffle(directions.begin(), directions.end(), mtEngine);

					//std::vector<Cell&> neighbors;
					for (auto &d : directions) {

						int potentialX = x + DirectionHelper::getInstance().VELOCITIES[d].first;
						int potentialY = y + DirectionHelper::getInstance().VELOCITIES[d].second;

						if (potentialX >= 0 && potentialX < size && potentialY >= 0 && potentialY < size) {
							if (maze[potentialX][potentialY].getVisited()) {
								// Connect the first cell to this one by removing shared wall
								maze[x][y].getWall(d)->setActive(false);
								//std::cout << "set wall " << DIRECTIONSTRINGS[d] << " of cell(" << x << ", " << y << ") to inactive\n";
								maze[x][y].setVisited(true);

								return std::make_pair(x, y);
							}
						}

					}

				}

			}
		}

		// If we've made it here, then no move was valid
		// Negative values indicate this
		return std::make_pair(-1, -1);
	}

	void init(Cell maze[20][20], int size) {

		std::pair<int, int> currentPos = std::make_pair(mazeDist(mtEngine), mazeDist(mtEngine));
		maze[currentPos.first][currentPos.second].setVisited(true);
		while (currentPos.first != -1 && currentPos.second != -1) {
			currentPos = findUnvisitedNeighbor(maze, size, currentPos);
		}

		currentPos = findNewStartingPoint(maze, size);

		bool mazeFilled = false;
		while (!mazeFilled) {

			while (currentPos.first != -1 && currentPos.second != -1) {
				currentPos = findUnvisitedNeighbor(maze, size, currentPos);
			}

			currentPos = findNewStartingPoint(maze, size);

			if (currentPos.first == -1 || currentPos.second == -1)
				mazeFilled = true;

			//printMaze(maze, size);

		}

	}

	void reseed(int seed, Cell maze[20][20], int size) {

		mtEngine = std::mt19937(seed);

		// Reset to default state
		for (int x = 0; x < size; ++x) {
			for (int y = 0; y < size; ++y) {

				maze[x][y].setVisited(false);
				for (int d = 0; d < 4; ++d) {
					Direction dir = static_cast<Direction>(d);
					maze[x][y].getWall(dir)->setActive(true);
				}

			}
		}

		init(maze, size);

	}

}