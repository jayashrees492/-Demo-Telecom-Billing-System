#include "main.h"
#include "add.c"
#include "call.c"
#include "display.c"





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
