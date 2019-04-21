#ifndef SANDBOX_PLACEMENT_HPP_
#define SANDBOX_PLACEMENT_HPP_

#include <SFML/System.hpp>
#include <iostream>

class SandboxPlacement {
public:
	SandboxPlacement();

	sf::Uint16 placementFlags;
	sf::Uint16 unknown_1;
	sf::Uint32 objectDatumHandle;
	sf::Uint32 gizmoDatumHandle;
	sf::Int32 budgetIndex;

	sf::Vector3f position;
	sf::Vector3f rightVector;
	sf::Vector3f upVector;

	sf::Uint32 unknown_2;
	sf::Uint32 unknown_3;

	sf::Uint16 engineFlags;

	/* Signed or unsigned bytes? Is that a thing? */

	// Unknown?
	sf::Uint8 flags;
	sf::Uint8 team;
	// This is the material from: materials.xml
	sf::Uint8 extra;
	sf::Uint8 respawnTime;
	sf::Uint8 objectType;
	sf::Uint8 zoneShape;

	float zoneRadiusWidth;
	float zoneDepth;
	float zoneTop;
	float zoneBottom;

	/* Add a clone function?? */
	void print();

};

#endif