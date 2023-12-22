#include <iostream>

class Calculator {
public:
	void headsInARow(int maxInARow);
	int singleInARow(int inARow);
	bool completeInARow(int &attempt, int inARow);
	void printResult(std::string toPrint, int& printsPerRow);
	bool checkForAnomaly(int attempts, int expectedAttempts);
};