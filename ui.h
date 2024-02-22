//
// Created by Elise on 16/02/2024.
//

#ifndef SUPEMON_UI_H
#define SUPEMON_UI_H

#include "player.h"
#include "items.h"
#include "deck.h"

void initializePlayer(Player *player);
void startNewGame(Player *player);
void loadGame(Player *player);
void welcomeScreen(Player *player);
void resetPlayer(Player *player);
void itemNameChoose(Items item, char* outName);
Items itemNameToEnum(const char* itemName);

#endif
