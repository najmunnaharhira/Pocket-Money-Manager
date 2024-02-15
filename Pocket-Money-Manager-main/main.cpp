#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;



struct Transaction {
    string description;
    float amount;
};

class PocketMoney {
private:
    float budget;
    float expenses;
    float savings;
    vector<Transaction> transactions;


public:
    PocketMoney() {
        budget = 0.0;
        expenses = 0.0;
        savings = 0.0;
    }

    void initialize() {
        cout << "Enter your budget for the month: ";
        cin >> budget;
    }
    

    void spend() {
        float amount;
        cout << "Enter amount spent: ";
        cin >> amount;

        if (amount <= budget - expenses) {
            expenses += amount;
            cout << "Expense recorded." << endl;

            Transaction transaction;
            cin.ignore(); // Clear newline from buffer
            cout << "Enter a brief description for this expense: ";
            getline(cin, transaction.description);
            transaction.amount = amount;
            transactions.push_back(transaction);
        } else {
            cout << "Exceeds the budget! Cannot spend more." << endl;
        }
    }

    void save() {
        float amount;
        cout << "Enter amount saved: ";
        cin >> amount;

        if (amount <= expenses) {
            savings += amount;
            expenses -= amount;
            cout << "Savings recorded." << endl;

            Transaction transaction;
            cin.ignore(); // Clear newline from buffer
            cout << "Enter a brief description for this savings: ";
            getline(cin, transaction.description);
            transaction.amount = -amount; // Negative amount denotes savings
            transactions.push_back(transaction);
        } else {
            cout << "Cannot save more than expenses!" << endl;
        }
    }

    void display() {
        cout << "Pocket Money Management:";
        cout << "----------------------------";
        cout << "Budget: " << budget << endl;
        cout << "Expenses: " << expenses << endl;
        cout << "Savings: " << savings << endl;
        cout << "----------------------------";
    }

    void showTransactions() {
        cout << "Transactions History:";
        cout << "----------------------------";
        for (const auto& transaction : transactions) {
            cout << "Description: " << transaction.description << "  Amount: " << transaction.amount << endl;
        }
        cout << "----------------------------";
    }


    void setReminder() {
        time_t now = time(0);
        tm endOfMonth = *localtime(&now);
        
        endOfMonth.tm_mon += 1; // Increase month by 1
        endOfMonth.tm_mday = 1; // Set day to the first day of next month
        endOfMonth.tm_hour = 0; // Set time to midnight
        endOfMonth.tm_min = 0;
        endOfMonth.tm_sec = 0;

        mktime(&endOfMonth); // Normalize the time structure

        cout << "Reminder: Reset the budget by the end of the month!" << endl;
        cout << "The end of the month is on: " << asctime(&endOfMonth);
    }
};


int main() {
    PocketMoney pocket;
    int choice;

    pocket.initialize();

    do {
        cout << "Pocket Money Menu:";
        cout << "1. Spend Money";
        cout << "2. Save Money";
        cout << "3. Display Details";
        cout << "4. Show Transactions";
        cout << "5. Set Reminder";
        cout << "6. Exit";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pocket.spend();
                break;
            case 2:
                pocket.save();
                break;
            case 3:
                pocket.display();
                break;
            case 4:
                pocket.showTransactions();
                break;
            case 5:
                pocket.setReminder();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}


