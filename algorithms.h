/**
* @file algorithms.h
 * @brief Implementation of various routing algorithms including Dijkstra's algorithm
 *        for walking and driving times, as well as route planning functionalities.
 */


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"
#include "route.h"
#include "inputHandler.h"

/**
 * @brief Computes the shortest walking paths using Dijkstra's algorithm.
 *
 * This function finds the shortest walking path from the source node to all other nodes in the graph.
 * The algorithm uses a priority queue, and its time complexity is O((V + E) log V), where V is the number of vertices and E is the number of edges.
 *
 * @param graph The graph on which Dijkstra's algorithm will be applied.
 * @param source The ID of the source node.
 */
void dijkstraDriving(Graph * graph, int source);

/**
 * @brief Computes the shortest driving paths using Dijkstra's algorithm.
 *
 * This function finds the shortest driving path from the source node to all other nodes in the graph.
 * The algorithm uses a priority queue, and its time complexity is O((V + E) log V), where V is the number of vertices and E is the number of edges.
 *
 * @param graph The graph on which Dijkstra's algorithm will be applied.
 * @param source The ID of the source node.
 */
void dijkstraWalking(Graph * graph, int source);

/**
 * @brief Computes the best driving route from source to destination.
 *
 * This function calculates the best driving route between two nodes, based on Dijkstra's algorithm.
 * The time complexity is O((V + E) log V) due to Dijkstra's algorithm.
 *
 * @param graph The graph on which the route will be calculated.
 * @param source The source node ID.
 * @param destination The destination node ID.
 * @return A `Route` object containing the best route, including the path and total time.
 */
Route bestDrivingRoute(Graph *graph, int source, int destination);

/**
 * @brief Computes the best alternative driving route by removing the primary path vertices.
 *
 * This function computes an alternative driving route by removing the vertices in the primary route.
 * The time complexity is O((V + E) log V) due to Dijkstra's algorithm.
 *
 * @param graph The graph on which the route will be calculated.
 * @param route The best driving route to be modified.
 * @return A `Route` object containing the alternative driving route.
 */
Route bestAlternativeDrivingRoute(Graph *graph, Route &route);

/**
 * @brief Removes specified nodes from the graph.
 *
 * This function removes a list of nodes from the graph.
 * The complexity is O(N), where N is the number of nodes to be removed.
 *
 * @param graph The graph from which nodes will be removed.
 * @param nodes A vector of node IDs to be removed.
 */
void removeNodes(Graph* graph, const std::vector<int>& nodes);

/**
 * @brief Removes specified segments (edges) from the graph.
 *
 * This function removes a list of segments from the graph.
 * The complexity is O(E), where E is the number of edges to be removed.
 *
 * @param graph The graph from which edges will be removed.
 * @param edges A vector of pairs, each containing two node IDs representing an edge.
 */
void removeSegments(Graph* graph, const std::vector<std::pair<int, int>>& edges);

/**
 * @brief Plans a route that does not involve any restricted areas or nodes.
 *
 * This function computes both the best driving route and the best alternative driving route, printing the results.
 *
 * @param graph The graph to be used for route calculation.
 * @param routePlan The route plan with source and destination.
 * @param out The output stream to which the results will be printed.
 */
void independentRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out);

/**
 * @brief Plans a restricted route without considering any included nodes.
 *
 * This function computes the best restricted driving route, printing the result.
 *
 * @param graph The graph to be used for route calculation.
 * @param routePlan The route plan with source and destination.
 * @param out The output stream to which the results will be printed.
 */
void restrictedRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out);

/**
 * @brief Plans a restricted route while including a specific node.
 *
 * This function computes the best restricted driving route by considering a specific node for inclusion.
 *
 * @param graph The graph to be used for route calculation.
 * @param routePlan The route plan with source, destination, and the included node.
 * @param out The output stream to which the results will be printed.
 */
void restrictedRouteInclude(Graph * graph, const RoutePlan &routePlan, std::ostream& out);

/**
 * @brief Computes all walking routes for parking spots and the destination.
 *
 * This function computes all walking routes from parking spots to the destination.
 * The time complexity is O(V + E), since it iterates through all vertices and edges.
 *
 * @param graph The graph to be used for route calculation.
 * @param walkingRoutes A vector to store the computed walking routes.
 * @param routePlan The route plan that includes constraints.
 * @return True if there are parking spots available, false otherwise.
 */
bool computeWalkingRoutes(Graph * graph, std::vector<Route> & walkingRoutes, const RoutePlan &routePlan);

/**
 * @brief Finds the best combination of driving and walking routes.
 *
 * This function computes the best driving and walking routes from a set of available walking routes.
 * The time complexity is O(W), where W is the number of walking routes considered.
 *
 * @param graph The graph to be used for route calculation.
 * @param walkingRoutes A vector of walking routes to be considered.
 * @param bestDriving The best driving route (output).
 * @param bestWalking The best walking route (output).
 * @param routePlan The route plan that includes constraints.
 */
void bestDrivingWalking(Graph * graph, const std::vector<Route>& walkingRoutes, Route& bestDriving, Route& bestWalking, const RoutePlan& routePlan);

/**
 * @brief Computes both driving and walking routes based on the route plan.
 *
 * This function computes a combination of driving and walking routes. If no viable solution is found, it recursively tries alternative routes.
 *
 * @param graph The graph to be used for route calculation.
 * @param routePlan The route plan that includes constraints.
 * @param out The output stream to which the results will be printed.
 * @param recursiveCall Indicates whether the function is being called recursively.
 */
void drivingWalkingRoute(Graph * graph, const RoutePlan &routePlan, std::ostream& out, bool recursiveCall = false);

/**
 * @brief Creates the final results for route planning.
 *
 * This function outputs the final results for the route plan, including the source, destination, parking information, and selected routes.
 *
 * @param graph The graph to be used for route calculation.
 * @param routePlan The route plan containing all constraints.
 * @param out The output stream to which the results will be printed.
 */
void resultMaker(Graph *graph, const RoutePlan &routePlan, std::ostream& out);

#endif //ALGORITHMS_H
