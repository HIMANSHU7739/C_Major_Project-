//  entry point of Mall Management System

#include <stdio.h>
#include "functions.h"
#include "input.h"

int main() {
    int choice;
    printf("=====================================\n");
    printf("       MALL MANAGEMENT SYSTEM \n");
    printf("=====================================\n");
    
// Main program loop
    while (1) {
        showMenu();
        printf("\nEnter your choice: ");
        choice = readInt();
        
// Process menu selection
        if (choice == 1) addItem();
        else if (choice == 2) displayItems();
        else if (choice == 3) buyItems();
        else if (choice == 4) searchById();
        else if (choice == 5) searchByName();
        else if (choice == 6) updateItem();
        else if (choice == 7) deleteItem();
        else if (choice == 8) {
            printf("\nThank you for using Mall Management System.\n");
            break;
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}
