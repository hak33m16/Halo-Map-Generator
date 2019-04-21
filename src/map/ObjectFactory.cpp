#include "map/ObjectFactory.hpp"

ObjectFactory::ObjectFactory() {

}

SandboxPlacement ObjectFactory::getBlock(Block block, sf::Int32 budgetIndex, sf::Vector3f position, sf::Vector3f upVector, sf::Vector3f rightVector, sf::Uint16 material) {

	SandboxPlacement placement;
	placement.budgetIndex = budgetIndex;
	placement.engineFlags = material;
	placement.extra = 0;
	placement.flags = 12;
	placement.gizmoDatumHandle = 4294967295;
	placement.objectDatumHandle = 4294967295;
	placement.objectType = 0;
	placement.placementFlags = 3;
	placement.position = position;
	placement.upVector = upVector;
	placement.rightVector = rightVector;
	placement.respawnTime = 30;
	placement.team = 8;
	placement.unknown_1 = 0;
	placement.unknown_2 = 4294967295;
	placement.unknown_3 = 4294967295;
	placement.zoneBottom = 0.0f;
	placement.zoneDepth = 0.0f;
	placement.zoneRadiusWidth = 0.0f;
	placement.zoneShape = 0;
	placement.zoneTop = 0.0f;

	return placement;

}
