#include "dataParser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>


std::vector<Location> parseLocations(const std::string& filename) {
	std::vector<Location> locations;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file: " << filename << std::endl;
		return locations;
	}


	std::string line;
	bool firstLine = true;

	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}

		std::stringstream ss(line);
		std::string token;
		Location location;

		// Parse the Name
		std::getline(ss, location.location, ',');

		// Parse the ID
		std::getline(ss, token, ',');
		location.id = std::stoi(token);

		// Parse the code
		std::getline(ss, location.code, ',');

        // Parse the parking
		std::getline(ss, token, ',');
		location.parking = (token[0] == '1');

		locations.push_back(location);
	}

	file.close();
	return locations;
}


std::vector<Distance> parseDistances(const std::string& filename) {
	std::vector<Distance> distances;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file: " << filename << std::endl;
		return distances;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}

		std::stringstream ss(line);
		std::string token;
		Distance distance;

		// Parse the location1
		std::getline(ss, distance.location1, ',');

		// Parse the location2
		std::getline(ss, distance.location2, ',');

		// Parse driving
		std::getline(ss, token, ',');
		if (token == "X") {
			distance.driving = INT_MAX;
		}else {
			distance.driving = std::stoi(token);
		}

		// Parse walking
		std::getline(ss, token, ',');
		distance.walking = std::stoi(token);

		distances.push_back(distance);
	}

	file.close();
	return distances;
}


void fileToGraph(Graph * graph, const std::string& locationFilename, const std::string& distanceFilename) {
	std::vector<Location> locations = parseLocations(locationFilename);
	std::vector<Distance> distances = parseDistances(distanceFilename);


	for (auto& l : locations) {
		graph->addVertex(l.location, l.id, l.code, l.parking);
	}

	for (auto& d : distances) {
		graph->addBidirectionalEdge(d.location1, d.location2, d.driving, d.walking);
	}

}
