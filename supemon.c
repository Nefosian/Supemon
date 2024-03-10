//
// Created by Elise on 16/02/2024.
//

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "supemon.h"
#include "move_cat.h"
#include "skill_cat.h"
#include "player.h"
#include "battle.h"

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
        case 11:
            initializeSupragon(supemon);
            break;
        case 12:
            initializeSuphoenix(supemon);
            break;
        case 13:
            initializeSupicorn(supemon);
            break;
        case 14:
            initializeSupraken(supemon);
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Slap;
    supemon->Move[1] = Roar;
    supemon->Skill1 = Scratch;
    supemon->Skill2 = Grawl;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Whip;
    supemon->Skill1 = Pound;
    supemon->Skill2 = Foliage;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;

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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Curve;
    supemon->Skill1 = Pound;
    supemon->Skill2 = Shell;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Wink;
    supemon->Move[1] = Roll;
    supemon->Skill1 = Charm;
    supemon->Skill2 = FireTornado;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Roar;
    supemon->Move[1] = Bit;
    supemon->Skill1 = Intimidation;
    supemon->Skill2 = Fang;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Fly;
    supemon->Move[1] = Bit;
    supemon->Skill1 = Tornado;
    supemon->Skill2 = Peck;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Spit;
    supemon->Move[1] = Watch;
    supemon->Skill1 = Poison;
    supemon->Skill2 = Hipnosis;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Charge;
    supemon->Move[1] = Jump;
    supemon->Skill1 = Suplex;
    supemon->Skill2 = Earthquake;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Bit;
    supemon->Move[1] = Backflip;
    supemon->Skill1 = Pound;
    supemon->Skill2 = IronTail;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
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
    supemon->experience = 0;
    supemon->experienceToNextLevel = 500;
    supemon->Move[0] = Cry;
    supemon->Move[1] = Bit;
    supemon->Skill1 = Shockwave;
    supemon->Skill2 = Vampirism;
    supemon->skill1damage = 2;
    supemon->isCaptured = 0;
}

void initializeSupragon(Supemon *supemon) {
    strcpy(supemon->name, "Supdragon");
    strcpy(supemon->type, "Dragon/Fire");
    strcpy(supemon->weakness, "Dragon, Ice, Fairy");
    supemon->level = 1;
    supemon->maxLife = 15;
    supemon->currentLife = 15;
    supemon->Attack = 4;
    supemon->Defense = 4;
    supemon->Dodge = 2;
    supemon->Precision = 3;
    supemon->Speed = 3;
    supemon->experience = 0;
    supemon->experienceToNextLevel = 1000;
    supemon->Move[0] = FlameBreath;
    supemon->Move[1] = DragonRoar;
    supemon->Skill1 = WingFlap;
    supemon->Skill2 = FireBlast;
    supemon->skill1damage = 4;
    supemon->isCaptured = 0;
}

void initializeSuphoenix(Supemon *supemon) {
    strcpy(supemon->name, "Supphoenix");
    strcpy(supemon->type, "Fire/Flying");
    strcpy(supemon->weakness, "Water, Electric, Rock");
    supemon->level = 1;
    supemon->maxLife = 14;
    supemon->currentLife = 14;
    supemon->Attack = 3;
    supemon->Defense = 3;
    supemon->Dodge = 4;
    supemon->Precision = 4;
    supemon->Speed = 4;
    supemon->experience = 0;
    supemon->experienceToNextLevel = 1000;
    supemon->Move[0] = BlazeWing;
    supemon->Move[1] = SkyDive;
    supemon->Skill1 = Rebirth;
    supemon->Skill2 = SolarFlare;
    supemon->skill1damage = 3;
    supemon->isCaptured = 0;
}

void initializeSupicorn(Supemon *supemon) {
    strcpy(supemon->name, "Supunicorn");
    strcpy(supemon->type, "Fairy");
    strcpy(supemon->weakness, "Steel, Poison");
    supemon->level = 1;
    supemon->maxLife = 12;
    supemon->currentLife = 12;
    supemon->Attack = 2;
    supemon->Defense = 3;
    supemon->Dodge = 4;
    supemon->Precision = 3;
    supemon->Speed = 5;
    supemon->experience = 0;
    supemon->experienceToNextLevel = 1000;
    supemon->Move[0] = MagicHorn;
    supemon->Move[1] = MysticalVeil;
    supemon->Skill1 = HealingWish;
    supemon->Skill2 = StarBlast;
    supemon->skill1damage = 3;
    supemon->isCaptured = 0;
}

void initializeSupraken(Supemon *supemon) {
    strcpy(supemon->name, "Supkraken");
    strcpy(supemon->type, "Water/Dark");
    strcpy(supemon->weakness, "Electric, Grass, Bug, Fairy");
    supemon->level = 1;
    supemon->maxLife = 16;
    supemon->currentLife = 16;
    supemon->Attack = 5;
    supemon->Defense = 4;
    supemon->Dodge = 1;
    supemon->Precision = 3;
    supemon->Speed = 2;
    supemon->experience = 0;
    supemon->experienceToNextLevel = 1000;
    supemon->Move[0] = AbyssalGrip;
    supemon->Move[1] = DarkWave;
    supemon->Skill1 = InkCloud;
    supemon->Skill2 = Tsunami;
    supemon->skill1damage = 5;
    supemon->isCaptured = 0;
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
        case FlameBreath:return "FlameBreath";
        case DragonRoar:return "DragonRoar";
        case BlazeWing:return "BlazeWing";
        case SkyDive:return "SkyDive";
        case MagicHorn:return "MagicHorn";
        case MysticalVeil:return "MysticalVeil";
        case AbyssalGrip:return "AbyssalGrip";
        case DarkWave:return "DarkWave";
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
        case WingFlap:return "WingFlap";
        case FireBlast:return "FireBlast";
        case Rebirth:return "Rebirth";
        case SolarFlare:return "SolarFlare";
        case HealingWish:return "HealingWish";
        case StarBlast:return "StarBlast";
        case InkCloud:return "InkCloud";
        case Tsunami:return "Tsunami";
        default: return "Unknown Skill";
    }
}

SupemonMove StringToMove(const char* moveString) {
    if (strcmp(moveString, "Curve") == 0) return Curve;
    if (strcmp(moveString, "Jump") == 0) return Jump;
    if (strcmp(moveString, "Roll") == 0) return Roll;
    if (strcmp(moveString, "Roar") == 0) return Roar;
    if (strcmp(moveString, "Dance") == 0) return Dance;
    if (strcmp(moveString, "Whip") == 0) return Whip;
    if (strcmp(moveString, "Slap") == 0) return Slap;
    if (strcmp(moveString, "Bit") == 0) return Bit;
    if (strcmp(moveString, "Backflip") == 0) return Backflip;
    if (strcmp(moveString, "Wink") == 0) return Wink;
    if (strcmp(moveString, "Fly") == 0) return Fly;
    if (strcmp(moveString, "Spit") == 0) return Spit;
    if (strcmp(moveString, "Watch") == 0) return Watch;
    if (strcmp(moveString, "Charge") == 0) return Charge;
    if (strcmp(moveString, "Cry") == 0) return Cry;
    if (strcmp(moveString, "FlameBreath") == 0) return FlameBreath;
    if (strcmp(moveString, "DragonRoar") == 0) return DragonRoar;
    if (strcmp(moveString, "BlazeWing") == 0) return BlazeWing;
    if (strcmp(moveString, "SkyDive") == 0) return SkyDive;
    if (strcmp(moveString, "MagicHorn") == 0) return MagicHorn;
    if (strcmp(moveString, "MysticalVeil") == 0) return MysticalVeil;
    if (strcmp(moveString, "AbyssalGrip") == 0) return AbyssalGrip;
    if (strcmp(moveString, "DarkWave") == 0) return DarkWave;
}

SupemonSkill StringToSkill(const char* skillString) {
    if (strcmp(skillString, "Scratch") == 0) return Scratch;
    if (strcmp(skillString, "Grawl") == 0) return Grawl;
    if (strcmp(skillString, "FireTornado") == 0) return FireTornado;
    if (strcmp(skillString, "Pound") == 0) return Pound;
    if (strcmp(skillString, "Foliage") == 0) return Foliage;
    if (strcmp(skillString, "Shell") == 0) return Shell;
    if (strcmp(skillString, "Charm") == 0) return Charm;
    if (strcmp(skillString, "Intimidation") == 0) return Intimidation;
    if (strcmp(skillString, "Tornado") == 0) return Tornado;
    if (strcmp(skillString, "Peck") == 0) return Peck;
    if (strcmp(skillString, "Poison") == 0) return Poison;
    if (strcmp(skillString, "Hipnosis") == 0) return Hipnosis;
    if (strcmp(skillString, "Suplex") == 0) return Suplex;
    if (strcmp(skillString, "Earthquake") == 0) return Earthquake;
    if (strcmp(skillString, "Fang") == 0) return Fang;
    if (strcmp(skillString, "IronTail") == 0) return IronTail;
    if (strcmp(skillString, "Shockwave") == 0) return Shockwave;
    if (strcmp(skillString, "Slash") == 0) return Slash;
    if (strcmp(skillString, "Vampirism") == 0) return Vampirism;
    if (strcmp(skillString, "WingFlap") == 0) return WingFlap;
    if (strcmp(skillString, "FireBlast") == 0) return FireBlast;
    if (strcmp(skillString, "Rebirth") == 0) return Rebirth;
    if (strcmp(skillString, "SolarFlare") == 0) return SolarFlare;
    if (strcmp(skillString, "HealingWish") == 0) return HealingWish;
    if (strcmp(skillString, "StarBlast") == 0) return StarBlast;
    if (strcmp(skillString, "InkCloud") == 0) return InkCloud;
    if (strcmp(skillString, "Tsunami") == 0) return Tsunami;
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
                printf("You have now : %d point of Speed\n",defender->Speed);
                break;
            case Grawl:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            case FireTornado:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            case Pound:
                defender->Dodge +=1;
                printf("You have now : %d point of Dodge\n",defender->Dodge);
                break;
            case Foliage:
                defender->Defense +=1;
                printf("You have now : %d point of Defense\n",defender->Defense);
                break;
            case Shell:
                defender->Defense +=1;
                printf("You have now : %d point of Defense\n",defender->Defense);
                break;
            case Charm:
                defender->Precision +=1;
                printf("You have now : %d point of Precision\n",defender->Precision);
                break;
            case Intimidation:
                defender->Precision +=1;
                printf("You have now : %d point of Precision\n",defender->Precision);
                break;
            case Tornado:
                defender->Dodge +=1;
                printf("You have now : %d point of Dodge\n",defender->Dodge);
                break;
            case Peck:
                defender->Precision +=1;
                printf("You have now : %d point of Precision\n",defender->Precision);
                break;
            case Poison:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            case Hipnosis:
                defender->Dodge +=1;
                printf("You have now : %d point of Dodge\n",defender->Dodge);
                break;
            case Suplex:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            case Earthquake:
                defender->Defense +=1;
                printf("You have now : %d point of Defense\n",defender->Defense);
                break;
            case Fang:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            case IronTail:
                defender->Defense +=1;
                printf("You have now : %d point of Defense\n",defender->Defense);
                break;
            case Shockwave:
                defender->Precision +=1;
                printf("You have now : %d point of Precision\n",defender->Precision);
                break;
            case Slash:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            case Vampirism:
                defender->currentLife +=1;
                attacker->currentLife -=1;
                printf("You stole 1 HP to your opponent\n");
                printf("Your opponent has now : %d/%d HP\n",attacker->currentLife,attacker->maxLife);
                printf("You have now : %d/%d HP\n",defender->currentLife,defender->maxLife);
                break;
            case WingFlap:
                defender->Speed +=1;
                printf("You have now : %d point of Speed\n",defender->Speed);
                break;
            case FireBlast:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            case Rebirth:
                defender->currentLife = defender->maxLife;
                printf("You have now : %d/%d HP\n",defender->currentLife,defender->maxLife);
                break;
            case SolarFlare:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            case HealingWish:
                defender->currentLife = defender->maxLife;
                printf("You have now : %d/%d HP\n",defender->currentLife,defender->maxLife);
                break;
            case StarBlast:
                defender->Precision +=1;
                printf("You have now : %d point of Precision\n",defender->Precision);
                break;
            case InkCloud:
                defender->Dodge +=1;
                printf("You have now : %d point of Dodge\n",defender->Dodge);
                break;
            case Tsunami:
                defender->Attack +=1;
                printf("You have now : %d point of Attack\n",defender->Attack);
                break;
            default:
                printf("Unknown Skill");
                break;
        }
    return;
}

void displayUsedDefender(Supemon *defender, Supemon *attacker, int i,Player *player) {
    printf("%s used %s\n", defender->name, moveToString(defender->Move[i-1]));
    if (i == 1) {
        srand(time(NULL));
        printf("Attack : %s\n",skillToString(defender->Skill1));
        float dodge = (float)defender->Precision / (defender->Precision + attacker->Dodge)+0.1;
        int dodge_percent = dodge * 100;
        int random_number = rand() % 100;
        if (random_number <= dodge_percent) {
            float calcul = (float)(defender->Attack * defender->skill1damage) / attacker->Defense;
            int calculInt = (int)(defender->Attack * defender->skill1damage) / attacker->Defense;
            if (calcul != calculInt) {
                int random_number2 = rand() % 100;
                if (random_number2 < 50) {
                    attacker->currentLife -= (int)calcul;
                } else {
                    attacker->currentLife -= (int)calcul+1;
                }
            } else {
                attacker->currentLife -= calculInt;
            }
            if (attacker->currentLife <= 0){
                attacker->currentLife = 0;
            }
            printf("Your opponent don't dodge the attack\n");
            printf("Your opponent has now : %d/%d HP\n",attacker->currentLife,attacker->maxLife);
        } else {                        
            printf("Your opponent dodged the attack\n");
            printf("Your opponent has already : %d/%d HP\n",attacker->currentLife,attacker->maxLife);
        }
    } else if (i == 2) {
        skill_condition(defender,attacker);
    }
    return;
}

void displayUsedAttacker(Supemon *defender, Supemon *attacker, int i) {
    printf("%s used %s\n", attacker->name, moveToString(attacker->Move[0]));
    srand(time(NULL));
    printf("Attack : %s\n",skillToString(defender->Skill1));
    float dodge = (float)attacker->Precision / (attacker->Precision + defender->Dodge)+0.1;
    int dodge_percent = dodge * 100;
    int random_number = rand() % 100;
    if (random_number <= dodge_percent) {
        float calcul = (float)(attacker->Attack * attacker->skill1damage) / defender->Defense;
        int calculInt = (int)(attacker->Attack * attacker->skill1damage) / defender->Defense;
        if (calcul != calculInt) {
            int random_number2 = rand() % 100;
            if (random_number2 < 50) {
                defender->currentLife -= (int)calcul;
            } else {
                defender->currentLife -= (int)calcul+1;
            }
        } else {
            defender->currentLife -= calculInt;
        }
        if (defender->currentLife <= 0){
            defender->currentLife = 0;
        }
        printf("You don't dodged the attack\n");
        printf("You have now : %d/%d HP\n",defender->currentLife,defender->maxLife);
        if (defender->currentLife <= 0) {
            printf("You lose the fight\n");
        }
    } else {                        
        printf("You dodged the attack\n");
        printf("You have already : %d/%d HP\n",defender->currentLife,defender->maxLife);
    }
}

void defenderMove(Supemon *defender, Supemon *attacker, int choice_move,char temp[255],Player *player) {
    displayMoves(defender);
        printf("Choose a move.\n");
        while (choice_move < 1 || choice_move > 2) {
            fgets(temp, sizeof(temp), stdin);
            if (sscanf(temp, "%d", &choice_move) != 1) {
                printf("Invalid input. Please enter a number.\n");
            } else if (choice_move < 1 || choice_move > 2) {
                printf("Invalid choice. Please choose a number between 1 and 2.\n");
            }
        }
        switch (choice_move) {
            case 1:
                displayUsedDefender(defender, attacker, 1,player);
                break;
            case 2:
                displayUsedDefender(defender, attacker, 2,player);
                break;
    }
}


void firstMove(Supemon *defender, Supemon *attacker, int choice_move, char temp[255],Player *player) {
    if (defender->Speed > attacker->Speed){
        defenderMove(defender, attacker, choice_move, temp,player);
    } if (defender->Speed == attacker->Speed){
        srand(time(NULL));
        int random_number = rand() % 100;
        if (random_number < 50){
            defenderMove(defender, attacker, choice_move, temp,player);
        } else {
            displayUsedAttacker(defender, attacker, 1);
        }
    } else {
        displayUsedAttacker(defender, attacker, 1);
    }    
}


void affiche(Supemon *defender, Supemon *attacker, int choice_move, char temp[255], Player *player){
    int choice_item = 0;
    int choice_ball = 0;
    int response = 0;
    int choice = 0;
    printf("%s (Enemy)\n", attacker->name);
    printf("--------------------------------\n");
    printf("HP:    %d/%d          Level:   %d\n", attacker->currentLife, attacker->maxLife, attacker->level);
    printf("Attack: %d            Defense: %d\n", attacker->Attack, attacker->Defense);
    printf("Speed:  %d            Dodge:   %d\n",attacker->Speed, attacker->Dodge);
    printf("--------------------------------\n");
    printf("%s (%s)\n", player->supemonSelected->name, player->name);
    printf("--------------------------------\n");
    printf("HP:    %d/%d          Level:   %d\n", player->supemonSelected->currentLife, player->supemonSelected->maxLife, player->supemonSelected->level);
    printf("Attack: %d            Defense: %d\n", player->supemonSelected->Attack, player->supemonSelected->Defense);
    printf("Speed:  %d            Dodge:   %d\n",player->supemonSelected->Speed, player->supemonSelected->Dodge);
    printf("--------------------------------\n\n");
    printf("+----------------------+\n");
    printf("|What will you do?     |\n");
    printf("| 1 - Move             |\n");
    printf("| 2 - Change Supremon  |\n");
    printf("| 3 - Use item         |\n");
    printf("| 4 - Capture          |\n");
    printf("| 5 - Run away         |\n");
    printf("+----------------------+\n");

    while (choice < 1 || choice > 5) {
        fgets(temp, sizeof(temp), stdin);
        if (sscanf(temp, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
        } else if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
        }
    }
    switch (choice) {
        case 1:
            defenderMove(player->supemonSelected, attacker, choice_move, temp,player);
            break;
        case 2:
            changeSup(player,choice);
            break;
        case 3:
            item_use(player,response,choice_item,defender);
            break;
        case 4:
            check_ball(attacker, defender, player,response,choice_ball);
            break;
        case 5:
            run_away(attacker, defender,player);
            break;
    }
}

void winExp(Supemon *defender, Supemon *attacker) {
    srand(time(NULL));
    int experience = 0;
    int random_exp= rand() % 401 + 100;
    defender->experience += attacker->level*random_exp;
    printf("You gained %d experience points.\n", attacker->level*random_exp);
    printf("You have now %d/%d XP and your supemon is level %d\n",defender->experience,defender->experienceToNextLevel,defender->level);
    levelUp(defender);
}


void increaseStats(Supemon *supemon) {
    srand(time(NULL));
    int rando = rand()%2;
    float random = 0;
    if (rando == 1){
        random = 0.5;
    } else {
        random= 0;
    }
    supemon->maxLife = (int)(supemon->maxLife + (supemon->maxLife * 0.3)+random);
    supemon->currentLife = supemon->maxLife;
    supemon->Attack = (int)(supemon->Attack + (supemon->Attack * 0.3)+random);
    supemon->Defense = (int)(supemon->Defense + (supemon->Defense * 0.3)+random);
    supemon->Speed = (int)(supemon->Speed + (supemon->Speed * 0.3)+random);
    supemon->Dodge = (int)(supemon->Dodge + (supemon->Dodge * 0.3)+random);
}

void levelUp(Supemon *supemon){
    if (supemon->experience >= supemon->experienceToNextLevel) {
        supemon->level++;
        increaseStats(supemon); 
        printf("Supemon %s leveled up to level %d!\n", supemon->name, supemon->level);

        supemon->experience -= supemon->experienceToNextLevel; 
        supemon->experienceToNextLevel += 1000; 
    } else {
        return;
    }
}

void Move(Supemon *defender, Supemon *attacker, int choice_move, char temp[255], Player *player) {
    firstMove(defender, attacker, choice_move, temp,player);
    while (defender->currentLife > 0 && attacker->currentLife > 0 && attacker->isCaptured == 0) {
        if (defender->currentLife <= 0) {  
            break;
        }
        affiche(defender, attacker, choice_move, temp, player);
        if (attacker->currentLife <= 0 || attacker->isCaptured == 1) {
            if (attacker->currentLife <= 0) {
                printf("You win the fight\n");
                int random_coins= rand() % 401 + 100;
                player->supcoins += random_coins;
                printf("You have now : %d supcoins\n",player->supcoins);
                winExp(defender, attacker);

                break;
            } else if (attacker->isCaptured == 1) {
                break;
            }
        }
        displayUsedAttacker(defender, attacker, 1);
    }
}

void randomSupemon(Supemon *supemon) {
    srand(time(NULL));
    int randomIndex = rand() % 10+1;
    switch (randomIndex) {
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
        case 11:
            initializeSupragon(supemon);
            break;
        case 12:
            initializeSuphoenix(supemon);
            break;
        case 13:
            initializeSupicorn(supemon);
            break;
        case 14:
            initializeSupraken(supemon);
            break;
    }
}