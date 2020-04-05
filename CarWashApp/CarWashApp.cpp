/* 
Lydia Pierce
Intro to Data Structures
CarWashApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
4/5/2020
*/

#include <iostream>
#include "SimpleList.h"
#include "Node.h"
#include <time.h>
#include <stdlib.h>
#define WASH_TIME 3

using namespace std;

int main()
{
	// Seed the random generator (near the top)
	srand(time(NULL));

	int _hours = 0;
	int nSimCarProbPercentage = 0;
	bool IsCarWashOpen = true;
	int nWashedCars = 0;
	int CarsinQueue = 0;
	int WaitTime = 0;
	int TotalWaitTime = 0;
	float AvgWaitTime = 0;
	int WashStartTime = 0;
	int j = 0;
	int entrytime;
	SimpleList s1;

	cout << "How many hours would you like to simulate?\n";
	cout << "Enter an integer: ";
	cin >> _hours;
	cout << "What is the probability of a car showing up at any minute?\n";
	cout << "Enter an integer 1-100: ";
	cin >> nSimCarProbPercentage;


	// A counter for the hours the simulation will run
	while (j <= _hours * 360)
	{
			// Has a car arrived off the road?
			// For each second, get a random value.  If you do it like this,
			// you get a number between 0-99
			int q = rand() % 100;
			// Below we check if it's within the probability
			// nSimCarProbPercentage is the percentage entered by the user
			// If a car has arrived, add it to the queue
			if (q < nSimCarProbPercentage)
			{
				// Process a car into the queue
				
				entrytime = j;
				s1.QueueItem(entrytime);
				CarsinQueue++;

				if (IsCarWashOpen == true)
				{
					WaitTime = j - s1.DequeueItem();
					TotalWaitTime = TotalWaitTime + WaitTime;
					CarsinQueue--;
					nWashedCars++;
					IsCarWashOpen = false;
					WashStartTime = entrytime;
				}
			}
			if (IsCarWashOpen == false)
			{
				if (WashStartTime % (WASH_TIME * 60) == 0 && j != 0)
					IsCarWashOpen = true;
				WashStartTime++;
			}
		
		// Increase the counter by 1 second
		j++;
	}
	AvgWaitTime = TotalWaitTime / nWashedCars;
	cout << "The total numbers of cars washed was: " << nWashedCars << endl;
	cout << "The average wait time of a car that went into the wash was: " << AvgWaitTime << " second(s)" << endl;
	cout << "The number of cars left in line at the close of the simulation: " << CarsinQueue << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
