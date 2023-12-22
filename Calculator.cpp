#include "Calculator.h"
#include <random>

// Consider 0 Heads and 1 Tails

int Calculator::singleInARow(int inARow)
{
	bool result;
	int flipNumber = 0;

	result = completeInARow(flipNumber, inARow);
	if (result != true) throw new std::exception("Error in headsInARow");
	return flipNumber;
	//std::cout << inARow << " Heads in a row completed after " << flipNumber << " attempts" << "\n\n";
}

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
	for (int i = 0; i < resultsArray.size(); ++i)
		std::cout << "Attempts to get " << i+1 << " in a row: " << resultsArray[i] << std::endl;
}

bool Calculator::completeInARow(int &flipNumber, int inARow)
{
	int currentInARow = 0;
	int attempts = 0;

	while (currentInARow < inARow)
	{ 
		// Use a random device to seed the generator and use a Mersenne Twister engine for randomness
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, 1); 
		// Generate a random number (either 0 or 1)
		int randomNumber = distrib(gen);

		if (randomNumber == 0)
		{
			std::cout << "1 ";
			currentInARow++;
		}
		else
		{
			std::cout << "0 ";
			currentInARow = 0;
			attempts++;
		}

		//std::cout << "Current in a row: " << currentInARow << std::endl;
		//std::cout << "Flip number: " << flipNumber << std::endl;
		flipNumber++;
	}
	std::cout << "\n\n";
	//std::cout << "True attempts to get " << inARow << " in a row: " << attempts << std::endl; // Will statistically be 1/2 of total flips 
	return true;
}

bool Calculator::checkForAnomaly(int attempts, int expectedAttempts)
{
	// 'anomaly' determines the amount something can deviate from the expected value, e.g. 2 means it must be at least 2x or 1/2x the expected value to be an anomaly 
	int anomaly = 3;
	if (attempts < expectedAttempts/anomaly || attempts > expectedAttempts * anomaly)
		return true;
	else
		return false;
}
