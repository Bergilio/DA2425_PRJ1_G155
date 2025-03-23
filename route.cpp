#include "route.h"

void printRoute(Route &route, std::ostream& out) {
	if (route.time < 0) {
		out << "none" << std::endl;
		return;
	}

	for (int i = 0; i < route.length; i++) {
        if (i == route.length - 1) {
            out << route.r[i];
        }
		else {
			out << route.r[i] << ",";
		}
	}
    out << "(" << route.time << ")" << std::endl;
}

void mergeRoutes(Route &route1, const Route &route2) {
	route1.time += route2.time;
	route1.length = route1.length + route2.length - 1;

	for (int i = 1; i < route2.length; i++) {
		route1.r.push_back(route2.r[i]);
	}

}