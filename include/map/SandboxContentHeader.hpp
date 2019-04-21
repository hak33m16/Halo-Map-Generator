#ifndef SANDBOX_CONTENT_HEADER_HPP_
#define SANDBOX_CONTENT_HEADER_HPP_

#include <string>
#include <SFML/System.hpp>

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

#endif