#include "Perimeter.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	//Open file and check if it opened successfully
	ifstream inputFile("input.txt");
	if (!inputFile) {
		cout << "Error - Nonexisting Input File" << endl;
		system("pause");
		return -1;
	}
	//Open output file
	ofstream outputFile("output.txt");

	//Get dimensions of grid
	int rowInput, column, cell;
	inputFile >> rowInput;
	inputFile >> column;

	//Initialize 2 dimensional vector to be size of grid
	vector<int> columnVector(column);
	vector<vector<int> > islandPerimeter(rowInput, columnVector);

	//Process remainder of input file into vector
	for (int i = 0; i < islandPerimeter.size(); i++) {
		for (int j = 0; j < islandPerimeter[i].size(); j++) {
			inputFile >> cell;
			islandPerimeter[i][j] = cell;
		}
	}

	//calculate the perimeter with used defined function
	int perimeter = calc_perimeter(islandPerimeter);

	//Output perimeter to output file
	outputFile << "Perimeter: " << perimeter;

	//Close the files
	outputFile.close();
	inputFile.close();
	//system("pause");
	return 0;
}