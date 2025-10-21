/*
Hannah Rath
Project 2
10/ 05/ 2025
*/

#include "Banking.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Implementation of Banking class

void Banking::SetInitialInvestment(double t_initialInvestment)
{
	m_totalAmount = t_initialInvestment;
}

void Banking::SetMonthlyDeposit(double t_monthlyDeposit)
{
	m_monthlyDeposit = t_monthlyDeposit;
}

void Banking::SetInterestRate(double t_interestRate)
{
	m_interestAmount = t_interestRate;
}

void Banking::SetNumberOfYears(int t_numberOfYears)
{
	m_numberOfYears = t_numberOfYears;
}

double Banking::GetInitialInvestment() const
{
	return m_totalAmount;
}

double Banking::GetMonthlyDeposit() const
{
	return m_monthlyDeposit;
}

double Banking::GetInterestRate() const
{
	return m_interestAmount;
}

int Banking::GetNumberOfYears() const
{
	return m_numberOfYears;
}

double Banking::calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears)
{
	//m_totalAmount = t_initialInvestment;

	//Display table heading
	cout << endl;
	cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << string(66, '=') << endl;
	cout << "Year       Year End Balance       Year End Earned Interest" << endl;
	cout << string(66, '-') << endl;

	//calculate the yearly interest and year end total balance
	for (int i = 0; i < t_numberOfYears; i++) {
		m_interestAmount = m_totalAmount * (t_interestRate / 100);
		m_totalAmount = m_totalAmount + m_interestAmount;
		cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_interestAmount << endl;
	}
	return m_totalAmount;
}

double Banking::balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears)
{
	m_totalAmount = t_initialInvestment;

	//Display table heading
	cout << endl;
	cout << "    Balance and Interest With Additional Monthly Deposits" << endl;
	cout << string(66, '=') << endl;
	cout << "Year       Year End Balance       Year End Earned Interest" << endl;
	cout << string(66, '-') << endl;

	

	//calculate the yearly interest and year end total balance
	for (int i = 0; i < t_numberOfYears; i++) {
		//m_yearlyTotalInterest = 0.0;


		for (int j = 0; j < 12; j++) {
			m_yearlyTotalInterest = m_yearlyTotalInterest + (m_totalAmount + t_monthlyDeposit) * ((t_interestRate / 100) / 12);
			m_totalAmount = (m_totalAmount + t_monthlyDeposit) + (1 + t_interestRate/100/12);
		}
		cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_yearlyTotalInterest << endl;
	}
	return m_totalAmount;
}


