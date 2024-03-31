#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a customer
struct Customer {
    int id;
    char name[50];
    char phoneNumber[15];
    float balance;
};

// Function to add a new customer
void addCustomer(struct Customer customers[], int *numCustomers) {
    struct Customer newCustomer;
    newCustomer.id = *numCustomers + 1;

    printf("Enter customer name: ");
    scanf("%s", newCustomer.name);
    printf("Enter customer phone number: ");
    scanf("%s", newCustomer.phoneNumber);
    newCustomer.balance = 0; // Initial balance

    customers[*numCustomers] = newCustomer;
    (*numCustomers)++;

    printf("Customer added successfully!\n");
}

// Function to make a call and update balance
void makeCall(struct Customer customers[], int numCustomers) {
    int customerId;
    int callDuration;

    printf("Enter customer ID: ");
    scanf("%d", &customerId);

    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }

    printf("Enter call duration in minutes: ");
    scanf("%d", &callDuration);

    float callCost = callDuration * 0.50; // Assuming rate per minute is $0.50
    customers[customerId - 1].balance += callCost;

    printf("Call made successfully!\n");
}

// Function to display customer information
void displayCustomerInfo(struct Customer customers[], int numCustomers) {
    int customerId;

    printf("Enter customer ID: ");
    scanf("%d", &customerId);

    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }

    struct Customer customer = customers[customerId - 1];
    printf("Customer ID: %d\n", customer.id);
    printf("Name: %s\n", customer.name);
    printf("Phone Number: %s\n", customer.phoneNumber);
    printf("Balance: $%.2f\n", customer.balance);
}

int main() {
    struct Customer customers[100]; // Assuming maximum 100 customers
    int numCustomers = 0;
    int choice;

    do {
        printf("\nTelecom Billing System\n");
        printf("1. Add new customer\n");
        printf("2. Make a call\n");
        printf("3. Display customer information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCustomer(customers, &numCustomers);
                break;
            case 2:
                makeCall(customers, numCustomers);
                break;
            case 3:
                displayCustomerInfo(customers, numCustomers);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}

