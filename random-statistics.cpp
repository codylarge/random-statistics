// random-statistics.cpp : Defines the entry point for the application.
// This is a simple program to test different statistics that im curious about
// Each different statistic will be its own function within the Calculator class

#include "random-statistics.h"
#include "Calculator.h"  // Include the header file for Calculator
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

int main()
{
    auto start = high_resolution_clock::now();

    Calculator calculator;

    // Find the number of flips to get 'inARow' heads in a row
    int inARow = 12;
    int expectedAttempts = pow(2, inARow);
    int result = calculator.singleInARow(inARow);
    bool anomaly = calculator.checkForAnomaly(result, expectedAttempts);
    //calculator.headsInARow(18);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Attempts to get " << inARow << " in a row: " << result << endl;
    cout << "Total runtime: " << duration.count() << " milliseconds" << endl;

    if (anomaly)
        cout << "Anomaly detected!!!" << endl << "Expected attempts : " << expectedAttempts << endl;
    //cout << "Total runtime: " << duration.count()/1000 << " seconds" << endl;

    return 0;
}