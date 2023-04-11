#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

#ifndef PROJECTTWO_ACCOUNT_H_
#define PROJECTTWO_ACCOUNT_H_
/*
* Creates a table for the end of the year balance and interest of the account
*/
class Account {
	private:
		int m_years;
		double m_initialInvestmentAmount;
		double m_monthlyDeposit;
		double m_annualInterest;
		void CalculateInterest(double& t_interestAmount, double& t_finalAmount, bool t_hasMonthlyDeposits);
		void PrintDetails(int t_year, double t_yearEndBalance, double t_interestEarned);
		void PrintHeader(string t_title);

	public:
		void UserInputAndValidation(void);
		void DisplayNoMonthly(void);
		void DisplayWithMonthly(void);
		
		
};
#endif
