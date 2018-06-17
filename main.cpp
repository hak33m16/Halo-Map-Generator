#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/Engine.hpp>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <cmath>

#include "tinyxml2.h"
#include "MapObjects.hpp"
#include "ObjectInformation.hpp"

using namespace tinyxml2;

void dump_to_stdout(const char*);

class TestObj {
public:
	TestObj() { }
	
	void setPlacement(SandboxPlacement *placement) {
		placement_ = placement;
	}

	void setBudget(BudgetEntry *budget) {
		budget_ = budget;
	}

	void setLabel(std::shared_ptr<sfg::Label> label) {
		label_ = label;
	}

	void operator()() {

		std::string text = "Position: (";// +placement_->position.x;
		text += std::to_string(placement_->position.x);
		text += ", ";
		text += std::to_string(placement_->position.y);
		text += ", ";
		text += std::to_string(placement_->position.z);
		text += ")\n";

		text += "Up Vector: (";// +placement_->position.x;
		text += std::to_string(placement_->upVector.x);
		text += ", ";
		text += std::to_string(placement_->upVector.y);
		text += ", ";
		text += std::to_string(placement_->upVector.z);
		text += ")\n";

		text += "Right Vector: (";// +placement_->position.x;
		text += std::to_string(placement_->rightVector.x);
		text += ", ";
		text += std::to_string(placement_->rightVector.y);
		text += ", ";
		text += std::to_string(placement_->rightVector.z);
		text += ")\n";

		text += "Count on Map: ";
		text += std::to_string(budget_->countOnMap);
		text += "\n";

		label_->SetText(text);
	}

private:
	SandboxPlacement *placement_;
	BudgetEntry *budget_;
	std::shared_ptr<sfg::Label> label_;

};

int main() {

	sf::RenderWindow renderWindow( sf::VideoMode(800, 600), "Halo Map Generator" );
	sfg::SFGUI sfgui;
	
	renderWindow.resetGLStates();
	renderWindow.setFramerateLimit(60);

	sfg::Desktop desktop;
	desktop.SetProperty("Button#create_window", "FontSize", 18.f);

	float refresh_rate = 1 / 60; // 1/60th of a second

	auto mainWindow = sfg::Window::Create( sfg::Window::Style::NO_STYLE | sfg::Window::Style::BACKGROUND | sfg::Window::Style::SHADOW | sfg::Window::Style::TITLEBAR );
	mainWindow->SetStyle(mainWindow->GetStyle() ^ sfg::Window::TITLEBAR);
	

	auto introLabel = sfg::Label::Create("Click on create window to create a window.");

	auto createWindowButton = sfg::Button::Create("Create window.");
	createWindowButton->SetId("create_Window");

	auto mainBox = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.f );
	mainBox->Pack( introLabel, false );
	mainBox->Pack( createWindowButton, false );

	auto scrolledWindowBox = sfg::Box::Create( sfg::Box::Orientation::VERTICAL );

	/* Adding map stuff to box. */

	//std::string mapPath = "C:/Users/Hakeem/Downloads/maps/Beaver Creek/sandbox.map";
	//std::string mapPath = "C:/Users/Hakeem/Desktop/Maps/Edge_Empty_1Blk/sandbox.map";

	std::string mapPath = "D:/Misc/Halo Online 1.106708 cert_ms23/Halo Online/mods/maps/Beaver Creek/sandbox.map";
	std::ifstream mapStream(mapPath, std::ios::binary | std::ios::in);

	UserMap map;
	map.DeserializeContentHeader(mapStream);
	map.DeserializeSandboxMap(mapStream);

	mapStream.close();

	auto label = sfg::Label::Create();
	label->SetText("Text Entry");

	auto entry_table = sfg::Table::Create();
	//auto n_table = sfg::Table::Create();
	for ( int i = 0; i < map.sandboxMap.placements.size() - 1; ++ i ) {
		if (map.sandboxMap.placements.at(i).budgetIndex != -1 ) {
			auto button = sfg::Button::Create(_ITEMMAP[map.sandboxMap.budget[ map.sandboxMap.placements.at(i).budgetIndex ].tagIndex]);
			
			TestObj *obj = new TestObj;
			obj->setLabel( label );
			obj->setPlacement( &map.sandboxMap.placements.at(i) );
			obj->setBudget( &map.sandboxMap.budget[ map.sandboxMap.placements.at(i).budgetIndex ] );
			button->GetSignal( sfg::Widget::OnLeftClick ).Connect( *obj );

			scrolledWindowBox->Pack(button);
		}
	}

	auto scrolledWindow = sfg::ScrolledWindow::Create();

	scrolledWindow->SetScrollbarPolicy( sfg::ScrolledWindow::HORIZONTAL_ALWAYS | sfg::ScrolledWindow::VERTICAL_AUTOMATIC );
	scrolledWindow->AddWithViewport( scrolledWindowBox );
	scrolledWindow->SetRequisition( sf::Vector2f( 500.f, 100.f ) );
	
	auto n_table = sfg::Table::Create();
	n_table->Attach( scrolledWindow, sf::Rect<sf::Uint32>(1, 1, 2, 2), sfg::Table::FILL | sfg::Table::EXPAND, sfg::Table::FILL | sfg::Table::EXPAND );


	n_table->Attach( label, sf::Rect<sf::Uint32>(2, 1, 0, 2) );

	/* ---- */

	mainWindow->Add( n_table );
	
	desktop.Add( mainWindow );

	/* ------ */

	auto table = sfg::Table::Create();
	table->SetRowSpacings(5.f);
	table->SetColumnSpacings(5.f);

	/*
	I need to understand how to resize the widget window here, and how to lock its position.
	*/

	auto red_scale = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	auto green_scale = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	auto blue_scale = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	auto angle_scale = sfg::Scale::Create(0.f, 360.f, 1.f, sfg::Scale::Orientation::HORIZONTAL);
	auto auto_check = sfg::CheckButton::Create("Auto");

	table->Attach(green_scale, sf::Rect<sf::Uint32>(1, 2, 1, 1), sfg::Table::FILL | sfg::Table::EXPAND, sfg::Table::FILL | sfg::Table::EXPAND);
	table->Attach(auto_check, sf::Rect<sf::Uint32>(2, 4, 1, 1), sfg::Table::FILL, sfg::Table::FILL);
	
	mainWindow->SetAllocation(sf::FloatRect(0.f, 0.f, renderWindow.getSize().x, renderWindow.getSize().y));
	

	sf::Event event;
	sf::Clock clock;
	float accumulator = 0.f;
	while ( renderWindow.isOpen() ) {
		accumulator += clock.restart().asSeconds();

		while ( renderWindow.pollEvent( event ) ) {
			if ( event.type == sf::Event::Closed ) {
				return 0;
			} else {
				desktop.HandleEvent( event );
			}
		}

		if ( accumulator >= refresh_rate ) {

			accumulator = 0;

			desktop.Update( refresh_rate );
			renderWindow.clear();
			sfgui.Display( renderWindow );
			renderWindow.display();

		}
		
	}

	///////////////////////////////////////////////////
	/*

	//dump_to_stdout("C:/Users/Hakeem/Documents/Repositories/Halo-Map-Generator/items.xml");

	std::string mapPath = "C:/Users/Hakeem/Downloads/maps/Beaver Creek/sandbox.map";
	//std::string mapPath = "C:/Users/Hakeem/Desktop/Maps/Edge_Empty_1Blk/sandbox.map";

	//std::string mapPath = "D:/Misc/Halo Online 1.106708 cert_ms23/Halo Online/mods/maps/Beaver Creek/sandbox.map";
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