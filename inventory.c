#include <stdio.h>
#include <string.h>
#include "inventory.h"
#include "player.h"
#include "items.h"

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

void removeItem(Player *player, Items item, int quantity) {
    if (player == NULL) {
        printf("Error: Player does not exist.\n");
        return;
    }
    if (quantity <= 0) {
        printf("Error: Invalid quantity to remove.\n");
        return;
    }
    int removed = 0;
    for (int i = 0; i < maxItem; i++) {
        if (player->objets[i] == item) {
            if (player->numberItems < quantity) {
                printf("Error: Not enough items to remove.\n");
                return;
            }
            removed = 1;
            printf("Item successfully removed.\n");
            for (int j = i; j < player->numberItems - 1; j++) {
                player->objets[j] = player->objets[j + 1];
            }
            player->numberItems--;
            break;
        }
    }
    if (!removed) {
        printf("Error: Item not found in inventory.\n");
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

int hasItem(const Player *player, Items item) {
    for (int i = 0; i < player->numberItems; i++) {
        if (player->objets[i] == item) {
            return 1;
            printf("Item found in inventory.\n"); 
        }
    }
    printf("Item not found in inventory.\n");
    return 0;    
}


int nbitem(const Player *player, Items item) {
    for (int i = 0; i < player->numberItems; i++) {
        if (player->objets[i] == item) {
            return 1;
            printf("You have %d %s.\n", player->numberItems, item); 
            return 0;
        } else {
            printf("You don't have this item in your inventory.\n");
            return 0;  
        }
    }
      
}

void useItem(Player *player, Items item) {
    if (hasItem(player, item)) {
        removeItem(player, item, 1); 
        printf("Item used successfully.\n");
        if (item == Potion) {
            player->supemonSelected->currentLife += 5;
            printf("Supemon healed by 5 HP.\n");
            if (player->supemonSelected->currentLife > player->supemonSelected->maxLife) {
                player->supemonSelected->currentLife = player->supemonSelected->maxLife;
                printf("Supemon reached maximum life.\n");
            }
        } else if (item == SuperPotion) {
            player->supemonSelected->currentLife += 10;
            printf("Supemon's life increased by 10.\n");
            if (player->supemonSelected->currentLife > player->supemonSelected->maxLife) {
                player->supemonSelected->currentLife = player->supemonSelected->maxLife;
                printf("Supemon reached maximum life.\n");
            }
        } else if (item == RareCandy)
        printf("Supemon's level increased by 1.\n");{
            player->supemonSelected->level += 1;
            if (player->supemonSelected->level > 100) {
                player->supemonSelected->level = 100;
                printf("Supemon reached maximum level.\n");
            }            
        }
       
    } else {
        printf("Error: Item not found in inventory, cannot be used.\n");
    }
}
