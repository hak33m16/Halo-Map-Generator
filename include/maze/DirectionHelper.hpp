#ifndef DIRECTION_HELPER_HPP_
#define DIRECTION_HELPER_HPP_

#include <unordered_map>
#include <string>

enum class Direction {
	North,
	East,
	South,
	West
};

class DirectionHelper {
public:
	static DirectionHelper& getInstance() {
		static DirectionHelper instance;
		return instance;
	}

//private:
	
	std::unordered_map<Direction, int> DIRECTIONS = {
		{ Direction::North, 0 },
		{ Direction::East, 1 },
		{ Direction::South, 2 },
		{ Direction::West, 3 }
	};

	std::unordered_map<Direction, std::string> DIRECTIONSTRINGS = {
		{ Direction::North, "North" },
		{ Direction::East, "East" },
		{ Direction::South, "South" },
		{ Direction::West, "West" }
	};

	std::unordered_map<Direction, std::pair<int, int>> VELOCITIES = {
		{ Direction::North, std::make_pair(0, -1) },
		{ Direction::East, std::make_pair(1, 0) },
		{ Direction::South, std::make_pair(0, 1) },
		{ Direction::West, std::make_pair(-1, 0) }
	};

};

#endif