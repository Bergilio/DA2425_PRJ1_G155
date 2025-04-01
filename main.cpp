/**
* @mainpage Route Planning Tool - DA2425_PRJ1_G155
 *
 * @section intro Introduction
 * This project was developed to help create a rote, according to user requirements.
 * In the file section is possible to find documentation to the functions, structs and classes
 * that are found in the files, as well as time complexity for the most relevant algorithms
 *
 * @section features Features
 * - Create driving only routes
 * - Create driving and walking routes
 * - Create routes with restrictions, like avoiding streets, locations, or including a specific location in your route
 *
 * @section usage Usage
 * The user should choose what input format it wants to use, either an input file or the terminal menu.
 * Choosing the input file format, an input.txt file should be found in the input_output directory with the appropriate input.
 * Choosing the terminal menu format, the user shall fill the fields that he is required to fill, writing 'none' if there is no interest in filling the field
 */

/**
 * @file main.cpp
 * @brief Main entry point for the Route Planning Analysis Tool.
 *
 * This program initializes the graph, handles user input, and invokes route planning
 * either from a file or from terminal input.
 */
#include "Graph.h"
#include "menu.h"
#include "dataParser.h"
#include "inputHandler.h"
#include "algorithms.h"
#include <iostream>
#include <fstream>

/**
 * @brief Main function to execute the route planning program.
 *
 * The program loads the graph from the given CSV files, displays the main menu, and allows the user
 * to choose between route planning from a file or from the terminal. The result is saved to an output file or
 * printed to the console.
 *
 * The input data is expected to be found inside the input_output directory, and it should be called input.txt.
 * The output.txt will contain the output, and it can e found in the same directory.
 *
 * The distances.csv and locations.csv should be inside smallSampleSize, and should have a valid representation of the
 * map that will be represented as graph.
 *
 * @return int Exit status code.
 */
int main() {

	Graph * graph = new Graph();
	RoutePlan routePlan;


	while (true) {
		fileToGraph(graph, "smallSampleSize/Locations.csv",
						"smallSampleSize/Distances.csv");
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
