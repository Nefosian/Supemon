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
void run_away(Supemon *attacker, Supemon *defender);
void capture(Supemon *attacker, Supemon *defender, Player *player, float chance_ball);
void check_ball(Supemon *attacker, Supemon *defender, Player *player, char response, int choice_ball);
void fct_for_item(Player *player, Supemon *defender, Items item);
void item_use(Player *player, char response, int choice_item, Supemon *defender);
void changeSup(Player *player, int choice_supermon);
void affichage(Supemon *attacker, Supemon *defender, Player *player);

#endif //SUPEMON_BATTLE_H