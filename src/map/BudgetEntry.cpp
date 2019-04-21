#include "map/BudgetEntry.hpp"

BudgetEntry::BudgetEntry() {

	tagIndex = 4294967295;

}

void BudgetEntry::print() {

	std::cout << "Tag Index: " << tagIndex << "\n";
	std::cout << "Count on Map: " << (int)countOnMap << "\n";
	std::cout << "Cost: " << cost << "\n";
	std::cout << "Runtime Min: " << (int)runtimeMin << "\n";
	std::cout << "Runtime Max: " << (int)runtimeMax << "\n";
	std::cout << "Design Time Max: " << (int)designTimeMax << "\n";

}