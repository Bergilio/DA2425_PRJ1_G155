/**
* @file dataParser.h
 * @brief This module provides functionality for parsing data from csv format
 *		  and constructing a graph representing the locations and the segments
 */


#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <string>
#include <vector>
#include "Graph.h"

/**
 * @brief Represents a location with its ID, code, and parking availability.
 */
struct Location{
	std::string location;
	int id;
	std::string code;
	bool parking;
};

/**
 * @brief Represents the driving and walking distance between two locations.
 */
struct Distance{
	std::string location1;
	std::string location2;
	int driving;
	int walking;
};

/**
 * @brief Parses a CSV file containing location data.
 *
 * Parses the provided file and returns a list of `Location` objects.
 * The time complexity is O(n), where n is the number of lines in the input file.
 *
 * @param filename The path to the location CSV file.
 * @return A vector of `Location` objects.
 */
std::vector<Location> parseLocations(const std::string& filename);

/**
 * @brief Parses a CSV file containing distance data between locations.
 *
 * Parses the provided file and returns a list of `Distance` objects.
 * The time complexity is O(m), where m is the number of lines in the input file.
 *
 * @param filename The path to the distance CSV file.
 * @return A vector of `Distance` objects.
 */
std::vector<Distance> parseDistances(const std::string& filename);

/**
 * @brief Fills the graph with vertices and edges based on location and distance data.
 *
 * This function reads location and distance data from files and populates the graph
 * with corresponding vertices and bidirectional edges. The time complexity is O(n + m),
 * where n is the number of locations and m is the number of distance entries.
 *
 * @param graph The pointer to the graph that will be filled.
 * @param locationFilename The path to the location CSV file.
 * @param distanceFilename The path to the distance CSV file.
 */
void fileToGraph(Graph * graph, const std::string& locationFilename, const std::string& distanceFilename);

#endif
