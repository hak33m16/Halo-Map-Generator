#include "MapObjects.hpp"

#include <fstream>

BudgetEntry::BudgetEntry() {

}

SandboxPlacement::SandboxPlacement() {

}

void SandboxPlacement::print() {

	std::cout << "Budget Index: " << budgetIndex << "\n";
	std::cout << "Engine Flags: " << engineFlags << "\n";
	std::cout << "Extra: " << (int)extra << "\n";
	std::cout << "Flags: " << (int)flags << "\n";
	std::cout << "Gizmo Datum Handle: " << gizmoDatumHandle << "\n";
	std::cout << "Object Datum Handle: " << objectDatumHandle << "\n";
	std::cout << "Object Type: " << (int)objectType << "\n";
	std::cout << "Placement Flags: " << placementFlags << "\n";
	std::cout << "Position: (" << position.x << ", " << position.y << ", " << position.z << ")\n";
	std::cout << "Respawn Time: " << (int)respawnTime << "\n";
	std::cout << "Right Vector: (" << rightVector.x << ", " << rightVector.y << ", " << rightVector.z << ")\n";
	std::cout << "Team: " << (int)team << "\n";
	std::cout << "Unknown 1: " << unknown_1 << "\n";
	std::cout << "Unknown 2: " << unknown_2 << "\n";
	std::cout << "Unknown 3: " << unknown_3 << "\n";
	std::cout << "Up Vector: (" << upVector.x << ", " << upVector.y << ", " << upVector.z << ")\n";
	std::cout << "Zone Bottom: " << zoneBottom << "\n";
	std::cout << "Zone Depth: " << zoneDepth << "\n";
	std::cout << "Zone Radius Width: " << zoneRadiusWidth << "\n";
	std::cout << "Zone Shape: " << (int)zoneShape << "\n";
	std::cout << "Zone Top: " << zoneTop << "\n";

}

SandboxContentHeader::SandboxContentHeader() {

}

SandboxMap::SandboxMap() {

}

////////////////////////////////
//
// Helper functions.
//
//////////

std::string UserMap::interpretString(std::ifstream &fStream, int length) {

	std::string streamString;

	for (int i = 0; i < length; ++ i) {
		char streamChar;
		fStream.read(&streamChar, 1);
		streamString += streamChar;
	}
	//streamString += '\0';

	return streamString;

}

/////////////////////////////////////////////
//
// UserMap class implementations.
//
//////////

UserMap::UserMap() {

}

// Begin deserialize helpers.

void UserMap::DeserializeContentHeader(std::ifstream &mapStream) {

	mapStream.seekg(0x138);

	std::string fileType = interpretString(mapStream, 4);

	if ( fileType != std::string("mapv") ) {
		std::cout << "Error: Unexpected file type.";
		exit(1);
	}

	mapStream.seekg(0x48);

	sandboxContentHeader.name = interpretString(mapStream, 32);
	sandboxContentHeader.description = interpretString(mapStream, 128);
	sandboxContentHeader.author = interpretString(mapStream, 16);

	mapStream.seekg(0x108);

	mapStream.read( (char*)&sandboxContentHeader.size, 8 );
	mapStream.read( (char*)&sandboxContentHeader.timestamp, 8 );

	mapStream.seekg(0x120);

	mapStream.read( (char*)&sandboxContentHeader.mapID, 4 );

}

void UserMap::DeserializeSandboxMap(std::ifstream &mapStream) {

	mapStream.seekg(0x288);
	
	mapStream.read( (char*)&sandboxMap.mapID, 4);

	mapStream.seekg(0x242);

	mapStream.read( (char*)&sandboxMap.sceneryObjectCount, 2 );
	mapStream.read( (char*)&sandboxMap.totalObjectCount, 2 );
	mapStream.read( (char*)&sandboxMap.budgetEntryCount, 2 );

	mapStream.seekg(0x278);
	for (int i = 0; i < 640; ++ i) {
		SandboxPlacement placement;
		DeserializePlacement(mapStream, placement);
		sandboxMap.placements.push_back( placement );
		
		//if (placement.objectType != 12 && placement.budgetIndex > -1) {
		//	placement.print();
		//	std::cout << "\n";
		//}
	}

	mapStream.seekg(0xD498);
	for (int i = 0; i < 256; ++ i) {
		BudgetEntry entry;
		DeserializeBudgetEntry(mapStream, entry);
		sandboxMap.budget.push_back( entry );

		std::cout << "Tag Index: " << entry.tagIndex << "\n";
		std::cout << "Count on Map: " << (int)entry.countOnMap << "\n";
		std::cout << "Cost: " << entry.cost << "\n";
		std::cout << "\n";
	}

}

sf::Vector3f UserMap::DeserializeVector3f(std::ifstream &mapStream) {

	sf::Vector3f position;

	mapStream.read( (char*)&position.x, 4 );
	mapStream.read( (char*)&position.y, 4 );
	mapStream.read( (char*)&position.z, 4 );

	return position;

}

void UserMap::DeserializeBudgetEntry(std::ifstream &mapStream, BudgetEntry &entry) {

	mapStream.read( (char*)&entry.tagIndex, 4 );
	mapStream.read( (char*)&entry.runtimeMin, 1 );
	mapStream.read( (char*)&entry.runtimeMax, 1 );
	mapStream.read( (char*)&entry.countOnMap, 1 );
	mapStream.read( (char*)&entry.designTimeMax, 1 );
	mapStream.read( (char*)&entry.cost, 4 );

}

void UserMap::DeserializePlacement(std::ifstream &mapStream, SandboxPlacement &placement) {

	mapStream.read( (char*)&placement.placementFlags, 2);
	mapStream.read( (char*)&placement.unknown_1, 2 );
	mapStream.read( (char*)&placement.objectDatumHandle, 4 );
	mapStream.read( (char*)&placement.gizmoDatumHandle, 4 );
	mapStream.read( (char*)&placement.budgetIndex, 4 );

	placement.position = DeserializeVector3f(mapStream);
	placement.rightVector = DeserializeVector3f(mapStream);
	placement.upVector = DeserializeVector3f(mapStream);
	
	mapStream.read( (char*)&placement.unknown_2, 4 );
	mapStream.read( (char*)&placement.unknown_3, 4 );
	mapStream.read( (char*)&placement.engineFlags, 2 );
	mapStream.read( (char*)&placement.flags, 1 );
	mapStream.read( (char*)&placement.team, 1 );
	mapStream.read( (char*)&placement.extra, 1);
	mapStream.read( (char*)&placement.respawnTime, 1 );
	mapStream.read( (char*)&placement.objectType, 1 );
	mapStream.read( (char*)&placement.zoneShape, 1 );
	mapStream.read( (char*)&placement.zoneRadiusWidth, 4);
	mapStream.read( (char*)&placement.zoneDepth, 4 );
	mapStream.read( (char*)&placement.zoneTop, 4 );
	mapStream.read( (char*)&placement.zoneBottom, 4);

}

// Begin serialize helpers.

void UserMap::SerializeContentHeader(std::ofstream &mapStream, SandboxContentHeader contentHeader) {

}

void UserMap::SerializeSandboxMap(std::ofstream &mapStream, SandboxMap sandboxMap) {

}

void UserMap::SerializeVector3f(std::ofstream &mapStream, sf::Vector3f vector) {

}

void UserMap::SerializeBudgetEntry(std::ofstream &mapStream, BudgetEntry budgetEntry) {

}

void UserMap::SerializePlacement(std::ofstream &mapStream, SandboxPlacement placement) {

}