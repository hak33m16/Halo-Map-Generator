#include "maze/Cell.hpp"

Cell::Cell() : visited(false) {

}

std::shared_ptr<Wall> Cell::getWall(Direction dir) {
	return walls[DirectionHelper::getInstance().DIRECTIONS[dir]];
}

void Cell::setWall(Direction dir, std::shared_ptr<Wall> newWall) {
	walls[static_cast<int>(dir)] = newWall;
}

bool Cell::getVisited() { 
	return visited; 
}

void Cell::setVisited(bool newVisited) {
	visited = newVisited; 
}
