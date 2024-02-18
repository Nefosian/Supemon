#include "items.h"
#include "supemon.h"

#define max_supemons 300
#define max_items 20

typedef struct{
    Items items[max_items];
    int itemsCounts[max_items];
    Supemon supemons[max_supemons]; 
} PlayerInventory;

void addItem(PlayerInventory *inventory, Items item, int quantity);
void removeItem(PlayerInventory *inventory, Items item, int quantity);
void addSupemon(PlayerInventory *inventory, Supemon supemon);
void removeSupemon(PlayerInventory *inventory, Supemon supemon);
void displayInventory(PlayerInventory *inventory);
