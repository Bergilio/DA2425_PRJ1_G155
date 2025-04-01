/**
* @file inputHandler.h
 * @brief Functions for handling user input for route planning.
 *
 * This file defines functions for parsing user inputs and converting them into appropriate data structures
 * for route planning.
 */
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <vector>

/**
 * @struct RoutePlan
 * @brief Represents a route planning configuration.
 *
 * This structure holds all the necessary information for a route plan, including the mode of transportation,
 * source and destination locations, maximum walking time, nodes to avoid, and segments to avoid.
 */
struct RoutePlan {
	std::string mode;
	int source;
	int destination;
	int maxWalkTime;
	std::vector<int> avoidNodes;
	int includeNode;
	std::vector<std::pair<int, int>> avoidSegments;
};

/**
 * @brief Displays the route planning menu and collects input from the user.
 *
 * The user is prompted for all necessary parameters for route planning, including the mode of transportation,
 * source, destination, and any constraints like avoidances or maximum walking time.
 *
 * @return RoutePlan The route plan based on the user's input.
 */
RoutePlan showRoutePlanningMenu();

/**
 * @brief Reads a route plan from an input file.
 *
 * Reads the route plan configuration from the input file `input_output/input.txt`, parsing each
 * field and returning a `RoutePlan` object.
 *
 * @return RoutePlan The route plan read from the input file.
 */
RoutePlan fileRoutePlan();

/**
 * @brief Parses a string input from the user.
 *
 * @param input The string to store the parsed input.
 * @param output The prompt message shown to the user.
 */
void parseInputStr(std::string& input, const std::string& output);

/**
 * @brief Parses an integer input from the user.
 *
 * @param input The integer to store the parsed input.
 * @param output The prompt message shown to the user.
 */
void parseInputInt(int &input, const std::string& output);

/**
 * @brief Converts a comma-separated string into a vector of integers.
 *
 * @param s The string to be converted.
 * @param v The vector where the integers will be stored.
 */
void stringToVector(const std::string& s, std::vector<int>& v);

/**
 * @brief Converts a string representing pairs of integers into a vector of pairs.
 *
 * @param s The string to be converted.
 * @param v The vector where the pairs will be stored.
 */
void stringToVectorOfPair(const std::string& s, std::vector<std::pair<int, int>>& v);

#endif
