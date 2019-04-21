#ifndef BUDGET_ENTRY_HPP_
#define BUDGET_ENTRY_HPP_

#include <SFML/System.hpp>
#include <iostream>

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

#endif