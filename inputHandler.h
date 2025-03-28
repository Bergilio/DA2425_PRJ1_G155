#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <vector>

struct RoutePlan {
	std::string mode;
	int source;
	int destination;
	int maxWalkTime;
	std::vector<int> avoidNodes;
	int includeNode;
	std::vector<std::pair<int, int>> avoidSegments;
};

RoutePlan showRoutePlanningMenu();
RoutePlan fileRoutePlan();
void parseInputStr(std::string& input, const std::string& output);
void parseInputInt(int &input, const std::string& output);
void stringToVector(const std::string& s, std::vector<int>& v);
void stringToVectorOfPair(const std::string& s, std::vector<std::pair<int, int>>& v);

#endif
