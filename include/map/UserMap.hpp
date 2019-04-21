#ifndef USER_MAP_HPP_
#define USER_MAP_HPP_

#include <fstream>

#include "map/SandboxContentHeader.hpp"
#include "map/SandboxMap.hpp"
#include "map/SandboxPlacement.hpp"
#include "map/BudgetEntry.hpp"

class UserMap {
public:
	UserMap();

	SandboxContentHeader sandboxContentHeader;
	SandboxMap sandboxMap;

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