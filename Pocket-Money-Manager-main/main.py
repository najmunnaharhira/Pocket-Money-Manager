import datetime



class PocketMoney:
    def __init__(self):
        self.budget = 0.0
        self.expenses = 0.0
        self.savings = 0.0
        self.transactions = []

    def initialize(self):
        self.budget = float(input("Enter your budget for the month: "))

    def spend(self):
        amount = float(input("Enter amount spent: "))
        if amount <= self.budget - self.expenses:
            self.expenses += amount
            print("Expense recorded.")
            description = input("Enter a brief description for this expense: ")
            self.transactions.append((description, amount))
        else:
            print("Exceeds the budget! Cannot spend more.")

    def save(self):
        amount = float(input("Enter amount saved: "))
        if amount <= self.expenses:
            self.savings += amount
            self.expenses -= amount
            print("Savings recorded.")
            description = input("Enter a brief description for this savings: ")
            self.transactions.append((description, -amount))  # Negative amount denotes savings
        else:
            print("Cannot save more than expenses!")


    def display(self):
        print("Pocket Money Management:")
        print("----------------------------")
        print(f"Budget: {self.budget}")
        print(f"Expenses: {self.expenses}")
        print(f"Savings: {self.savings}")
        print("----------------------------")



    def show_transactions(self):
        print("Transactions History:")
        print("----------------------------")
        for description, amount in self.transactions:
            print(f"Description: {description}, Amount: {amount}")
        print("----------------------------")

    def set_reminder(self):
        now = datetime.datetime.now()
        next_month = now.month + 1 if now.month < 12 else 1  # Increment month, reset to 1 in January
        next_year = now.year + 1 if now.month == 12 else now.year  # Increment year if December
        
        end_of_month = now.replace(day=1, month=next_month, year=next_year, hour=0, minute=0, second=0)
        print("Reminder: Reset the budget by the end of the month!")
        print(f"The end of the month is on: {end_of_month}")
        


if __name__ == "__main__":
    pocket = PocketMoney()
    pocket.initialize()

    while True:
        print("Pocket Money Menu:")
        print("1. Spend Money")
        print("2. Save Money")
        print("3. Display Details")
        print("4. Show Transactions")
        print("5. Set Reminder")
        print("6. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            pocket.spend()
        elif choice == '2':
            pocket.save()
        elif choice == '3':
            pocket.display()
        elif choice == '4':
            pocket.show_transactions()
        elif choice == '5':
            pocket.set_reminder()
        elif choice == '6':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")




