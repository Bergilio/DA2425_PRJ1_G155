#include "inputHandler.h"
#include <iostream>

void parseInputStr(std::string& input, const std::string& output) {
	std::cout << output;
	std::cin >> input;
}

void parseInputInt(int input, const std::string& output) {
	std::cout << output;
	std::cin >> input;
}

void stringToVector(const std::string& s, std::vector<int>& v) {
	for (auto& c : s) {
		if (c != ',') {
			v.push_back(c - '0');
		}
	}
}

void stringToVectorOfPair(const std::string& s, std::vector<std::pair<int, int>>& v) {
	std::pair<int, int> holding;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i - 1] == '(' && s[i + 1] == ',') {
			holding.first = i - '0';
		}
		else if (s[i - 1] == ',' && s[i + 1] == ')') {
			holding.second = i - '0';
			v.push_back(holding);
		}
	}
}
