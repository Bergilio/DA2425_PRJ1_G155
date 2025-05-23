#include "algorithms.h"
#include <iostream>
#include <algorithm>
#include <climits>

void dijkstraWalking(Graph * graph, int source) {
	Vertex * src = graph->findVertexById(source);

	if (!src) {
		return;
	}

	for (auto v : graph->getVertexSet()) {
		v->setDist(INT_MAX);
		v->setVisited(false);
		v->setPath(nullptr);
	}

	src->setDist(0);

	MutablePriorityQueue<Vertex> *queue = new MutablePriorityQueue<Vertex>;
	queue->insert(src);

	while (!queue->empty()) {
		auto v = queue->extractMin();
		v->setVisited(true);

		for (auto e : v->getAdj()) {
			auto u = e->getDest();
			int walking = e->getWalking();

			if (!u->isVisited() && v->getDist() + walking < u->getDist()) {
				u->setDist(v->getDist() + walking);
				u->setPath(e);

				if (u->queueIndex == 0) {
					queue->insert(u);
				}
				else {
					queue->decreaseKey(u);
				}
			}
		}
	}

	delete queue;
}

void dijkstraDriving(Graph * graph, int source) {
	Vertex * src = graph->findVertexById(source);

	if (!src) {
		return;
	}

	for (auto v : graph->getVertexSet()) {
		v->setDist(INT_MAX);
		v->setVisited(false);
		v->setPath(nullptr);
	}

	src->setDist(0);

	MutablePriorityQueue<Vertex> *queue = new MutablePriorityQueue<Vertex>;
	queue->insert(src);

	while (!queue->empty()) {
		auto v = queue->extractMin();
		v->setVisited(true);

		for (auto e : v->getAdj()) {
			auto u = e->getDest();
			int driving = e->getDriving();

			if (!u->isVisited() && v->getDist() + driving < u->getDist()) {
				u->setDist(v->getDist() + driving);
				u->setPath(e);

				if (u->queueIndex == 0) {
					queue->insert(u);
				}
				else {
					queue->decreaseKey(u);
				}
			}
		}
	}

	delete queue;
}

Route bestDrivingRoute(Graph *graph, int source, int destination) {
	dijkstraDriving(graph, source);
	Vertex * dest = graph->findVertexById(destination);

	if (dest->getDist() == INT_MAX) {
		return {{}, 0, -1};
	}

	std::vector<int> route;
	Edge * cur = dest->getPath();
	int time = dest->getDist();

	while (cur != nullptr) {
		route.push_back(cur->getDest()->getId());
		cur = cur->getOrig()->getPath();
	}
	route.push_back(source);

	std::reverse(route.begin(), route.end());

	return {route, (int)route.size(), time};
}

Route bestAlternativeDrivingRoute(Graph* graph, Route &route) {
	for (int i = 1; i < route.length - 1; i++) {
		graph->removeVertex(route.r[i]);
	}
	return bestDrivingRoute(graph, route.r[0], route.r[route.length-1]);
}

// ------------------------------------ Final Solution Functions -------------------------------------------------- //

// Helper function to remove vertexes, built because of reusability

void removeNodes(Graph* graph, const std::vector<int>& nodes) {
	for (int i = 0; i < nodes.size(); i++) {
		graph->removeVertex(nodes[i]);
	}
}

// Helper function to remove only the edges, not vertexes

void removeSegments(Graph* graph, const std::vector<std::pair<int, int>>& edges) {
	for (auto &p : edges) {
		Vertex* v1 = graph->findVertexById(p.first);
		Vertex* v2 = graph->findVertexById(p.second);

		if (v1 && v2) {
			v1->removeEdge(p.second);
			v2->removeEdge(p.first);
		}
	}
}

// Independent Route Planning

void independentRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out) {
	Route route = bestDrivingRoute(graph, routePlan.source, routePlan.destination);
	out << "BestDrivingRoute:"; printRoute(route, out);

	route = bestAlternativeDrivingRoute(graph, route);
	out << "BestAlternativeDrivingRoute:"; printRoute(route, out);
}

// Restricted Route Planning without any Included Nodes

void restrictedRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out) {
	Route route = bestDrivingRoute(graph, routePlan.source, routePlan.destination);
	out << "RestrictedDrivingRoute:"; printRoute(route, out);
}

// Restricted Route Planning with the Included Node

void restrictedRouteInclude(Graph * graph, const RoutePlan &routePlan, std::ostream& out) {
	Route route1 = bestDrivingRoute(graph, routePlan.source, routePlan.includeNode);
	Route route2 = bestDrivingRoute(graph, routePlan.includeNode, routePlan.destination);
	mergeRoutes(route1, route2);
	out << "RestrictedDrivingRoute:"; printRoute(route1, out);
}

// Driving and Walking Route Planning

bool computeWalkingRoutes(Graph * graph, std::vector<Route> & walkingRoutes, const RoutePlan &routePlan) {
	bool hasParking = false;

	for (auto v : graph->getVertexSet()) {
		if (v->getParking()) {
			hasParking = true;

			if (v->getDist() <=routePlan.maxWalkTime) {
				Route route;

				Edge * cur = v->getPath();
				route.time = v->getDist();

				while (cur != nullptr) {
					route.r.push_back(cur->getDest()->getId());
					cur = cur->getOrig()->getPath();
				}
				route.r.push_back(routePlan.destination);

				route.length = route.r.size();

				walkingRoutes.push_back(route);
			}
		}
	}

	return hasParking;
}

// Helper function to find the best walking and driving routes

void bestDrivingWalking(Graph * graph, const std::vector<Route>& walkingRoutes, Route& bestDriving, Route& bestWalking, const RoutePlan& routePlan) {
	int curWalkingTime = 0;

	for (auto &walkingRoute : walkingRoutes) {
		int id = walkingRoute.r[0];
		int drivingDistance = graph->findVertexById(id)->getDist();

		if (drivingDistance + walkingRoute.time < bestDriving.time + bestWalking.time ||
		(drivingDistance + walkingRoute.time == bestDriving.time + bestWalking.time && curWalkingTime < walkingRoute.time)) {

			curWalkingTime = walkingRoute.time;
			Route drivingRoute;

			Edge * cur = graph->findVertexById(id)->getPath();
			drivingRoute.time = graph->findVertexById(id)->getDist();

			while (cur != nullptr) {
				drivingRoute.r.push_back(cur->getDest()->getId());
				cur = cur->getOrig()->getPath();
			}
			drivingRoute.r.push_back(routePlan.source);
			drivingRoute.length = drivingRoute.r.size();

			std::reverse(drivingRoute.r.begin(), drivingRoute.r.end());

			bestDriving = drivingRoute;
			bestWalking = walkingRoute;
		}
	}
}

void drivingWalkingRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out, bool recursiveCall) {
 	dijkstraWalking(graph, routePlan.destination);

	std::vector<Route> walkingRoutes;
	bool hasParking = computeWalkingRoutes(graph, walkingRoutes, routePlan);

	if (walkingRoutes.size() == 0 && !recursiveCall) {
		out << "DrivingRoute:none" << std::endl;
		out << "ParkingNode:none" << std::endl;
		out << "WalkingRoute:none" << std::endl;
		out << "TotalTime:" << std::endl;
		if (hasParking) {
			out << "Message:No possible route with max. walking time of " << routePlan.maxWalkTime << " minutes." << std::endl;
		}
		else {
			out << "Message:Absence of parking spot." << std::endl;
		}
		RoutePlan alternativeRoutePlan = routePlan;
		alternativeRoutePlan.maxWalkTime = INT_MAX;
		if (hasParking) {
			out << std::endl << "Source:" << routePlan.source << std::endl;
			out << "Destination:" << routePlan.destination << std::endl;
			drivingWalkingRoute(graph, alternativeRoutePlan, out, true);
			drivingWalkingRoute(graph, alternativeRoutePlan, out, true);
		}
		return;
	}

	dijkstraDriving(graph, routePlan.source);

	Route bestDriving = {{}, 0, INT_MAX / 2 - 1};
	Route bestWalking = {{}, 0, INT_MAX / 2 - 1};

	bestDrivingWalking(graph, walkingRoutes, bestDriving, bestWalking, routePlan);

	if (hasParking) {
		out << "DrivingRoute:"; printRoute(bestDriving, out);
		out << "ParkingNode:" << bestWalking.r[0] << std::endl;
		out << "WalkingRoute:"; printRoute(bestWalking, out);
		out << "TotalTime:" << bestWalking.time + bestDriving.time << std::endl;
	}

	if (recursiveCall) {
		removeNodes(graph, {bestWalking.r[0]});
	}
}


// This function decides what to do according to the route plan that was chosen. Some behaviour, like printing the
// source and destination or removing the nodes and segments is common to every plan there is, so it is done by this function.

// The avoidNodes and avoidSegments in RoutePlan is just an empty vector if those fields were empty in the input, so
// nothing will be removed from the graph and the expected behaviour will be met.

void resultMaker(Graph *graph, const RoutePlan &routePlan, std::ostream& out) {
	out << "Source:" << routePlan.source << std::endl;
	out << "Destination:" << routePlan.destination << std::endl;

	removeNodes(graph, routePlan.avoidNodes);
	removeSegments(graph, routePlan.avoidSegments);

	if (routePlan.mode == "driving" && routePlan.includeNode < 0 && routePlan.avoidNodes.empty() && routePlan.avoidSegments.empty()) {
		independentRoute(graph, routePlan, out);
	}
	else if (routePlan.mode == "driving" && (routePlan.includeNode >= 0 || !routePlan.avoidNodes.empty() || !routePlan.avoidSegments.empty())) {
		if (routePlan.includeNode < 0) {
			restrictedRoute(graph, routePlan, out);
		}
		else {
			restrictedRouteInclude(graph, routePlan, out);
		}
	}
	else if (routePlan.mode == "driving-walking") {
		drivingWalkingRoute(graph, routePlan, out);
	}
}

