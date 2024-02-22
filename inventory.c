#include <stdio.h>
#include <string.h>
#include "inventory.h"
#include "player.h"
#include "items.h"

void addItem(Player *player, Items item, int quantity) {
    for (int i = 0; i < player->numberItems; i++) {
        if (player->objets[i].item == item) {
            player->objets[i].quantity += quantity;
            return;
        }
    }
    player->objets[player->numberItems].item = item;
    player->objets[player->numberItems].quantity = quantity;
    player->numberItems++;
}


void removeItem(Player *player, Items item, int quantity) {
    for (int i = 0; i < player->numberItems; i++) {
        if (player->objets[i].item == item) {
            player->objets[i].quantity -= quantity;
            
            if (player->objets[i].quantity < 0)
                player->objets[i].quantity = 0;
            return;
        }
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

int nbitem(const Player *player, Items item) {
    for (int i = 0; i < player->numberItems; i++) {
        if (player->objets[i].item == item) {
            return player->objets[i].quantity;
        }
    }
    return 0;
}

int hasItem(const Player *player, Items item) {
    return nbitem(player, item) > 0;
}





void useItem(Player *player,Supemon *supemon, Items item) {
    if (hasItem(player, item)) {
        printf("Item used successfully.\n");
        if (item == Potion) {
            supemon->currentLife += 5;
            printf("Supemon healed by 5 HP.\n");
            if (supemon->currentLife > supemon->maxLife) {
                supemon->currentLife = supemon->maxLife;
                printf("Supemon reached maximum life.\n");
            }
            return;
        } else if (item == SuperPotion) {
            supemon->currentLife += 10;
            printf("Supemon's life increased by 10.\n");
            if (supemon->currentLife > supemon->maxLife) {
                supemon->currentLife = supemon->maxLife;
                printf("Supemon reached maximum life.\n");
            }
            return; 
        } else if (item == RareCandy) {
            printf("Supemon's level increased by 1.\n");
            supemon->level += 1;
            if (supemon->level > 100) {
                supemon->level = 100;
                printf("Supemon reached maximum level.\n");
            }
            return; 
        }
        removeItem(player, item, 1);

    } else {
        printf("Error: Item not found in inventory, cannot be used.\n");
    }
}
