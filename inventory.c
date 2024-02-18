#include <stdio.h>
#include <string.h>
#include "inventory.h"
#include "player.h"
#include "items.h"

#define maxItem 20

void addItem(Player *player, Items item, int quantity){
    if (player == NULL) {
        printf("Error: Inventory does not exist.\n");
        return;
    }
    if (quantity <= 0) {
        printf("Error: Invalid quantity to add.\n");
        return;
    }
    int added = 0;
    for (int i = 0; i < maxItem; i++) {
        if (player->numberItems < maxItem && (player->objets[i] == item || player->numberItems == 0)) {
            player->objets[i] = item;
            player->numberItems += quantity;
            added = 1;
            printf("Item successfully added.\n");
            break;
        }
    }
    if (!added) {
        printf("Error: Inventory full, unable to add item.\n");
    }
}

void removeItem(PlayerInventory *inventory, Items item, int quantity){
    if (inventory == NULL){
        printf("Error : Inventory does not exist.\n");
        return;
    }
    if (quantity <= 0){
        printf("Error : Invalid quantity to remove.\n");
        return;
    }
    int removed = 0;
    for (int i = 0; i < max_items; i++){
        if (inventory->itemsCounts[i] != 0 && inventory->items[i] == item){
            if (inventory->itemsCounts[i] >= quantity){
                inventory->itemsCounts[i] -= quantity;
                removed = 1;
                printf("Item successfuly removed.\n");
                break;
            } else {
                printf("Error : Not enough items to remove.\n");
                return;
            }
        }
    }
    if (!removed){
        printf("Error : Item not found in inventory.\n");
    }
}

void addSupemon(Player *player, Supemon newSupemon) {
    if (player->numberSupemons < maxSize) {
        if (player->numberDeckSupemons < deckSize) {
            player->deckSupemons[player->numberDeckSupemons++] = newSupemon;
            printf("Supemon successfully added to the deck.\n");
        } else {
            player->collectionSupemons[player->numberSupemons++] = newSupemon;
            printf("Deck is full. Supemon successfully added to the collection.\n");
        }
    } else {
        printf("Error: Both deck and collection are full, unable to add new Supemon.\n");
    }
}

void removeSupemon(Player *player, Supemon supemon) {
    if (player == NULL) {
        printf("Error: Player does not exist.\n");
        return;
    }
    int removed = 0;
    for (int i = 0; i < player->numberSupemons; i++) {
        if (strcmp(player->collectionSupemons[i].name, supemon.name) == 0) {
            for (int j = i; j < player->numberSupemons - 1; j++) {
                player->collectionSupemons[j] = player->collectionSupemons[j + 1];
            }
            player->numberSupemons--;
            removed = 1;
            printf("Supemon successfully removed from the collection.\n");
            break;
        }
    }
    if (!removed) {
        printf("Error: Supemon not found in collection.\n");
    }
}
