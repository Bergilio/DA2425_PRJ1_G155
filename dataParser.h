#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <string>
#include <vector>
#include "Graph.h"

struct Location{
	std::string location;
	int id;
	std::string code;
	bool parking;
};

struct Distance{
	std::string location1;
	std::string location2;
	int driving;
	int walking;
};

std::vector<Location> parseLocations(const std::string& filename);
std::vector<Distance> parseDistances(const std::string& filename);
void fileToGraph(Graph * graph, const std::string& locationFilename, const std::string& distanceFilename);

#endif
