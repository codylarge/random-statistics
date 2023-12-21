// random-statistics.cpp : Defines the entry point for the application.
// This is a simple program to test different statistics that im curious about
// Each different statistic will be its own function within the Calculator class

#include "random-statistics.h"
#include "Calculator.h"  // Include the header file for Calculator

using namespace std;

int main()
{
    Calculator calculator;

    calculator.singleInARow(15);
    //calculator.headsInARow(18);

    return 0;
}