#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};

void showMenu();
void addItem();
void displayItems();
void buyItems();
void searchById();
void searchByName();
void updateItem();
void deleteItem();

extern struct Item items[MAX_ITEMS];
extern int itemCount;

#endif
