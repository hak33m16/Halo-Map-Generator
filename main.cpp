#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/Engine.hpp>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>

#include "tinyxml2.h"
#include "MapObjects.hpp"
#include "ObjectInformation.hpp"

using namespace tinyxml2;

void dump_to_stdout(const char*);

int main() {

	sf::Window sfml_window(sf::VideoMode(800, 600), "SFGUI with OpenGL example", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;

	float refresh_rate = 1 / 60; // 1/60th of a second

	sfg::SFGUI sfgui;

	auto table = sfg::Table::Create();
	table->SetRowSpacings(5.f);
	table->SetColumnSpacings(5.f);

	/*
	I need to understand how to resize the widget window here, and how to lock its position.
	*/

	auto window = sfg::Window::Create();
	window->SetTitle("SFGUI with OpenGL");
	window->Add( table );

	sfg::Desktop desktop;
	desktop.Add( window );

	sfml_window.setActive();

	auto red_scale = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	auto green_scale = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	auto blue_scale = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	auto angle_scale = sfg::Scale::Create(0.f, 360.f, 1.f, sfg::Scale::Orientation::HORIZONTAL);
	auto auto_check = sfg::CheckButton::Create("Auto");

	table->Attach(green_scale, sf::Rect<sf::Uint32>(1, 2, 1, 1), sfg::Table::FILL | sfg::Table::EXPAND, sfg::Table::FILL | sfg::Table::EXPAND);
	table->Attach(auto_check, sf::Rect<sf::Uint32>(2, 4, 1, 1), sfg::Table::FILL, sfg::Table::FILL);
	
	sf::Clock clock;
	float accumulator = 0.f;
	while ( sfml_window.isOpen() ) {
		accumulator += clock.restart().asSeconds();

		while ( sfml_window.pollEvent( event ) ) {
			if ( event.type == sf::Event::Closed ) {
				return 0;
			} else {
				desktop.HandleEvent( event );
			}
		}

		if ( accumulator >= refresh_rate ) {

			accumulator = 0;

			desktop.Update( refresh_rate );
			sfgui.Display( sfml_window );
			sfml_window.display();

		}

	}

	///////////////////////////////////////////////////
	/*

	//dump_to_stdout("C:/Users/Hakeem/Documents/Repositories/Halo-Map-Generator/items.xml");

	//std::string mapPath = "C:/Users/Hakeem/Downloads/maps/Beaver Creek/sandbox.map";
	//std::string mapPath = "C:/Users/Hakeem/Desktop/Maps/Edge_Empty_1Blk/sandbox.map";

	std::string mapPath = "D:/Misc/Halo Online 1.106708 cert_ms23/Halo Online/mods/maps/Beaver Creek/sandbox.map";
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
					  << "Type 'p' to view a placement, 'b' for a budget, 'q' to quit, 's' to save map: ";
			std::cin >> input;

		} else if ( input == "b" ) {
			
			std::cout << "Enter the budget index to go to (0 - 255): ";
			std::cin >> input;

			std::cout << "ITEM: " << _ITEMMAP[map.sandboxMap.budget[std::stoi(input)].tagIndex] << "\n";
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

				if ( budgetIndex >= 0 ) {
					std::cout << "ITEM: " << _ITEMMAP[map.sandboxMap.budget[budgetIndex].tagIndex] << "\n";
					map.sandboxMap.budget[budgetIndex].print();
					std::cout << "\n";
					input = "-";
				} else {
					std::cout << "Invalid budget.\n";
					input = "-";
				}

			} else {

				input = "-";

			}

		} else if ( input == "q" ) {

			done = true;

		} else if ( input == "s" ) {
			
			std::ofstream mapOutStream(mapPath, std::ios::binary | std::ios::out | std::ios::in);
			map.SerializeSandboxMap(mapOutStream, map.sandboxMap);
			mapOutStream.close();

			std::cout << "Map saved.\n";

		}

		std::cout << "\n ## ------------------------------------ ## \n\n";

	}

	*/
	///////////////////////////////////////////////

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

}

void dump_to_stdout(const char* pFilename)
{
	tinyxml2::XMLDocument doc(pFilename);
	bool failed = doc.LoadFile(pFilename);

	std::cout << pFilename << "\n";
	std::cout << "Failed: " << failed << "\n";

	if (!failed)
	{
		std::stack<tinyxml2::XMLNode*> nodeStack;

		auto currentNode = doc.FirstChild();
		nodeStack.push(currentNode);

		std::cout << "std::map<sf::Uint32, std::string> _ITEMMAP = \n    {";
		while (!nodeStack.empty()) {

			currentNode = nodeStack.top();
			nodeStack.pop();

			while (currentNode != nullptr) {

				if (std::string(currentNode->Value()) == "item") {
					std::cout << "        { " << std::stoul(currentNode->ToElement()->Attribute("tagindex"), nullptr, 16)
						<< ", \"" << currentNode->ToElement()->Attribute("name") << "\"},\n";
				}

				if (currentNode->FirstChild() != nullptr) {
					nodeStack.push(currentNode->FirstChild());
				}

				currentNode = currentNode->NextSibling();
			}

		}
		std::cout << "};";

	}
}