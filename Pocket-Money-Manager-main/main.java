import java.util.Scanner;

class Transaction {
    String description;
    float amount;
}

class PocketMoney {
    float budget;
    float expenses;
    float savings;
    Transaction[] transactions;
    int transactionCount;

    public PocketMoney() {
        transactions = new Transaction[100];
        transactionCount = 0;
    }
}

public class PocketMoneyManagement {

    static Scanner scanner = new Scanner(System.in);

    public static void initialize(PocketMoney pocket) {
        System.out.print("Enter your budget for the month: ");
        pocket.budget = scanner.nextFloat();
        pocket.expenses = 0.0f;
        pocket.savings = 0.0f;
        pocket.transactionCount = 0;
    }

    public static void spend(PocketMoney pocket) {
        System.out.print("Enter amount spent: ");
        float amount = scanner.nextFloat();
        scanner.nextLine(); // Consume newline
        if (amount <= pocket.budget - pocket.expenses) {
            pocket.expenses += amount;
            System.out.println("Expense recorded.");
            System.out.print("Enter a brief description for this expense: ");
            String description = scanner.nextLine();
            pocket.transactions[pocket.transactionCount] = new Transaction();
            pocket.transactions[pocket.transactionCount].description = description;
            pocket.transactions[pocket.transactionCount].amount = amount;
            pocket.transactionCount++;
        } else {
            System.out.println("Exceeds the budget! Cannot spend more.");
        }
    }

    public static void save(PocketMoney pocket) {
        System.out.print("Enter amount saved: ");
        float amount = scanner.nextFloat();
        scanner.nextLine(); // Consume newline
        if (amount <= pocket.expenses) {
            pocket.savings += amount;
            pocket.expenses -= amount;
            System.out.println("Savings recorded.");
            System.out.print("Enter a brief description for this savings: ");
            String description = scanner.nextLine();
            pocket.transactions[pocket.transactionCount] = new Transaction();
            pocket.transactions[pocket.transactionCount].description = description;
            pocket.transactions[pocket.transactionCount].amount = -amount; // Negative amount denotes savings
            pocket.transactionCount++;
        } else {
            System.out.println("Cannot save more than expenses!");
        }
    }

    public static void display(PocketMoney pocket) {
        System.out.println("Pocket Money Management:");
        System.out.println("----------------------------");
        System.out.println("Budget: " + pocket.budget);
        System.out.println("Expenses: " + pocket.expenses);
        System.out.println("Savings: " + pocket.savings);
        System.out.println("----------------------------");
    }

    public static void showTransactions(PocketMoney pocket) {
        System.out.println("Transactions History:");
        System.out.println("----------------------------");
        for (int i = 0; i < pocket.transactionCount; ++i) {
            System.out.println("Description: " + pocket.transactions[i].description);
            System.out.println("Amount: " + pocket.transactions[i].amount);
        }
        System.out.println("----------------------------");
    }

    public static void setReminder() {
        // Function to set a reminder for the end of the month
        // You can implement this part in Java using the available date/time classes
        System.out.println("Reminder: Reset the budget by the end of the month!");
        // Implement the rest of the logic here for setting the reminder
    }

    public static void main(String[] args) {
        PocketMoney pocket = new PocketMoney();
        int choice;

        initialize(pocket);

        do {
            System.out.println("Pocket Money Menu:");
            System.out.println("1. Spend Money");
            System.out.println("2. Save Money");
            System.out.println("3. Display Details");
            System.out.println("4. Show Transactions");
            System.out.println("5. Set Reminder");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    spend(pocket);
                    break;
                case 2:
                    save(pocket);
                    break;
                case 3:
                    display(pocket);
                    break;
                case 4:
                    showTransactions(pocket);
                    break;
                case 5:
                    setReminder();
                    break;
                case 6:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 6);
    }
}

