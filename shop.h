//
// Created by Elise on 16/02/2024.
//

#ifndef SUPEMON_SHOP_H
#define SUPEMON_SHOP_H

#include "items.h"
#include "player.h"

typedef struct {
    Items type;
    int buy;
    int resell;
} Shop;

void shop(Player *player);
void Buy(Player *player, Items item, Items price, char temp[256], char response);
void verify(char temp[], char response, Player *player);
#endif

