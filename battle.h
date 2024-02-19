//
// Created by Elise on 18/02/2024.
//

#ifndef SUPEMON_BATTLE_H
#define SUPEMON_BATTLE_H

#include "supemon.h"
#include "player.h"


void supemonAttack(Supemon *attacker, Supemon *defender);
void supemonBattle(Supemon *supemon1, Supemon *supemon2);
void affichage(Supemon *supemon1, Supemon *supemon2, Player *player);

#endif
