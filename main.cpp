#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "data_structures/GraphMap.h"
#include "dataParser.cpp"

struct RoutePlan {
	std::string mode;
	int source;
	int destination;
	int maxWalkTime;
	std::vector<int> avoidNodes;
	std::vector<int> includeNodes;
	std::vector<std::pair<int, int>> avoidSegments;
};

void showMenu() {
	std::cout << "\nRoute Planning Analysis Tool\n";
	std::cout << "1. Load Locations and Distances\n";
	std::cout << "2. Route Planning with input file\n";
	std::cout << "3. Route Planning from terminal menu\n";
	std::cout << "4. Exit\n";
	std::cout << "Enter choice: ";
}

void parseInputStr(std::string& input, const std::string& output) {
	std::cout << output;
	std::cin >> input;
}

void parseInputInt(int input, const std::string& output) {
	std::cout << output;
	std::cin >> input;
}

void stringToVector(const std::string& s, std::vector<int>& v) {
	for (auto& c : s) {
		if (c != ',') {
			v.push_back(c - '0');
		}
	}
}

void stringToVectorOfPair(const std::string& s, std::vector<std::pair<int, int>>& v) {
	std::pair<int, int> holding;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i - 1] == '(' && s[i + 1] == ',') {
			holding.first = i - '0';
		}
		else if (s[i - 1] == ',' && s[i + 1] == ')') {
			holding.second = i - '0';
			v.push_back(holding);
		}
	}
}

RoutePlan showRoutePlanningMenu() {
	std::string mode;
	int source;
	int destination;
	int maxWalkTime;
	std::string avoidNodesStr;
	std::string includeNodesStr;
	std::string avoidSegmentsStr;

	parseInputStr(mode, "Mode:");
	parseInputInt(source, "Source:");
	parseInputInt(destination, "Destination:");
	parseInputInt(maxWalkTime, "MaxWalkTime:");
	parseInputStr(avoidNodesStr, "AvoidNodes:");
	parseInputStr(includeNodesStr, "IncludeNodes:");
	parseInputStr(avoidSegmentsStr, "AvoidSegments:");

	std::vector<int> avoidNodes;
	std::vector<int> includeNodes;
	std::vector<std::pair<int, int>> avoidSegments;

	stringToVector(avoidNodesStr, avoidNodes);
	stringToVector(includeNodesStr, includeNodes);

	stringToVectorOfPair(avoidSegmentsStr, avoidSegments);

	return {mode, source, destination, maxWalkTime, avoidNodes, includeNodes, avoidSegments};
}

int getMainMenuInput() {
	int choice;
	std::cin >> choice;
	std::cout << std::endl;
	return choice;
}

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
			return 0;
		}
	}



	return 0;
}