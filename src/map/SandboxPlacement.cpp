#include "map/SandboxPlacement.hpp"

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
	std::cout << "Position: (" << std::fixed << (float)position.x << ", " << (float)position.y << ", " << (float)position.z << ")\n";
	std::cout << "Up Vector: (" << upVector.x << ", " << upVector.y << ", " << upVector.z << ")\n";
	std::cout << "Right Vector: (" << rightVector.x << ", " << rightVector.y << ", " << rightVector.z << ")\n";
	std::cout << "Respawn Time: " << (int)respawnTime << "\n";
	std::cout << "Team: " << (int)team << "\n";
	std::cout << "Unknown 1: " << unknown_1 << "\n";
	std::cout << "Unknown 2: " << unknown_2 << "\n";
	std::cout << "Unknown 3: " << unknown_3 << "\n";
	std::cout << "Zone Bottom: " << zoneBottom << "\n";
	std::cout << "Zone Depth: " << zoneDepth << "\n";
	std::cout << "Zone Radius Width: " << zoneRadiusWidth << "\n";
	std::cout << "Zone Shape: " << (int)zoneShape << "\n";
	std::cout << "Zone Top: " << zoneTop << "\n";

}