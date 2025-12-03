#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "input.h"

struct Item items[MAX_ITEMS];
int itemCount = 0;

void showMenu() {
    printf("\n--------------- MAIN MENU ---------------\n");
    printf("1. Add new item\n");
    printf("2. Display all items\n");
    printf("3. Buy items (Billing)\n");
    printf("4. Search by ID\n");
    printf("5. Search by Name\n");
    printf("6. Update item\n");
    printf("7. Delete item\n");
    printf("8. Exit\n");
    printf("-----------------------------------------\n");
}


void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\nCannot add more items.\n");
        return;
    }

    struct Item newItem;
    newItem.id = itemCount + 1;

    printf("\nEnter item name: ");
    readString(newItem.name, sizeof(newItem.name));

    printf("Enter price: ");
    newItem.price = readFloat();

    printf("Enter quantity: ");
    newItem.quantity = readInt();

    items[itemCount] = newItem;
    itemCount++;

    printf("\nItem added successfully! ID = %d\n", newItem.id);
}

void displayItems() {
    if (itemCount == 0) {
        printf("\nNo items found.\n");
        return;
    }

    printf("\n----------- ITEMS IN MALL -----------\n");
    printf("ID\tName\t\t\tPrice\tQuantity\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%-20s\t%.2f\t%d\n",
               items[i].id,
               items[i].name,
               items[i].price,
               items[i].quantity);
    }
}

void buyItems() {
    if (itemCount == 0) {
        printf("\nNo items available.\n");
        return;
    }

    displayItems();
    float total = 0.0f;

    while (1) {
        printf("\nEnter ID to buy (0 to finish): ");
        int id = readInt();
        if (id == 0) break;

        int index = -1;
        for (int i = 0; i < itemCount; i++) {
            if (items[i].id == id) { index = i; break; }
        }
        if (index == -1) { printf("Invalid ID. Try again.\n"); continue; }

        printf("Enter quantity: ");
        int qty = readInt();
        if (qty <= 0) { printf("Quantity must be positive.\n"); continue; }
        if (qty > items[index].quantity) {
            printf("Only %d available. Try smaller quantity.\n", items[index].quantity);
            continue;
        }

        total += items[index].price * qty;
        items[index].quantity -= qty;
        printf("Added %d x %s to bill.\n", qty, items[index].name);
    }

    printf("\nTotal bill = %.2f\n", total);
    if (total >= 1000.0f) {
        float discount = total * 0.10f;
        printf("Discount 10%% = %.2f\n", discount);
        total -= discount;
    }
    printf("Final amount to pay: %.2f\n", total);
    printf("Thank you for shopping!\n");
}

void searchById() {
    if (itemCount == 0) { printf("\nNo items available.\n"); return; }

    printf("\nEnter ID to search: ");
    int id = readInt();

    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            printf("\nItem Found:\nID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n",
                   items[i].id, items[i].name, items[i].price, items[i].quantity);
            return;
        }
    }
    printf("\nNo item found with this ID.\n");
}

void searchByName() {
    if (itemCount == 0) { printf("\nNo items available.\n"); return; }

    char name[50];
    printf("\nEnter name to search: ");
    readString(name, sizeof(name));

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            if (!found) {
                printf("\nSearch results:\n");
                printf("ID\tName\t\t\tPrice\tQuantity\n");
                printf("-------------------------------------\n");
            }
            printf("%d\t%-20s\t%.2f\t%d\n",
                   items[i].id, items[i].name, items[i].price, items[i].quantity);
            found = 1;
        }
    }
    if (!found) printf("No item found with that name.\n");
}

void updateItem() {
    if (itemCount == 0) { printf("\nNo items available.\n"); return; }

    printf("\nEnter ID of item to update: ");
    int id = readInt();

    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            printf("\nEnter new name (leave empty to keep current): ");
            char temp[50];
            readString(temp, sizeof(temp));
            if (strlen(temp) > 0) strcpy(items[i].name, temp);

            printf("Enter new price (0 to keep current): ");
            float p = readFloat();
            if (p > 0) items[i].price = p;

            printf("Enter new quantity (-1 to keep current): ");
            int q = readInt();
            if (q >= 0) items[i].quantity = q;

            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void deleteItem() {
    if (itemCount == 0) { printf("\nNo items available.\n"); return; }

    printf("\nEnter ID to delete: ");
    int id = readInt();

    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];
                items[j].id = j + 1;
            }
            itemCount--;
            printf("Item deleted successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}
