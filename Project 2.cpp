/*
Hannah Rath
Project 2
10/ 05/ 2025
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include "Banking.h"

using namespace std;

//Defining Variables
Banking myInvestment;
double initialInvestment = 0.0;
double monthlyDeposit = 0.0;
double interestRate = 0.0;
int years = 0;
char user_input = 'c';

//Home funcgion and input validation
void PrintHomeScreen();
int validIntInput();
double validDoubleInput();


int main()
{
	while (user_input != 'q') {
		PrintHomeScreen();

		myInvestment.calcBalanceWithoutMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
		myInvestment.balanceWithMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetMonthlyDeposit(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());

		cout << "Enter 'q' to quit program or 'c' for new input: ";
		cin >> user_input;
	}
	return 0;
}

void PrintHomeScreen() {
	try {
		//Home screen border
		cout << string(34, '*') << endl;
		cout << string(10, '*') << "  Data Input  " << string(10, '*') << endl;
		
		//initial investment amount
		cout << "Initial Investment Amount: $";
		initialInvestment = validDoubleInput();
		if (initialInvestment < 0) {
			throw runtime_error("Invalid input");
		}
		myInvestment.SetInitialInvestment(initialInvestment);

		//MonthlyDeposit
		cout << "Monthly Deposit: $";
		monthlyDeposit = validDoubleInput();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid input");
		}
		myInvestment.SetMonthlyDeposit(monthlyDeposit);

		//Annual Interest
		cout << "Annual Interest: %";
		interestRate = validDoubleInput();
		if (interestRate < 0) {
			throw runtime_error("Invalid input");
		}
		myInvestment.SetInterestRate(interestRate);

		//Number of Years
		cout << "Number of Years: ";
		years = validIntInput();
		if (years < 0) {
			throw runtime_error("Invalid input");
		}
		myInvestment.SetNumberOfYears(years);
	}

	catch (runtime_error& excpt) {
		cout << "Error, cannot enter a negative number" << endl;
	}
}

int validIntInput() {
	int x;

	while (1) {
		if (cin >> x) {
			break;
		}
		else {
			cout << "Invalid input";
				cin.clear();
				while (cin.get() != '\n');
		}
	}
	return x;
}

double validDoubleInput() {
	double x;

	while (1) {
		if (cin >> x) {
			break;
		}
		else {
			cout << "Invalid input";
			cin.clear();
			while (cin.get() != '\n');
		}
	}
	return x;
}

