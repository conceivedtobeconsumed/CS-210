// Investment.cpp
// Implementation of the Investment class declared in Investment.h.
//
// Author: [Your Name]
// Date:   [Enter date]

#include "Investment.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

// Set up the object with whatever starting values were passed in.
Investment::Investment(double t_initialInvestment,
                       double t_monthlyDeposit,
                       double t_annualInterestRate,
                       int t_numberOfYears)
	: m_initialInvestment(t_initialInvestment),
	  m_monthlyDeposit(t_monthlyDeposit),
	  m_annualInterestRate(t_annualInterestRate),
	  m_numberOfYears(t_numberOfYears)
{
}

// A starting investment can't be negative money.
void Investment::setInitialInvestment(double t_initialInvestment)
{
	if (t_initialInvestment < 0.0)
		throw invalid_argument("Initial investment cannot be negative.");
	m_initialInvestment = t_initialInvestment;
}

// Monthly deposits can't be negative either.
void Investment::setMonthlyDeposit(double t_monthlyDeposit)
{
	if (t_monthlyDeposit < 0.0)
		throw invalid_argument("Monthly deposit cannot be negative.");
	m_monthlyDeposit = t_monthlyDeposit;
}

// Interest rate is a percent; a negative rate doesn't make sense here.
void Investment::setAnnualInterestRate(double t_annualInterestRate)
{
	if (t_annualInterestRate < 0.0)
		throw invalid_argument("Annual interest rate cannot be negative.");
	m_annualInterestRate = t_annualInterestRate;
}

// Need at least one year to have anything to report.
void Investment::setNumberOfYears(int t_numberOfYears)
{
	if (t_numberOfYears <= 0)
		throw invalid_argument("Number of years must be greater than zero.");
	m_numberOfYears = t_numberOfYears;
}

double Investment::getInitialInvestment() const
{
	return m_initialInvestment;
}

double Investment::getMonthlyDeposit() const
{
	return m_monthlyDeposit;
}

double Investment::getAnnualInterestRate() const
{
	return m_annualInterestRate;
}

int Investment::getNumberOfYears() const
{
	return m_numberOfYears;
}

// Print a year-end table. Interest compounds monthly: each month we add the
// deposit and that month's interest to the running balance, then total up the
// interest for the year to show in the "Year End Earned Interest" column.
void Investment::printReport(bool t_includeMonthlyDeposit) const
{
	// Skip the deposit entirely for the "no additional deposits" report.
	double monthlyDeposit = t_includeMonthlyDeposit ? m_monthlyDeposit : 0.0;

	// Convert the yearly percentage into a monthly decimal rate.
	double monthlyRate = (m_annualInterestRate / 100.0) / 12.0;

	// Running balance starts at the initial investment and carries forward.
	double openingAmount = m_initialInvestment;

	// Table header.
	cout << "  Year          Year End Balance      Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------------" << endl;

	// Two decimal places with a fixed point, the way currency reads.
	cout << fixed << setprecision(2);

	for (int year = 1; year <= m_numberOfYears; ++year)
	{
		double yearlyInterest = 0.0;

		// Twelve months of compounding for this year.
		for (int month = 1; month <= 12; ++month)
		{
			double monthInterest = (openingAmount + monthlyDeposit) * monthlyRate;
			yearlyInterest += monthInterest;
			openingAmount += monthlyDeposit + monthInterest;
		}

		// Right-align each column under its header. Building each cell as a
		// stream string lets the "$" stay attached to the number while setw
		// handles the alignment.
		ostringstream balanceCell;
		balanceCell << "$" << fixed << setprecision(2) << openingAmount;

		ostringstream interestCell;
		interestCell << "$" << fixed << setprecision(2) << yearlyInterest;

		cout << setw(6) << year
		     << setw(20) << balanceCell.str()
		     << setw(26) << interestCell.str()
		     << endl;
	}

	cout << endl;
}
