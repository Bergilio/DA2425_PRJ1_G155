# Route Planning Tool

## Overview
The **Route Planning Tool** is a C++ application designed to calculate optimal routes on a graph-based map. The tool considers both driving and walking segments, allowing users to specify constraints such as maximum walking distance. It aims to minimize total travel time while ensuring practical route selection.

## Features
- **Graph-Based Route Calculation**: Uses a custom graph implementation to represent roads and pathways.
- **Driving Only Route Calculation**: Computes the optimal route for users that only want to drive.
- **Driving & Walking Integration**: Finds the best route that allows the user to park the car and walk the last segment of the path.
- **Optimized Travel Time**: Prioritizes minimizing overall travel duration.
- **User-Defined Restrictions**: Allows users to invoke restrictions on their route, including avoiding locations, avoiding specific streets, adding an obligatory stop at a certain location, or setting the maximum time they are willing to walk.
- **Data Parsing**: Reads road and location data from `.csv` files.
- **Interactive User Input**: Accepts parameters for start and destination points, restrictions, and mode selection.

## Technologies Used
- **C++**: Core language for implementation.
- **CLion**: Primary development environment.
- **STL Containers & Algorithms**: Utilized for efficient graph operations.
- **Custom Graph Implementation**: Inspired by professor’s model, including `MutablePriorityQueue` and `operator<` for vertices.

## Setup Instructions
1. **Clone the Repository**:
   ```sh
   git clone https://github.com/Bergilio/DA2425_PRJ1_G155.git
   cd route-planning-tool
   ```
2. **Build the Project** (Using CLion or manually via CMake/G++)
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
3. **Run the Program**:
   ```sh
   ./main
   ```

## Usage
- Choose input format from the menu options:
  - File input (input.txt)
  - Terminal menu
- Provide input for:
  - Start and destination locations.
  - Maximum walking distance (if applicable).
  - Preferred mode (driving, walking, mixed).
  - Restrictions such as location avoidance, mandatory stops, and walking time limits.
- The tool will output the optimal route and estimated travel time (if you choose the file input format, the output can b efound in output.txt).


