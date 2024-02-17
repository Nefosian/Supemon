//
// Created by Elise on 16/02/2024.
//

#ifndef SUPEMON_PLAYER_H
#define SUPEMON_PLAYER_H

#include "supemon.h"
#include "items.h"

#define maxSize 300 // Paul ici, c' est pour le nombre total de supemon qu'il peut avoir
#define deckSize 6 // Paul ici, c' est pour le nombre de supemon actif dans son deck, comme le vrai jeu pokemon quoi, max 6
#define maxItem 20 // Paul ici, c' est pour le nombre total d'item dans l'inventaire

typedef struct{
    char name[80];
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
