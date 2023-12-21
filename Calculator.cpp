
#include "Calculator.h"
#include <random>
#include <iostream>
#include <cmath>

// Consider 0 Heads and 1 Tails
void Calculator::headsInARow(int maxInARow)
{
	bool result;
	int inARow = 1;
	int flipNumber = 0;
	std::vector<int> resultsArray(maxInARow);

	while (inARow <= maxInARow)
	{
		result = completeInARow(flipNumber, inARow);
		if(result != true) throw new std::exception("Error in headsInARow");
		resultsArray[inARow - 1] = flipNumber;
		//std::cout << inARow << " Heads in a row completed after " << flipNumber << " attempts" << "\n\n";
		inARow++;
		flipNumber = 0;
	}

	// Print the elements of the vector
	for (int i = 0; i < resultsArray.size(); ++i) {
		std::cout << "Attempts to get " << i+1 << " in a row: " << resultsArray[i] << std::endl;
	}
}

void Calculator::singleInARow(int inARow)
{
	bool result;
	int flipNumber = 0;

	result = completeInARow(flipNumber, inARow);
	if (result != true) throw new std::exception("Error in headsInARow");
	std::cout << inARow << " Heads in a row completed after " << flipNumber << " attempts" << "\n\n";
}

bool Calculator::completeInARow(int &flipNumber, int inARow)
{
	int currentInARow = 0;
	int attempts = 0;
	int spacer = 0;

	while (currentInARow < inARow)
	{ 
		// Use a random device to seed the generator and use a Mersenne Twister engine for randomness
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, 1); 
		// Generate a random number (either 0 or 1)
		int randomNumber = distrib(gen);


		if (spacer == 10)
		{
			std::cout << std::endl;
			spacer = 0;
		}

		if (randomNumber == 0)
		{
			std::cout << "Heads " << " ";
			currentInARow++;
		}
		else
		{
			std::cout << "Tails " << " ";
			currentInARow = 0;
			attempts++;
		}
		//std::cout << "Current in a row: " << currentInARow << std::endl;
		//std::cout << "Flip number: " << flipNumber << std::endl;
		spacer++;
		flipNumber++;
	}
	std::cout << "\n\n";
	//std::cout << "True attempts to get " << inARow << " in a row: " << attempts << std::endl; // Will statistically be 1/2 of total flips 
	return true;
}
bool Calculator::checkForAnomaly(int attempts, int inARow)
{
	// 'anomaly' determines the amount something can deviate from the expected value, e.g. 2 means it must be at least 2x or 1/2x the expected value to be an anomaly 
	int anomaly = 3;
	int expectedAttempts = pow(2, inARow);
	if (attempts < expectedAttempts/anomaly || attempts > expectedAttempts * anomaly)
	{
		return true;
	}
	else
	{
		return false;
	}
}
