//
// Created by Elise on 16/02/2024.
//

#include <string.h>
#include "supemon.h"
#include "move_cat.h"
#include "skill_cat.h"
#include <stdio.h>
#include <time.h>

void initializeSupemon(Supemon *supemon, int choice) {
    switch(choice) {
        case 1:
            initializeSupmander(supemon);
            break;
        case 2:
            initializeSupasaur(supemon);
            break;
        case 3:
            initializeSupirtle(supemon);
            break;
        case 4:
            initializeSupfox(supemon);
            break;
        case 5:
            initializeSuplion(supemon);
            break;
        case 6:
            initializeSuphawk(supemon);
            break;
        case 7:
            initializeSupsnake(supemon);
            break;
        case 8:
            initializeSupbear(supemon);
            break;
        case 9:
            initializeSupwolf(supemon);
            break;
        case 10:
            initializeSupbat(supemon);
            break;
    }
}

void initializeSupmander(Supemon *supemon) {
    strcpy(supemon->name, "Supmander");
    strcpy(supemon->type, "Fire");
    strcpy(supemon->weakness, "Water, Ground, Rock");
    supemon->level = 1;
    supemon->maxLife = 10;
    supemon->currentLife = 10;
    supemon->Attack = 1;
    supemon->Defense = 1;
    supemon->Dodge = 1;
    supemon->Precision = 2;
    supemon->Speed = 1;
    supemon->Move[0] = Slap;
    supemon->Move[1] = Roar;
    supemon->Skill1 = Scratch;
    supemon->Skill2 = Grawl;
    supemon->skill1damage = 2;
}

void initializeSupasaur(Supemon *supemon) {
    strcpy(supemon->name, "Supasaur");
    strcpy(supemon->type, "Plant");
    strcpy(supemon->weakness, "Fire, Ice, Poison, Flight, Insect");
    supemon->level = 1;
    supemon->maxLife = 9;
    supemon->currentLife = 9;
    supemon->Attack = 1;
    supemon->Defense = 1;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 2;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Whip;
    supemon->Skill1 = Pound;
    supemon->Skill2 = Foliage;
    supemon->skill1damage = 2;

}

void initializeSupirtle(Supemon *supemon) {
    strcpy(supemon->name, "Supirtle");
    strcpy(supemon->type, "Water");
    strcpy(supemon->weakness, "Electrical, Plant");
    supemon->level = 1;
    supemon->maxLife = 11;
    supemon->currentLife = 11;
    supemon->Attack = 1;
    supemon->Defense = 2;
    supemon->Dodge = 2;
    supemon->Precision = 1;
    supemon->Speed = 1;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Curve;
    supemon->Skill1 = Pound;
    supemon->Skill2 = Shell;
    supemon->skill1damage = 2;
}

void initializeSupfox(Supemon *supemon) {
    strcpy(supemon->name, "Supfox");
    strcpy(supemon->type, "Fire/Psy");
    strcpy(supemon->weakness, "Water, Rock, Earth, Spectre, Darkness");
    supemon->level = 1;
    supemon->maxLife = 9;
    supemon->currentLife = 9;
    supemon->Attack = 2;
    supemon->Defense = 3;
    supemon->Dodge = 1;
    supemon->Precision = 2;
    supemon->Speed = 1;
    supemon->Move[0] = Wink;
    supemon->Move[1] = Roll;
    supemon->Move[2] = Dance;
    supemon->Skill1 = Charm;
    supemon->Skill2 = FireTornado;
    supemon->Skill3 = Slash;
    supemon->skill1damage = 2;
}

void initializeSuplion(Supemon *supemon) {
    strcpy(supemon->name, "Suplion");
    strcpy(supemon->type, "normal");
    strcpy(supemon->weakness, "Fight");
    supemon->level = 1;
    supemon->maxLife = 9;
    supemon->currentLife = 9;
    supemon->Attack = 2;
    supemon->Defense = 2;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 3;
    supemon->Move[0] = Roar;
    supemon->Move[1] = Bit;
    supemon->Skill1 = Intimidation;
    supemon->Skill2 = Fang;
    supemon->skill1damage = 2;
}

void initializeSuphawk(Supemon *supemon) {
    strcpy(supemon->name, "Suphawk");
    strcpy(supemon->type, "Flight");
    strcpy(supemon->weakness, "Electrical, Ice, Rock");
    supemon->level = 1;
    supemon->maxLife = 12;
    supemon->currentLife = 12;
    supemon->Attack = 3;
    supemon->Defense = 3;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 2;
    supemon->Move[0] = Fly;
    supemon->Move[1] = Bit;
    supemon->Skill1 = Tornado;
    supemon->Skill2 = Peck;
    supemon->skill1damage = 2;
}

void initializeSupsnake(Supemon *supemon) {
    strcpy(supemon->name, "Supsnake");
    strcpy(supemon->type, "Poison");
    strcpy(supemon->weakness, "Earth, Psy");
    supemon->level = 1;
    supemon->maxLife = 10;
    supemon->currentLife = 10;
    supemon->Attack = 2;
    supemon->Defense = 1;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 1;
    supemon->Move[0] = Spit;
    supemon->Move[1] = Watch;
    supemon->Skill1 = Poison;
    supemon->Skill2 = Hipnosis;
    supemon->skill1damage = 2;
}

void initializeSupbear(Supemon *supemon) {
    strcpy(supemon->name, "Supbear");
    strcpy(supemon->type, "Fight/Earth");
    strcpy(supemon->weakness, "Flying, Psychic, Water, Plant, Ice");
    supemon->level = 1;
    supemon->maxLife = 10;
    supemon->currentLife = 10;
    supemon->Attack = 3;
    supemon->Defense = 1;
    supemon->Dodge = 3;
    supemon->Precision = 3;
    supemon->Speed = 2;
    supemon->Move[0] = Charge;
    supemon->Move[1] = Jump;
    supemon->Skill1 = Suplex;
    supemon->Skill2 = Earthquake;
    supemon->skill1damage = 2;
}

void initializeSupwolf(Supemon *supemon) {
    strcpy(supemon->name, "Supwolf");
    strcpy(supemon->type, "Darkness");
    strcpy(supemon->weakness, "Fighting, Insect, Fairy");
    supemon->level = 1;
    supemon->maxLife = 10;
    supemon->currentLife = 10;
    supemon->Attack = 3;
    supemon->Defense = 2;
    supemon->Dodge = 3;
    supemon->Precision = 1;
    supemon->Speed = 1;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Backflip;
    supemon->Skill1 = Pound;
    supemon->Skill2 = IronTail;
    supemon->skill1damage = 2;
}

void initializeSupbat(Supemon *supemon) {
    strcpy(supemon->name, "Supbat");
    strcpy(supemon->type, "Flight/Poison");
    strcpy(supemon->weakness, "Electric, Ice, Rock, Psych");
    supemon->level = 1;
    supemon->maxLife = 11;
    supemon->currentLife = 11;
    supemon->Attack = 1;
    supemon->Defense = 2;
    supemon->Dodge = 3;
    supemon->Precision = 2;
    supemon->Speed = 3;
    supemon->Move[0] = Cry;
    supemon->Move[1] = Bit;
    supemon->Skill1 = Shockwave;
    supemon->Skill2 = Vampirism;
    supemon->skill1damage = 2;
}


const char* moveToString(move) {
    switch(move) {
        case Curve:return "Curve";
        case Jump:return "Jump";
        case Roll:return "Roll";
        case Roar:return "Roar";
        case Dance:return "Dance";
        case Whip:return "Whip";
        case Slap:return "Slap";
        case Bit:return "Bit";
        case Backflip:return "Backflip";
        case Wink:return "Wink";
        case Fly:return "Fly";
        case Spit:return "Spit";
        case Watch:return "Watch";
        case Charge:return "Charge";
        case Cry:return "Cry";
        default: return "Unknown Move";
    }
}

const char* skillToString(skill) {
    switch(skill) {
        case Scratch:return "Scratch";
        case Grawl:return "Grawl";
        case FireTornado:return "FireTornado";
        case Pound:return "Pound";
        case Foliage:return "Foliage";
        case Shell:return "Shell";
        case Charm:return "Charm";
        case Intimidation:return "Intimidation";
        case Tornado:return "Tornado";
        case Peck:return "Peck";
        case Poison:return "Poison";
        case Hipnosis:return "Hipnosis";
        case Suplex:return "Suplex";
        case Earthquake:return "Earthquake";
        case Fang:return "Fang";
        case IronTail:return "IronTail";
        case Shockwave:return "Shockwave";
        case Slash:return "Slash";
        case Vampirism:return "Vampirism";
        default: return "Unknown Skill";
    }
}


void displayMoves(Supemon *supemon) {
    printf("1. %s\n", moveToString(supemon->Move[0]));
    printf("2. %s\n", moveToString(supemon->Move[1]));
    if(supemon->Move[2] != NULL) {
        printf("3. %s\n", moveToString(supemon->Move[2]));
    }
}


void skill_condition(Supemon *defender, Supemon *attacker){
    printf("Attack : %s\n",skillToString(defender->Skill2));
        switch (defender->Skill2) {
            case Scratch:
                defender->Speed +=1;
                printf("You have now : %d Speed\n",defender->Speed);
                break;
            case Grawl:
                defender->Attack +=1;
                printf("You have now : %d Attack\n",defender->Attack);
                break;
            case FireTornado:
                defender->Attack +=1;
                printf("You have now : %d Attack\n",defender->Attack);
                break;
            case Pound:
                defender->Dodge +=1;
                printf("You have now : %d Dodge\n",defender->Dodge);
                break;
            case Foliage:
                defender->Defense +=1;
                printf("You have now : %d Defense\n",defender->Defense);
                break;
            case Shell:
                defender->Defense +=1;
                printf("You have now : %d Defense\n",defender->Defense);
                break;
            case Charm:
                defender->Precision +=1;
                printf("You have now : %d Precision\n",defender->Precision);
                break;
            case Intimidation:
                defender->Precision +=1;
                printf("You have now : %d Precision\n",defender->Precision);
                break;
            case Tornado:
                defender->Dodge +=1;
                printf("You have now : %d Dodge\n",defender->Dodge);
                break;
            case Peck:
                defender->Precision +=1;
                printf("You have now : %d Precision\n",defender->Precision);
                break;
            case Poison:
                defender->Attack +=1;
                printf("You have now : %d Attack\n",defender->Attack);
                break;
            case Hipnosis:
                defender->Dodge +=1;
                printf("You have now : %d Dodge\n",defender->Dodge);
                break;
            case Suplex:
                defender->Attack +=1;
                printf("You have now : %d Attack\n",defender->Attack);
                break;
            case Earthquake:
                defender->Defense +=1;
                printf("You have now : %d Defense\n",defender->Defense);
                break;
            case Fang:
                defender->Attack +=1;
                printf("You have now : %d Attack\n",defender->Attack);
                break;
            case IronTail:
                defender->Defense +=1;
                printf("You have now : %d Defense\n",defender->Defense);
                break;
            case Shockwave:
                defender->Precision +=1;
                printf("You have now : %d Precision\n",defender->Precision);
                break;
            case Slash:
                defender->Attack +=1;
                printf("You have now : %d Attack\n",defender->Attack);
                break;
            case Vampirism:
                defender->currentLife +=1;
                attacker->currentLife -=1;
                printf("You stole 1 HP to your opponent\n");
                printf("Your opponent has now : %d/%d HP\n",attacker->currentLife,attacker->maxLife);
                printf("You have now : %d/%d HP\n",defender->currentLife,defender->maxLife);
                break;
            default:
                printf("Unknown Skill");
                break;
        }
}

void displayUsed(Supemon *defender, Supemon *attacker, int i) {
    printf("%s used %s\n", defender->name, moveToString(defender->Move[i-1]));
    if (i == 1) {
        srand(time(NULL));
        printf("Attack : %s\n",skillToString(defender->Skill1));
        float dodge = (float)defender->Precision / (defender->Precision + attacker->Dodge)+0.1;
        int dodge_percent = dodge * 100;
        int random_number = rand() % 100;
        if (random_number <= dodge_percent) {
            float calcul = (defender->Attack * defender->skill1damage) / attacker->Defense;
            attacker->currentLife -= calcul;
            printf("Your opponent has now : %d/%d HP\n",attacker->currentLife,attacker->maxLife);
        } else {                        
            printf("Your opponent dodged the attack\n");
        }
    } else if (i == 2 || i==3) {
        skill_condition(defender,attacker);
    }
}
