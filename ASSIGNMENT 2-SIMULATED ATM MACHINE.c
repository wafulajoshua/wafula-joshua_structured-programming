#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float balance = 1000.0;
const char stored_pin[] = "1234";

int login() {
    char entered_pin[10];
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter your PIN: ");
        scanf("%s", entered_pin);

        if (strcmp(entered_pin, stored_pin) == 0) {
            printf("Login successful.\n\n");
            return 1;
        } else {
            attempts--;
            printf("Incorrect PIN. Attempts left: %d\n", attempts);
        }
    }

    printf("Access denied. Too many failed attempts.\n");
    return 0;
}

void checkBalance() {
    printf("Your current balance is: KES %.2f\n", balance);
}

void deposit() {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Deposited KES %.2f. New balance: KES %.2f\n", amount, balance);
    } else {
        printf("Deposit amount must be positive.\n");
    }
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
    } else if (amount > balance) {
        printf("Insufficient funds.\n");
    } else {
        balance -= amount;
        printf("Withdrew KES %.2f. New balance: KES %.2f\n", amount, balance);
    }
}

void showMenu() {
    printf("\nATM Menu:\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    if (login()) {
        do {
            showMenu();
            printf("Choose an option (1-4): ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    printf("Thank you for using the ATM. Goodbye!\n");
                    break;
                default:
                    printf("Invalid choice. Please select from 1 to 4.\n");
            }
        } while (choice != 4);
    }

    return 0;
}
