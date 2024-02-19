//
// Created by Elise on 16/02/2024.
//

#ifndef SUPEMON_SUPEMON_H
#define SUPEMON_SUPEMON_H

#include "move_cat.h"
#include "skill_cat.h"

#define max_moves 4

typedef struct{
    char name[80];
    char type[80];
    char gender[80];
    char weakness[80];
    int level;
    int experience;
    int maxLife;
    int currentLife;
    int Attack;
    int Defense;
    int Dodge;
    int Precision;
    int currentPrecision;
    int Speed;
    char *Move[max_moves];
    SupemonSkill Skill[6];
    int luck;
}Supemon;

void initializeSupemon(Supemon *supemon, int choice);
void initializeSupmander(Supemon *supemon);
void initializeSupasaur(Supemon *supemon);
void initializeSupirtle(Supemon *supemon);
void initializeSupfox(Supemon *supemon);
void initializeSuplion(Supemon *supemon);
void initializeSuphawk(Supemon *supemon);
void initializeSupsnake(Supemon *supemon);
void initializeSupbear(Supemon *supemon);
void initializeSupwolf(Supemon *supemon);
void initializeSupbat(Supemon *supemon);

#endif
