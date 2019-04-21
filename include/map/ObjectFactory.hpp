#ifndef OBJECT_FACTORY_HPP_
#define OBJECT_FACTORY_HPP_

#include "map/UserMap.hpp"

enum class Block {
	block_1x20x20 = 295,
	block_0p1x20x20 = 349,
	block_0p1x1x1 = 328
};

class ObjectFactory {
public:
	ObjectFactory();

	// There is probably a better way to define all of these
	// getters, based off of the "objectType" entry we find
	// in each placement. Look for a resource on this.

	// Add in 3D direction enums for up/right vector
	static SandboxPlacement getBlock(Block type, sf::Int32 budgetIndex, sf::Vector3f position, sf::Vector3f upVector, sf::Vector3f rightVector, sf::Uint16 material = 1023);
	SandboxPlacement getPowerup();
	SandboxPlacement getWeapon();
	SandboxPlacement getZone();

private:

};

#endif