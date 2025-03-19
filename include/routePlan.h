#ifndef ROUTEPLAN_H
#define ROUTEPLAN_H

#include <string>
#include <vector>

struct RoutePlan {
	std::string mode;
	int source;
	int destination;
	int maxWalkTime;
	std::vector<int> avoidNodes;
	std::vector<int> includeNodes;
	std::vector<std::pair<int, int>> avoidSegments;
};

RoutePlan showRoutePlanningMenu();



#endif //ROUTEPLAN_H
