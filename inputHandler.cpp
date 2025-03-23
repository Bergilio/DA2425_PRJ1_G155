#include "inputHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

void parseInputStr(std::string& input, const std::string& output) {
	std::cout << output;
	std::cin >> input;
}

void parseInputInt(int &input, const std::string& output) {
	std::cout << output;
	std::cin >> input;
}

void stringToVector(const std::string& s, std::vector<int>& v) {
	if (s == "none") return;

	std::stringstream ss(s);
	std::string token;

	while (std::getline(ss, token, ',')) {
		v.push_back(std::stoi(token));
	}
}

void stringToVectorOfPair(const std::string& s, std::vector<std::pair<int, int>>& v) {
	if (s == "none") return;

	std::regex segmentPattern(R"(\((\d+),(\d+)\))");
	std::smatch match;
	std::string::const_iterator searchStart(s.cbegin());

	while (std::regex_search(searchStart, s.cend(), match, segmentPattern)) {
		int first = std::stoi(match[1]);
		int second = std::stoi(match[2]);
		v.emplace_back(first, second);
		searchStart = match.suffix().first;
	}
}

RoutePlan showRoutePlanningMenu() {
	RoutePlan routePlan = {"", -1, -1, -1, {}, -1, {}};

	std::string avoidNodesStr;
	std::string avoidSegmentsStr;

	parseInputStr(routePlan.mode, "Mode:");
	parseInputInt(routePlan.source, "Source:");
	parseInputInt(routePlan.destination, "Destination:");
	if (routePlan.mode != "driving") {
		parseInputInt(routePlan.maxWalkTime, "MaxWalkTime:");
	}
	parseInputStr(avoidNodesStr, "AvoidNodes:");
	parseInputStr(avoidSegmentsStr, "AvoidSegments:");
	if (routePlan.mode != "driving-walking") {
		parseInputInt(routePlan.includeNode, "IncludeNode:");
	}

	stringToVector(avoidNodesStr, routePlan.avoidNodes);
	stringToVectorOfPair(avoidSegmentsStr, routePlan.avoidSegments);

	return routePlan;
}


RoutePlan fileRoutePlan() {

	RoutePlan routePlan = {"", -1, -1, -1, {}, -1, {}};

	std::ifstream file("input_output/input.txt");

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file: " << "input.txt" << std::endl;
		return routePlan;
	}

	std::string line;

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string key, value;
		std::getline(ss, key, ':');
		std::getline(ss, value);

		if (value.empty()) {
			continue;
		}

		if (key == "Mode") {
			routePlan.mode = value;
		} else if (key == "Source") {
			routePlan.source = std::stoi(value);
		} else if (key == "Destination") {
			routePlan.destination = std::stoi(value);
		} else if (key == "MaxWalkTime") {
			routePlan.maxWalkTime = std::stoi(value);
		} else if (key == "AvoidNodes") {
			stringToVector(value, routePlan.avoidNodes);
		} else if (key == "AvoidSegments") {
			stringToVectorOfPair(value, routePlan.avoidSegments);
		} else if (key == "IncludeNode") {
			routePlan.includeNode = std::stoi(value);
		}
	}

	file.close();

	return routePlan;
}
