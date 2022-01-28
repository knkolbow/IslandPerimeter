#ifndef CALCULATE_PERIMETER_H
#define CALCULATE_PERIMETER_H

#include <vector>
#include <algorithm>

//using namespace std;

/** Calculates the perimeter of an island
	@param islandPerimeter: 2 dimensional array (vector) of the island
	@returns: the calculated perimeter of the island
*/

int calc_perimeter(const std::vector<std::vector<int> >& islandPerimeter) {
	//Initialize return value
	int perimeter = 0;

	//Check for 1's
	for (int i = 0; i < islandPerimeter.size(); i++) {
		for (int j = 0; j < islandPerimeter[i].size(); j++) {
			if (islandPerimeter[i][j] == 1) {
				int count = 0;

				//Check if cell is in top row OR has 0 above
				if (i == 0 || islandPerimeter[i - 1][j] == 0) {
					count++;
				}
				//Check if cell is in the bottom row or has 0 below
				if (i == islandPerimeter.size() - 1 || islandPerimeter[i + 1][j] == 0) {
					count++;
				}
				//Check if cell is all the way to the left or has 0 to the left
				if (j == 0 || islandPerimeter[i][j - 1] == 0) {
					count++;
				}
				//Check if cell is all the way to the right or has 0 to the right
				if (j == islandPerimeter[i].size() - 1 || islandPerimeter[i][j + 1] == 0) {
					count++;
				}
				//add count to the perimeter
				perimeter += count;
			}
		}
	}
	return perimeter;
}
#endif