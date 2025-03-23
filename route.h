#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <iostream>

struct Route {
  std::vector<int> r;
  int length;
  int time;
};

void printRoute(Route &route, std::ostream& out);
void mergeRoutes(Route &route1, const Route &route2);

#endif //ROUTE_H
