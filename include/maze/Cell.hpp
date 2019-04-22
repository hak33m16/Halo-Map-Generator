#ifndef CELL_HPP_
#define CELL_HPP_

#include <memory>
#include <array>

#include "Wall.hpp"
#include "DirectionHelper.hpp"

class Cell {
public:
	Cell();

	std::shared_ptr<Wall> getWall(Direction dir);
	void setWall(Direction dir, std::shared_ptr<Wall> newWall);

	bool getVisited();
	void setVisited(bool newVisited);

private:
	bool visited;

	std::array<std::shared_ptr<Wall>, 4> walls;

};

#endif