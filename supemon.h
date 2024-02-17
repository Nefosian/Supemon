//
// Created by Elise on 16/02/2024.
//

#ifndef SUPEMON_SUPEMON_H
#define SUPEMON_SUPEMON_H

#include "move_cat.h"
#include "skill_cat.h"

typedef struct{
    char name[80];
    char type[80];
    char gender[80];
    int level;
    int experience;
    int maxLife;
    int currentLife;
    int attack;
    int defense;
    int dodge;
    int precision;
    int currentPrecision;
    int speed;
    SupemonMove Move[6];
    SupemonSkill skill[6];
    int luck;
}Supemon;

#endif
