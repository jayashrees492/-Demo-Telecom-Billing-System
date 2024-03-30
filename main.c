#include <stdio.h>

#define MAX_CUSTOMERS 100

// Function to add a new customer
void addCustomer(int ids[], char names[][50], char phoneNumbers[][15], float balances[], int *numCustomers) {
    int id = *numCustomers + 1;
    
    printf("Enter customer name: ");
    scanf("%s", names[*numCustomers]);
    printf("Enter customer phone number: ");
    scanf("%s", phoneNumbers[*numCustomers]);
    balances[*numCustomers] = 0; // Initial balance
    
    ids[*numCustomers] = id;
    (*numCustomers)++;
    printf("Customer added successfully!\n");
}

// Function to make a call and update balance
void makeCall(int ids[], float balances[], int numCustomers) {
    int customerId, callDuration;
    
    printf("Enter customer ID: ");
    scanf("%d", &customerId);
    
    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }
    printf("Enter call duration in minutes: ");
    scanf("%d", &callDuration);
    
    float callCost = callDuration * 0.50; // Assuming rate per minute is $0.50
    balances[customerId - 1] += callCost;
    printf("Call made successfully!\n");
}

// Function to display customer information
void displayCustomerInfo(int ids[], char names[][50], char phoneNumbers[][15], float balances[], int numCustomers) {
    int customerId;
    
    printf("Enter customer ID: ");
    scanf("%d", &customerId);
    
    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }
    printf("Customer ID: %d\n", ids[customerId - 1]);
    printf("Name: %s\n", names[customerId - 1]);
    printf("Phone Number: %s\n", phoneNumbers[customerId - 1]);
    printf("Balance: $%.2f\n", balances[customerId - 1]);
}

int main() {
    int customerIds[MAX_CUSTOMERS];
    char customerNames[MAX_CUSTOMERS][50];
    char customerPhoneNumbers[MAX_CUSTOMERS][15];
    float customerBalances[MAX_CUSTOMERS];
    int numCustomers = 0, choice;
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
                addCustomer(customerIds, customerNames, customerPhoneNumbers, customerBalances, &numCustomers);
                break;
            case 2:
                makeCall(customerIds, customerBalances, numCustomers);
                break;
            case 3:
                displayCustomerInfo(customerIds, customerNames, customerPhoneNumbers, customerBalances, numCustomers);
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
