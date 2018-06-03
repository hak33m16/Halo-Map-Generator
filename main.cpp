#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <iomanip>

#include "MapObjects.hpp"

int main() {

	//std::string mapPath = "C:/Users/Hakeem/Downloads/maps/Beaver Creek/sandbox.map";
	std::string mapPath = "C:/Users/Hakeem/Desktop/Maps/BaseOrient2Item/sandbox.map";
	std::ifstream mapStream(mapPath, std::ios::in | std::ios::binary);

	UserMap map;
	map.DeserializeContentHeader(mapStream);
	map.DeserializeSandboxMap(mapStream);

	//std::cout << "\n" << typeid(map.sandboxContentHeader.description).name();
	//std::cout << "\n" << typeid(mapPath).name();

	//std::cout << mapPath[0];
	//std::cout << map.sandboxContentHeader.description;

	//for ( int i = 0; i < 10; ++ i) {
	//	std::cout << map.sandboxContentHeader.description[0];
	//}

	//std::cout << map.sandboxContentHeader.description;

	/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/

	/*
	std::string filePath1 = "C:/Users/Hakeem/Desktop/Maps/BaseOrient1Item/sandbox.map";
	std::string filePath2 = "C:/Users/Hakeem/Desktop/Maps/BaseOrient2Item/sandbox.map";

	unsigned char buffer[10000];
	std::ifstream myFile(filePath1, std::ios::in | std::ios::binary);
	myFile.read((char*)buffer, 10000);
	if (!myFile) {
		// An error occurred!
		// myFile.gcount() returns the number of bytes read.
		// calling myFile.clear() will reset the stream state
		// so it is usable again.
	}

	int count = 0;
	std::string sixteenBytes = "";
	for (auto &e : buffer) {

		std::cout << std::setfill('0') << std::setw(2) << std::hex << static_cast<unsigned int>(e) << " ";
		++count;

		sixteenBytes += isprint(e) ? e : '.';

		if (count % 16 == 0) {
			std::cout << sixteenBytes << "\n";
			sixteenBytes = "";
		}

	}

	return 0;*/



}