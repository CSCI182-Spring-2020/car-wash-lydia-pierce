/* 
Lydia Pierce
Intro to Data Structures
CarWashApp.cpp : This program simulates a car wash. The user inputs the number of hours to run the simulation
and the probability a car comes off the road. Cars come off the road at random times to join the line.
If the car wash is open, cars waiting in the line go in the wash, and it takes 3 minutes to finish the wash.
The program returns the number of washed cars, the average wait time, and the number of cars left in line at the end.
4/5/2020
*/

#include <iostream>
#include "SimpleList.h"
#include "Node.h"
#include <time.h>
#include <stdlib.h>
#define WASH_TIME 3

using namespace std;

struct UserInputException : public exception {
	const char* what() const throw() {
		return "Invalid entry.";
	}
};

int main()
{
	try{
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

	cout << "Welcome to the Car Wash Simulator 3000!" << endl << endl;
	cout << "How many hours would you like to simulate?\n";
	cout << "Enter an integer: ";
	cin >> _hours;
	if (!cin)
		throw UserInputException();
	cout << "What is the probability of a car showing up at any minute?\n";
	cout << "Enter an integer 1-100: ";
	cin >> nSimCarProbPercentage;
	if (!cin || nSimCarProbPercentage < 1 || nSimCarProbPercentage > 100)
		throw UserInputException();


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
					WashStartTime = 0;
				}
			}
			if (IsCarWashOpen == false)
			{
				WashStartTime++;
				if (WashStartTime % (WASH_TIME * 60) == 0)
					IsCarWashOpen = true;
			}
		
		// Increase the counter by 1 second
		j++;
	}

	if (nWashedCars == 0)
		throw exception("No cars went in the wash");

		AvgWaitTime = TotalWaitTime / nWashedCars;
	cout << "The total numbers of cars washed was: " << nWashedCars << endl;
	cout << "The average wait time of a car that went into the wash was: " << AvgWaitTime
		<< " second(s) or " << AvgWaitTime/60 << " minute(s)" << endl;
	cout << "The number of cars left in line at the close of the simulation: " << CarsinQueue << endl;
	}
	catch (UserInputException & ex)
	{
		cout << "User Input Error found: " << ex.what() << endl;
	}
	catch (exception & ex)
	{
		cout << "Error found: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "REALLY bad error" << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
