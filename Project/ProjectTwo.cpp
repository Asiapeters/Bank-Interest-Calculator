/*
* This program requests user to enter investment information to calculate the interest rate for a set amount of years
* and formats information into a table
* 
* Author:  Asia Peters
* Date:    Apri 2, 2023
* Version: 1.0
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Account.h"

using namespace std;

/*
* Prints monthly and no monthly end of the year reports and resets formatting of console
*/
void printReports(ios& currentState, Account account) {
    account.DisplayNoMonthly();
    cout.copyfmt(currentState);
    account.DisplayWithMonthly();
    cout.copyfmt(currentState);
}

int main() {
    char userInput = 'Y';
    Account account;
    ios state(nullptr);

    // Requests information from the user until user decides to end the program
    do {
        if (userInput == 'y' || userInput == 'Y') {
            account.UserInputAndValidation();
            printReports(state, account);
        }

        cout << endl << "Would you like to try different values? (Y / N): ";
        cin >> userInput;
        cout << endl;

    } while (userInput != 'N' && userInput != 'n');

    return 0;
}
