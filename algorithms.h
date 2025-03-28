#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"
#include "route.h"
#include "inputHandler.h"

void dijkstraDriving(Graph * graph, int source);
void dijkstraWalking(Graph * graph, int source);
Route bestDrivingRoute(Graph *graph, int source, int destination);
Route bestAlternativeDrivingRoute(Graph *graph, Route &route);
void removeNodes(Graph* graph, const std::vector<int>& nodes);
void removeSegments(Graph* graph, const std::vector<std::pair<int, int>>& edges);
void independentRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out);
void restrictedRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out);
void restrictedRouteInclude(Graph * graph, const RoutePlan &routePlan, std::ostream& out);
void drivingWalkingRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out, bool recursiveCall = false);
void resultMaker(Graph *graph, const RoutePlan &routePlan, std::ostream& out);

#endif //ALGORITHMS_H
