#include "Graph.h"
#include "menu.h"
#include "dataParser.h"
#include "inputHandler.h"
#include "algorithms.h"
#include <iostream>
#include <fstream>

int main() {

	Graph * graph = new Graph();
	RoutePlan routePlan;


	while (true) {
		fileToGraph(graph, "map_data/Locations.csv",
						"map_data/Distances.csv");
		showMenu();
		int choice = getMainMenuInput();

		if (choice == 1) {
			routePlan = fileRoutePlan();
			std::ofstream outFile("input_output/output.txt");
			resultMaker(graph, routePlan, outFile);
			outFile.close();
			break;
		}

		if (choice == 2) {
			routePlan = showRoutePlanningMenu();
			resultMaker(graph, routePlan, std::cout);
		}

		if (choice == 3) {
			break;
		}
	}

	delete graph;

	return 0;
}
