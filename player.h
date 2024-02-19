//
// Created by Elise on 16/02/2024.
//

#ifndef SUPEMON_PLAYER_H
#define SUPEMON_PLAYER_H

#include "supemon.h"
#include "items.h"

#define maxSize 300 
#define deckSize 6 
#define maxItem 20 

typedef struct{
    char name[80];
    int age;
    Supemon collectionSupemons[maxSize];
    int numberSupemons;
    Supemon deckSupemons[deckSize];
    int numberDeckSupemons;
    Supemon *supemonSelected;
    int supcoins;
    Items objets[maxItem];
    int numberItems;
} Player;

#endif
