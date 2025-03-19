#include "routePlan.h"
#include "inputHandler.h"


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