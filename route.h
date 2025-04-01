/**
* @file route.h
 * @brief Contains definitions for route-related structures and functions.
 *
 * This file defines the `Route` structure and provides functions for printing and merging routes.
 */

#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <iostream>

/**
 * @struct Route
 * @brief Represents a route with a sequence of locations and travel time.
 *
 * This structure holds the locations of a route (as indices), the number of locations in the route,
 * and the total time taken for the route.
 */
struct Route {
  std::vector<int> r;
  int length;
  int time;
};

/**
 * @brief Prints a route to the specified output stream.
 *
 * @param route The route to be printed.
 * @param out The output stream to print to.
 */
void printRoute(Route &route, std::ostream& out);

/**
 * @brief Merges two routes into one.
 *
 * The second route is appended to the first route, and the total time is updated.
 *
 * @param route1 The first route to be updated.
 * @param route2 The second route to be merged into the first.
 */
void mergeRoutes(Route &route1, const Route &route2);

#endif //ROUTE_H
