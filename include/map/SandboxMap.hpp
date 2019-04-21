#ifndef SANDBOX_MAP_HPP_
#define SANDBOX_MAP_HPP_

#include <vector>

#include "SFML/System.hpp"
#include "map/SandboxPlacement.hpp"
#include "map/BudgetEntry.hpp"

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

#endif