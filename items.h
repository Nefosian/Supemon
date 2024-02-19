//
// Created by Elise on 16/02/2024.
//

#ifndef SUPEMON_ITEMS_H
#define SUPEMON_ITEMS_H

typedef enum{
    EmptySlot,
    Potion,
    SuperPotion,
    RareCandy,
    Supeball,
    SuperSupeball,
    NetBall,
}Items;

typedef struct {
    Items itemName[80];
    int price;
    int quantity;
    int maxQuantity[5];
} Shop;


#endif
