/**
* @file menu.h
 * @brief Contains functions for displaying the main menu and receiving user input.
 */

#ifndef MENU_H
#define MENU_H

/**
 * @brief Displays the main menu of the route planning tool.
 *
 * The menu gives the user options for route planning with a file or from the terminal,
 * as well as an option to exit the program.
 */
void showMenu();

/**
 * @brief Receives and returns the main menu input from the user.
 *
 * @return int User choice from the main menu.
 */
int getMainMenuInput();

#endif //MENU_H
