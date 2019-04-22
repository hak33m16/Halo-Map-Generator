#include "maze/Wall.hpp"

Wall::Wall() : active(true) {

}

bool Wall::getActive() {
	return active;
}

void Wall::setActive(bool newActive) {
	active = newActive;
}