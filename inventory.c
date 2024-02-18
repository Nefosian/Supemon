#include <stdio.h>
#include <string.h>
#include "player.h"
#include "items.h"
#include "inventory.h"

void addItem(PlayerInvotory *inventory, Items item, int quantity){
    if (inventory == NULL){
        printf("Error : Inventory does not exist.\n");
        return;
    }
    if (quantity <= 0){
        printf("Error : Invalid quantity to add.\n");
        return;
    }
    int added = 0;
    for (int i = 0; i < max_items; i++){
        if (inventory->itemsCounts[i] == 0 || inventory->items[i] == item){
            inventory->items[i] = item;
            inventory->itemsCounts[i] += quantity;
            added = 1;
            printf("Item successfuly added.\n");
            break; 
        }
    }
    if (!added){
            printf("Error : Inventory full, unable to add item.\n");
    }
}

