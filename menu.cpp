#include "menu.h"
#include <iostream>

void showMenu() {
	std::cout << "\nRoute Planning Analysis Tool\n";
	std::cout << "1. Route Planning with input file\n";
	std::cout << "2. Route Planning from terminal menu\n";
	std::cout << "3. Exit\n";
	std::cout << "Enter choice: ";
}

int getMainMenuInput() {
	int choice;
	std::cin >> choice;
	std::cout << std::endl;
	return choice;
}
