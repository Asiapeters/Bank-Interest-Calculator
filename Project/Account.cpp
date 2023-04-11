#include "Account.h"

/*
* Calculates end of the year balance and interest
* @param interestAmount, the interestAmount that accrued over the year
* @param finalAmount, the current balance
* @param hasMonthlyDeposits, determines if calculation includes monthly deposits
*/
void Account::CalculateInterest(double& t_interestAmount, double& t_finalAmount, bool t_hasMonthlyDeposits) {
    t_interestAmount = 0.0;
    for (int month = 1; month <= 12; ++month) {
        if (t_hasMonthlyDeposits) {
            t_finalAmount += m_monthlyDeposit;
        }
        double monthlyInterest = t_finalAmount * ((m_annualInterest / 100.0) / 12.0);
        t_interestAmount += monthlyInterest;
        t_finalAmount += monthlyInterest;
    }
}

/**
* Prints the calculated results of each years investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
void Account::PrintDetails(int year, double yearEndBalance, double interestEarned) {
    cout << setfill(' ');
    cout << fixed << setprecision(2);
    cout  << setw(7) << right << year;
    cout << setw(20) << "";
    cout << setfill(' ');
    cout << "$" << setw(4) << left << yearEndBalance;
    if (yearEndBalance < 10) {
        cout << setw(23) << "";
        
    }
    else if (yearEndBalance < 100) {
        cout << setw(22) << "";
    }
    else if (yearEndBalance < 1000) {
        cout << setw(21) << "";
    }
    else {
        cout << setw(20) << "";
    }
    
    cout << "$" << setw(4) << left << interestEarned << endl;
}

/*
* Prints the header of the year investment details
* @param title, title of header
*/
void Account::PrintHeader(string title) {
    cout << endl;
    cout << setfill(' ');
    cout << setw(64) << title << endl;
    cout << setfill('=') << setw(72) << "" << endl;

    cout << setfill(' ');
    cout << setw(4) << "" << "Year" << setw(15) << "";
    cout << "Year End Balance" << setw(12) << "";
    cout << "Year End Interest" << endl;
    cout << setfill('-') << setw(72) << "" << endl;

}

/*
* Requests financial information from user
*/
void Account::UserInputAndValidation(void) {
    // Header
    cout << setfill('*') << setw(34) << "" << endl;
    cout << setw(10) << "" << " Data Input " << setw(12) << "" << endl;

    // Requests information from user and validates input
    do {
        cout << "Intitial Investment Amount: ";
        cin >> m_initialInvestmentAmount;
    } while (m_initialInvestmentAmount < 0);
    
    do {
        cout << "Monthly Deposit: ";
        cin >> m_monthlyDeposit;
    } while (m_monthlyDeposit < 0);
    
    do {
        cout << "Annual Interest: ";
        cin >> m_annualInterest;
    } while (m_annualInterest < 0);
 
    do {
        cout << "Number of years: ";
        cin >> m_years;
    } while (m_years < 1);

    // Waits for input from user
    cout << "Press any key to continue . . ." << endl;
    cin.get();

}

/**
 * Calculates and returns an end of year balance for given number of years
 */
void Account::DisplayNoMonthly(void) {
    double currentBalance = m_initialInvestmentAmount;
    double currentInterest = 0.0;

    // For each year, the end of the year balance and interest is displayed
    PrintHeader("Balance and Interest Without Additional Monthly Deposits");
    for (int currentYear = 1; currentYear <= m_years; ++currentYear) {
        CalculateInterest(currentInterest, currentBalance, false);
        PrintDetails(currentYear, currentBalance, currentInterest);
    }

}

/**
 * Calculates and returns an end of year balance for a given number of years including monthly deposits
 */
void Account::DisplayWithMonthly(void) {
    double currentBalance = m_initialInvestmentAmount;
    double currentInterest = 0.0;

    PrintHeader("Balance and Interest With Additional Monthly Deposits");
    // For each year, the end of the year balance and interest is displayed
    for (int currentYear = 1; currentYear <= m_years; ++currentYear) {
        CalculateInterest(currentInterest, currentBalance, true);
        PrintDetails(currentYear, currentBalance, currentInterest);
    }

}
