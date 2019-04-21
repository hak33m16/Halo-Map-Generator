#ifndef MAP_OBJECTS_HPP
#define MAP_OBJECTS_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <map> 

//#include "ObjectInformation.hpp"

class BudgetEntry {
public:
	BudgetEntry();

	sf::Uint32 tagIndex;
	
	/* Are these bytes unsigned? */
	sf::Uint8 runtimeMin;
	sf::Uint8 runtimeMax;
	sf::Uint8 countOnMap;
	sf::Uint8 designTimeMax;

	float cost;

	void print();

};

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

class SandboxContentHeader {
public:
	SandboxContentHeader();

	std::string name;
	std::string description;
	std::string author;
	
	sf::Int64 size;
	sf::Int64 timestamp;
	sf::Int32 mapID;

};

class SandboxMap {
public:
	SandboxMap();

	sf::Int16 sceneryObjectCount;
	sf::Int16 totalObjectCount;
	sf::Int16 budgetEntryCount;
	sf::Int32 mapID;

	std::vector<SandboxPlacement> placements;
	std::vector<BudgetEntry> budget;

};

class UserMap {
public:
	UserMap();
	
	SandboxContentHeader sandboxContentHeader;
	SandboxMap sandboxMap;
	//SandboxPlacement sandboxPlacement;
	//BudgetEntry budgetEntry;

	// Deserialize helpers.
	void DeserializeContentHeader(std::ifstream&);
	void DeserializeSandboxMap(std::ifstream&);
	sf::Vector3f DeserializeVector3f(std::ifstream&);
	void DeserializeBudgetEntry(std::ifstream&, BudgetEntry&);
	void DeserializePlacement(std::ifstream&, SandboxPlacement&);

	// Serialize helpers.
	void SerializeBudgetEntry(std::ofstream&, BudgetEntry);
	void SerializeVector3f(std::ofstream&, sf::Vector3f);
	void SerializePlacement(std::ofstream&, SandboxPlacement&);
	void SerializeSandboxMap(std::ofstream&, SandboxMap&);
	void SerializeContentHeader(std::ofstream&, SandboxContentHeader);

	// General helpers.
	std::string interpretString(std::ifstream&, int);

};

#endif