#include <iostream>
#include <string>

using namespace std;

int main()
{
    string username, enteredPin, pin = "1234"; // Hardcoded PIN
    double balance = 1000.00;                  // Initial balance
    int choice;
    int attempts = 0;      // Track login attempts
    bool loggedIn = false; // Login status

    // Ask for username
    cout << "Enter your username: ";
    cin >> username;

    // Login process
    while (attempts < 3)
    {
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin)
        {
            loggedIn = true;
            cout << "Login successful!" << endl;
            break; // Exit the loop if login is successful
        }
        else
        {
            attempts++;
            cout << "Invalid PIN. You have " << (3 - attempts) << " attempts left." << endl;
        }
    }

    // If login failed 3 times, exit the program
    if (!loggedIn)
    {
        cout << "Too many failed attempts. Exiting program." << endl;
        return 0;
    }

    // Menu options after successful login
    while (loggedIn)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Your current balance is: $" << balance << endl;
            break;
        }
        case 2:
        {
            double deposit;
            cout << "Enter amount to deposit: $";
            cin >> deposit;
            if (deposit > 0)
            {
                balance += deposit;
                cout << "Deposit successful! Your new balance is: $" << balance << endl;
            }
            else
            {
                cout << "Invalid deposit amount!" << endl;
            }
            break;
        }
        case 3:
        {
            double withdraw;
            cout << "Enter amount to withdraw: $";
            cin >> withdraw;
            if (withdraw <= balance && withdraw > 0)
            {
                balance -= withdraw;
                cout << "Withdrawal successful! Your new balance is: $" << balance << endl;
            }
            else if (withdraw > balance)
            {
                cout << "Insufficient funds. Your current balance is: $" << balance << endl;
            }
            else
            {
                cout << "Invalid withdrawal amount!" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Logging out..." << endl;
            loggedIn = false;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
