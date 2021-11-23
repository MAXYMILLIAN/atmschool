// ConsoleATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

std::string PIN;
std::string savedPIN;
std::string YN;
int run; // do we still run?
int failedCount;
int EXIT_FAILED_NUMBER; // after which fail we want to quit
int accountBalance;
int moneyToGet;
int loggedIn;

int main() {
    //bankomat 1

    // iniatilize variables
    run = 1;
    failedCount = 0;
    EXIT_FAILED_NUMBER = 3;
    loggedIn = 0;

    // saved PIN
    savedPIN = "4321";

    // initial account balance
    accountBalance = 10000;

    //ask if we want to start
    std::cout << "Welcome to ATM!\n\n";
    std::cout << "Do you want to input your PIN? y/n\n";
    std::cin >> YN;

    if (YN == "n") {
        exit;
    }

    while (run) {

        if (loggedIn == 0) {
            // read PIN from input
            std::cout << "Enter PIN\n";
            std::cout << "PIN = ";
            std::cin >> PIN;

            // compare PIN with saved PIN
            if (PIN == savedPIN) {
                // ok, access granted
                std::cout << "Access grated\n";
                failedCount = 0;
                loggedIn = 1;
            }
        }
        
        // if user is logged in
        if (loggedIn == 1) {

            std::cout << "Your account balance: ";
            std::cout << accountBalance;
            std::cout << " PLN";
            std::cout << "\n\n";

            // you can get your money out
            std::cout << "Please specify amount to withdrawn\n";
            std::cout << "amount in PLN = ";
            std::cin >> moneyToGet;


            // check if client has enough money
            if (accountBalance - moneyToGet < 0) {
                // you don't have enough money
                std::cout << "Not enough money!\n\n";                
            }
            else {
                accountBalance = accountBalance - moneyToGet;    
            }            

            std::cout << "Your account balance: ";
            std::cout << accountBalance;
            std::cout << " PLN";
            std::cout << "\n\n";

            // reset YN variable
            YN = "";
            // stay in the loop if user put anything other than y or n
            while (YN != "y" && YN != "n") {
                std::cout << "Do you want to withdraw more money y/n?\n\n";
                std::cin >> YN;

                if (YN == "n") {
                    // set run to 0 so exit while loop
                    run = 0;
                }
            }

        }
        else {
            // if failed, increase failed attempts variable
            failedCount++;
            std::cout << "Wrong PIN put ";
            std::cout << failedCount;
            std::cout << " times";
            std::cout << " \n\n";
        }

        //exit if too many
        if (failedCount >= EXIT_FAILED_NUMBER) {

            std::cout << "To many failed attempts reached!\n";
            std::cout << "Card blocked!\n";
            std::cout << "Press any key to exit\n";
            std::cin;

            //exit while loop
            run = 0;
        }
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
