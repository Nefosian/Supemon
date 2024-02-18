//
// Created by Elise on 16/02/2024.
//

#include <string.h>
#include "supemon.h"

void initializeSupmander(Supemon *supemon) {
    strcpy(supemon->name, "Supmander");
    strcpy(supemon->type, "Fire");
    strcpy(supemon->weakness, "Water, Ground, Rock");
    supemon->maxLife = 10;
    supemon->Attack = 1;
    supemon->Defense = 1;
    supemon->Dodge = 1;
    supemon->Precision = 2;
    supemon->Speed = 1;
    supemon->Move[0] = Slap;
    supemon->Move[1] = Roar;
    supemon->Skill[0] = Scratch;
    supemon->Skill[1] = Grawl;
}

void initializeSupasaur(Supemon *supemon) {
    strcpy(supemon->name, "Supasaur");
    strcpy(supemon->type, "Plant");
    strcpy(supemon->weakness, "Fire, Ice, Poison, Flight, Insect");
    supemon->maxLife = 9;
    supemon->Attack = 1;
    supemon->Defense = 1;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 2;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Whip;
    supemon->Skill[0] = Pound;
    supemon->Skill[1] = Foliage;

}

void initializeSupirtle(Supemon *supemon) {
    strcpy(supemon->name, "Supirtle");
    strcpy(supemon->type, "Water");
    strcpy(supemon->weakness, "Electrical, Plant");
    supemon->maxLife = 11;
    supemon->Attack = 1;
    supemon->Defense = 2;
    supemon->Dodge = 2;
    supemon->Precision = 1;
    supemon->Speed = 1;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Curve;
    supemon->Skill[0] = Pound;
    supemon->Skill[1] = Shell;
}

void initializeSupfox(Supemon *supemon) {
    strcpy(supemon->name, "Supfox");
    strcpy(supemon->type, "Fire/Psy");
    strcpy(supemon->weakness, "Water, Rock, Earth, Spectre, Darkness");
    supemon->maxLife = 9;
    supemon->Attack = 2;
    supemon->Defense = 3;
    supemon->Dodge = 1;
    supemon->Precision = 2;
    supemon->Speed = 1;
    supemon->Move[0] = Wink;
    supemon->Move[1] = Roll;
    supemon->Move[2] = Dance;
    supemon->Skill[0] = Charm;
    supemon->Skill[1] = FireTornado;
    supemon->Skill[2] = Slash;
}

void initializeSuplion(Supemon *supemon) {
    strcpy(supemon->name, "Suplion");
    strcpy(supemon->type, "normal");
    strcpy(supemon->weakness, "Fight");
    supemon->maxLife = 9;
    supemon->Attack = 2;
    supemon->Defense = 2;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 3;
    supemon->Move[0] = Roar;
    supemon->Move[1] = Bit;
    supemon->Skill[0] = Intimidation;
    supemon->Skill[1] = Fang;
}

void initializeSuphawk(Supemon *supemon) {
    strcpy(supemon->name, "Suphawk");
    strcpy(supemon->type, "Flight");
    strcpy(supemon->weakness, "Electrical, Ice, Rock");
    supemon->maxLife = 12;
    supemon->Attack = 3;
    supemon->Defense = 3;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 2;
    supemon->Move[0] = Fly;
    supemon->Move[1] = Bit;
    supemon->Skill[0] = Tornado;
    supemon->Skill[1] = Peck;
}

void initializeSupsnake(Supemon *supemon) {
    strcpy(supemon->name, "Supsnake");
    strcpy(supemon->type, "Poison");
    strcpy(supemon->weakness, "Earth, Psy");
    supemon->maxLife = 10;
    supemon->Attack = 2;
    supemon->Defense = 1;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 1;
    supemon->Move[0] = Spit;
    supemon->Move[1] = Watch;
    supemon->Skill[0] = Poison;
    supemon->Skill[1] = Hipnosis;
}

void initializeSupbear(Supemon *supemon) {
    strcpy(supemon->name, "Supbear");
    strcpy(supemon->type, "Fight/Earth");
    strcpy(supemon->weakness, "Flying, Psychic, Water, Plant, Ice");
    supemon->maxLife = 10;
    supemon->Attack = 3;
    supemon->Defense = 1;
    supemon->Dodge = 3;
    supemon->Precision = 3;
    supemon->Speed = 2;
    supemon->Move[0] = Charge;
    supemon->Move[1] = Jump;
    supemon->Skill[0] = Suplex;
    supemon->Skill[1] = Earthquake;
}

void initializeSupwolf(Supemon *supemon) {
    strcpy(supemon->name, "Supwolf");
    strcpy(supemon->type, "Darkness");
    strcpy(supemon->weakness, "Fighting, Insect, Fairy");
    supemon->maxLife = 10;
    supemon->Attack = 3;
    supemon->Defense = 2;
    supemon->Dodge = 3;
    supemon->Precision = 1;
    supemon->Speed = 1;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Backflip;
    supemon->Skill[0] = Pound;
    supemon->Skill[1] = IronTail;
}

void initializeSupbat(Supemon *supemon) {
    strcpy(supemon->name, "Supbat");
    strcpy(supemon->type, "Flight/Poison");
    strcpy(supemon->weakness, "Electric, Ice, Rock, Psych");
    supemon->maxLife = 11;
    supemon->Attack = 1;
    supemon->Defense = 2;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 3;
    supemon->Move[0] = Cry;
    supemon->Move[1] = Bit;
    supemon->Skill[0] = Shockwave;
    supemon->Skill[1] = Vampirism;
}