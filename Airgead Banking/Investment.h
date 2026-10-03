// Investment.h
// Class prototype for the Airgead Banking investment calculator.
// Holds the user's investment details and prints year-by-year growth reports.
//
// Author: [Your Name]
// Date:   [Enter date]

#ifndef AIRGEAD_BANKING_INVESTMENT_H_
#define AIRGEAD_BANKING_INVESTMENT_H_

// The Investment class stores the four values the user enters and knows how to
// print a year-end growth report, with or without the monthly deposit.
class Investment
{
public:
	// Build an Investment. Defaults keep the object in a valid state even if no
	// values are supplied yet.
	Investment(double t_initialInvestment = 0.0,
	           double t_monthlyDeposit = 0.0,
	           double t_annualInterestRate = 0.0,
	           int t_numberOfYears = 0);

	// Setters validate their input and throw std::invalid_argument on bad data
	// so the caller can report the problem and re-prompt.
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setAnnualInterestRate(double t_annualInterestRate);
	void setNumberOfYears(int t_numberOfYears);

	// Getters are const because they only observe the data.
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getAnnualInterestRate() const;
	int getNumberOfYears() const;

	// Print one year-end report. When t_includeMonthlyDeposit is false the
	// monthly deposit is treated as zero (the "no additional deposits" report).
	void printReport(bool t_includeMonthlyDeposit) const;

private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterestRate;
	int m_numberOfYears;
};

#endif  // AIRGEAD_BANKING_INVESTMENT_H_
