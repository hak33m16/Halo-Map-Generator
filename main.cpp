#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

#include "tinyxml2.h"
#include "MapObjects.hpp"

using namespace tinyxml2;

void dump_to_stdout(const char* pFilename)
{
	tinyxml2::XMLDocument doc(pFilename);
	bool failed = doc.LoadFile(pFilename);

	std::cout << pFilename << "\n";
	std::cout << "Failed: " << failed << "\n";

	if ( !failed )
	{
		//const char* title = doc.FirstChildElement("root")->FirstChildElement()->Attribute("id");//FirstChildElement("category")->GetText();
		
		std::stack<std::pair<sf::Uint32, std::string>> itemStack;
		std::stack<tinyxml2::XMLNode*> nodeStack;

		auto currentNode = doc.FirstChild();//("root");
		nodeStack.push(currentNode);
		//std::cout << currentNode->Value() << " :: ";
		//nodeStack.push( currentNode->FirstChild() );
		while ( !nodeStack.empty() ) {

			currentNode = nodeStack.top();
			nodeStack.pop();

			while ( currentNode != nullptr ) {
				std::cout << currentNode->Value() << " :: ";

				if ( currentNode->FirstChild() != nullptr ) {
					nodeStack.push( currentNode->FirstChild() );
				}

				currentNode = currentNode->NextSibling();
			}

			/*
			std::cout << currentNode->Value() << " :: ";
			while ( currentNode->NextSibling() != nullptr ) {
				currentNode = currentNode->NextSibling();
				std::cout << currentNode->Value() << " :: ";

				if ( currentNode->FirstChild() != nullptr ) {
					nodeStack.push( currentNode->FirstChild() );
				}

			}

			currentNode = nodeStack.top();
			nodeStack.pop();*/

		}
		//printf("Name of root (1): %s\n", title);
	}
}

int main() {

	dump_to_stdout("C:/Users/Hakeem/Documents/Repositories/Halo-Map-Generator/items.xml");

	/*

	//std::string mapPath = "C:/Users/Hakeem/Downloads/maps/Beaver Creek/sandbox.map";
	std::string mapPath = "C:/Users/Hakeem/Desktop/Maps/Edge_Empty_1Blk/sandbox.map";
	std::ifstream mapStream(mapPath, std::ios::binary | std::ios::in);

	UserMap map;
	map.DeserializeContentHeader(mapStream);
	map.DeserializeSandboxMap(mapStream);

	mapStream.close();

	std::string input = "-";

	bool done = false;
	while ( !done ) {

		if ( input == "-" ) {

			std::cout << "## 640 placements, 240 budgets ##\n"
					  << "Type 'p' to view a placement, 'b' for a budget, 'q' to quit: ";
			std::cin >> input;

		} else if ( input == "b" ) {
			
			std::cout << "Enter the budget index to go to (0 - 255): ";
			std::cin >> input;

			map.sandboxMap.budget[std::stoi(input)].print();
			std::cout << "\n";
			input = "-";

		} else if ( input == "p" ) {

			std::cout << "Enter the placement index to go to (0 - 639): ";
			std::cin >> input;

			map.sandboxMap.placements[std::stoi(input)].print();
			std::cout << "\n";
			sf::Int32 budgetIndex = map.sandboxMap.placements[std::stoi(input)].budgetIndex;

			std::cout << "Print this objects corresponding budget? (y/n): ";
			std::cin >> input;

			if ( input == "y" ) {
				map.sandboxMap.budget[budgetIndex].print();
				std::cout << "\n";
				input = "-";
			} else {
				input = "-";
			}

		} else if ( input == "q" ) {
			done = true;
		}

	}

	// Should be moving the object by 2 (decent width for players)
	//for ( auto &e : map.sandboxMap.placements ) {
		// We found the textured 0.1' x 10' x 5' wall
	//	if ( e.budgetIndex == 4 && e.engineFlags != 0 ) {
	//		e.position.y -= 1;
	//		break;
	//	}
	//}

	//std::ofstream mapOutStream(mapPath, std::ios::binary | std::ios::out | std::ios::in);

	//map.SerializeSandboxMap(mapOutStream, map.sandboxMap);

	//mapOutStream.close();

	/*
	mapStream = std::ifstream(mapPath, std::ios::binary | std::ios::in);
	std::cout << "#########################################\n";

	//UserMap map;
	map.DeserializeContentHeader(mapStream);
	map.DeserializeSandboxMap(mapStream);

	mapStream.close();*/

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