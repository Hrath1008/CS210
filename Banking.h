/*
Hannah Rath
Project 2
10/ 05/ 2025
*/

#pragma once
#ifndef BANKING_H
#define BANKING_H

//Class for inputs 
class Banking
{
public:
	void SetInitialInvestment(double t_initialInvestment);
	void SetMonthlyDeposit(double t_monthlyDeposit);
	void SetInterestRate(double t_interestRate);
	void SetNumberOfYears(int t_numberOfYears);
	double GetInitialInvestment() const;
	double GetMonthlyDeposit() const;
	double GetInterestRate() const;
	int GetNumberOfYears() const;
	double calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears);
	double balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);


private:
	double m_totalAmount = 0.0;
	double m_interestAmount = 0.0;
	double m_yearlyTotalInterest = 0.0;
	double m_monthlyDeposit = 0.0;
	int m_numberOfYears = 0;

};
#endif