#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


struct Transaction {
    char description[100];
    float amount;
};

struct PocketMoney {
    float budget;
    float expenses;
    float savings;
    struct Transaction transactions[100];
    int transactionCount;
};


void initialize(struct PocketMoney *pocket) {
    printf("Enter your budget for the month: ");
    scanf("%f", &pocket->budget);
    pocket->expenses = 0.0;
    pocket->savings = 0.0;
    pocket->transactionCount = 0;
}

void spend(struct PocketMoney *pocket) {
    float amount;
    printf("Enter amount spent: ");
    scanf("%f", &amount);
    if (amount <= pocket->budget - pocket->expenses) {
        pocket->expenses += amount;
        printf("Expense recorded.");
        printf("Enter a brief description for this expense: ");
        getchar(); // Clear newline from buffer
        fgets(pocket->transactions[pocket->transactionCount].description, sizeof(pocket->transactions[pocket->transactionCount].description), stdin);
        pocket->transactions[pocket->transactionCount].amount = amount;
        pocket->transactionCount++;
    } else {
        printf("Exceeds the budget! Cannot spend more.");
    }
}



void save(struct PocketMoney *pocket) {
    float amount;
    printf("Enter amount saved: ");
    scanf("%f", &amount);
    if (amount <= pocket->expenses) {
        pocket->savings += amount;
        pocket->expenses -= amount;
        printf("Savings recorded.");
        printf("Enter a brief description for this savings: ");
        getchar(); // Clear newline from buffer
        fgets(pocket->transactions[pocket->transactionCount].description, sizeof(pocket->transactions[pocket->transactionCount].description), stdin);
        pocket->transactions[pocket->transactionCount].amount = -amount; // Negative amount denotes savings
        pocket->transactionCount++;
    } else {
        printf("Cannot save more than expenses!");
    }
}



void display(struct PocketMoney *pocket) {
    printf("Pocket Money Management:");
    printf("----------------------------");
    printf("Budget: %.2f", pocket->budget);
    printf("Expenses: %.2f", pocket->expenses);
    printf("Savings: %.2f", pocket->savings);
    printf("----------------------------");
}


void showTransactions(struct PocketMoney *pocket) {
    printf("Transactions History:");
    printf("----------------------------");
    for (int i = 0; i < pocket->transactionCount; ++i) {
        printf("Description: %sAmount: %.2f", pocket->transactions[i].description, pocket->transactions[i].amount);
    }
    printf("----------------------------");
}



void setReminder() {
    // Function to set a reminder for the end of the month
    time_t now;
    struct tm endOfMonth;
    time(&now);
    endOfMonth = *localtime(&now);

    endOfMonth.tm_mon += 1; // Increase month by 1
    endOfMonth.tm_mday = 1; // Set day to the first day of next month
    endOfMonth.tm_hour = 0; // Set time to midnight
    endOfMonth.tm_min = 0;
    endOfMonth.tm_sec = 0;

    mktime(&endOfMonth); // Normalize the time structure

    printf("Reminder: Reset the budget by the end of the month!");
    printf("The end of the month is on: %s", asctime(&endOfMonth));
}



int main() {
    struct PocketMoney pocket;
    int choice;

    initialize(&pocket);

    do {
        printf("Pocket Money Menu:");
        printf("1. Spend Money");
        printf("2. Save Money");
        printf("3. Display Details");
        printf("4. Show Transactions");
        printf("5. Set Reminder");
        printf("6. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                spend(&pocket);
                break;
            case 2:
                save(&pocket);
                break;
            case 3:
                display(&pocket);
                break;
            case 4:
                showTransactions(&pocket);
                break;
            case 5:
                setReminder();
                break;
            case 6:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.");
        }
    } while (choice != 6);

    return 0;
}




