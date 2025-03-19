#include <string>
#include "GraphMap.h"
#include "menu.h"
#include "dataParser.h"
#include "routePlan.h"

int main() {
	RoutePlan routePlan;
	Graph * graph = new Graph();


	while (true) {
		showMenu();
		int choice = getMainMenuInput();

		if (choice == 1) {
			fileToGraph(graph, "map_data/Locations.csv",
			            "map_data/Distances.csv");
		}

		if (choice == 3) {
			routePlan = showRoutePlanningMenu();
			break;
		}

		if (choice == 4) {
			break;
		}
	}



	return 0;
}