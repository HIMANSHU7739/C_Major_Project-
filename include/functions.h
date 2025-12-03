// Header for mall management core functions

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ITEMS 100

// Item structure: stores product details
struct Item {
    int id;      // Unique identifier
    char name[50];   // Product name
    float price;     // Unit price
    int quantity;    // Stock quantity
};

// Function declarations
void showMenu();        // Display menu
void addItem();         // Add new item with auto-ID
void displayItems();    // Show all items
void buyItems();        // Process purchase with billing and discount
void searchById();      // Search by ID
void searchByName();    // Search by name (exact match)
void updateItem();      // Update item details
void deleteItem();      // Delete item and maintain array

// Global variables
extern struct Item items[MAX_ITEMS];
extern int itemCount;

#endif
