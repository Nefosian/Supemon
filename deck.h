#ifndef DECK_H
#define DECK_H

#include "player.h"
#include "supemon.h"
#include "inventory.h"

void initializeDeck(Player *player);
void displayDeck(const Player *player);
void addSupemonToDeck(Player *player, Supemon newSupemon);
void replaceSupemonInDeck(Player *player, int deckPosition, Supemon newSupemon);
void removeSupemonFromDeck(Player *player, int deckPosition);

#endif 
