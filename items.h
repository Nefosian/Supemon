//
// Created by Elise on 16/02/2024.
//


#ifndef SUPEMON_ITEMS_H
#define SUPEMON_ITEMS_H

#define EmptySlot 0
#define maxItem 20 

typedef enum{
    Potion,
    SuperPotion,
    RareCandy,
    Supeball,
    SuperSupeball,
    NetBall,
}Items;

typedef struct{
    Items item;
    int quantity;
}Item_quantity;


#endif
