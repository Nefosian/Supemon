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
            increaseStats(supemon);
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