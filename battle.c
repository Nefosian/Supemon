//
// Created by Elise on 18/02/2024.
//

#include "battle.h"
#include "supemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "inventory.h"


void run_away(Supemon *attacker, Supemon *defender){
    printf("You try to run away!\n");
    srand(time(NULL));
    float chance_to_escape = (float)defender->Speed / ((float)defender->Speed + (float)attacker->Speed);
    int escape_chance = (int)(chance_to_escape * 100);
    int random_number = rand() % 100;
    if (random_number <= escape_chance) {
        printf("You successfully escaped!\n");
    } else {
        printf("You failed to escape!\n");
    }

    return 0;
}

void capture(Supemon *attacker, Supemon *defender, Player *player,float chance_ball){
    printf("You throw a ball!\n");
    float chance_to_cap = (((float)attacker->maxLife - (float)attacker->currentLife) / (float)attacker->maxLife) - chance_ball;
    int capture_chance = (int)(chance_to_cap * 100);
    srand(time(NULL));
    int random_number = rand() % 100;
    if (random_number <= capture_chance) {
        printf("You captured the Supemon!\n");
        //addSupemon(player, defender);
    } else {
        printf("The Supemon broke free!\n");
    }
}

void check_ball(Supemon *attacker, Supemon *defender, Player *player,char response,int choice_ball){
    do {
        printf("Do you want to use a Supeball, SuperSupeball or NetBall? Y for yes N for no\n");
        if (scanf(" %c", &response) != 1 || (response != 'y' && response != 'Y' && response != 'n' && response != 'N')) {
            printf("Invalid response. Please enter 'Y' for yes or 'N' for no.\n"); 
        } 
        } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
        if (response == 'Y' || response == 'y') {
            printf("You have %d Supeball, %d SuperSupeball and %d NetBall\n",nbitem(player, Supeball),nbitem(player, SuperSupeball),nbitem(player, NetBall));
            printf("Choose a Ball to use\n");
            printf("1 - Supeball\n");
            printf("2 - SuperSupeball\n");
            printf("3 - NetBall\n");
            printf("4 - Don't use a special ball\n");
            scanf("%d", &choice_ball);
            if (choice_ball != 1 || choice_ball < 1 || choice_ball > 4) {
                printf("Invalid input. Please enter a number between 1 and 3.\n");
            } else {
                switch (choice_ball) {
                    case 1:
                        if (hasItem(player, Supeball) == Supeball){
                            printf("You used a Supeball your chance to Capture is now increased by 2!\n");
                            removeItem(player, Supeball, 1);
                            capture(attacker, defender, player,0.25);
                            break;
                        } else {
                            printf("You don't have any Supeball!\n");
                            check_ball(attacker, defender, player,response,choice_ball);
                            break;
                        }
                    case 2:
                        if (hasItem(player, SuperSupeball) == SuperSupeball){
                            printf("You used a SuperSupeball your chance to Capture is now increased by 2!\n");
                            removeItem(player, SuperSupeball, 1);
                            capture(attacker, defender, player,0.25);
                            break;
                        } else {
                            printf("You don't have any SuperSupeball!\n");
                            check_ball(attacker, defender, player,response,choice_ball);
                            break;
                        }
                    case 3:
                        if (hasItem(player, NetBall) == NetBall){
                            printf("You used a NetBall your chance to Capture is now increased by 2!\n");
                            removeItem(player,NetBall, 1);
                            capture(attacker, defender, player,0.25);
                            break;
                        } else {
                            printf("You don't have any NetBall!\n");
                            check_ball(attacker, defender, player,response,choice_ball);
                            break;
                        }
                    case 4:
                        printf("You chose not to use a special ball.\n");
                        capture(attacker, defender, player,0.5);
                        return 0;
                }
            }
        } else {
            printf("You chose not to use a special ball.\n");
            capture(attacker, defender, player,0.5);
            return 0;
        }
}

void fct_for_item(Player *player,Supemon *defender,Items item){
    if (hasItem(player, item) == item){
        printf("You used a %s!\n",item);
        useItem(player, item);
        removeItem(player, item, 1);
        return 0;
    } else {
        printf("You don't have any %s!\n",item);
        return 0;
    }
}

void item_use(Player *player,char response,int choice_item,Supemon *defender){
    do {
        printf("Do you want to use a Potion, SuperPotion or RareCandy? Y for yes N for no\n");
        if (scanf(" %c", &response) != 1 || (response != 'y' && response != 'Y' && response != 'n' && response != 'N')) {
            printf("Invalid response. Please enter 'Y' for yes or 'N' for no.\n"); 
        } 
        } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
        if (response == 'Y' || response == 'y') {
            printf("You have %d Potion, %d SuperPotion and %d RareCandy\n",nbitem(player, Potion),nbitem(player, SuperPotion),nbitem(player, RareCandy));
            printf("Choose an item to use\n");
            printf("1 - Potion\n");
            printf("2 - SuperPotion\n");
            printf("3 - RareCandy\n");
            printf("4 - Don't use an item\n");
            scanf("%d", &choice_item);
            if (choice_item != 1 || choice_item < 1 || choice_item > 4) {
                printf("Invalid input. Please enter a number between 1 and 4.\n");
                return 0;
            } else {
                switch (choice_item) {
                    case 1:
                        fct_for_item(player,defender,Potion);
                        break;
                    case 2:
                        fct_for_item(player,defender,SuperPotion);
                        break;
                    case 3:
                        fct_for_item(player,defender,RareCandy);
                        break;
                    case 4:
                        printf("You chose not to use an item.\n");
                        return 0;
                }
                return 0;
            }
        } else {
            printf("You don't want to use item! The game continue!");
            return 0;
        }
}

void affichage(Supemon *attacker, Supemon *defender, Player *player){
    int choice = 0;
    int choice_move = 0;
    int choice_ball = 0;
    int choice_item = 0;
    char response;
    

    printf("%s (Enemy)\n", attacker->name);
    printf("--------------------------------\n");
    printf("HP:    %d/%d           Level:   %d\n", attacker->currentLife, attacker->maxLife, attacker->level);
    printf("Attack: %d            Defense: %d\n", attacker->Attack, attacker->Defense);
    printf("Speed:  %d            Dodge:   %d\n",attacker->Speed, attacker->Dodge);
    printf("--------------------------------\n");
    printf("%s (%s)\n", defender->name, player->name);
    printf("--------------------------------\n");
    printf("HP:    %d/%d           Level:   %d\n", defender->currentLife, defender->maxLife, defender->level);
    printf("Attack: %d            Defense: %d\n", defender->Attack, defender->Defense);
    printf("Speed:  %d            Dodge:   %d\n",defender->Speed, defender->Dodge);
    printf("--------------------------------\n\n");
    printf("+----------------------+\n");
    printf("|What will you do?     |\n");
    printf("| 1 - Move             |\n");
    printf("| 2 - Change Supremon  |\n");
    printf("| 3 - Use item         |\n");
    printf("| 4 - Capture          |\n");
    printf("| 5 - Run away         |\n");
    printf("+----------------------+\n");
    

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
    }

    switch (choice) {
        case 1:
            printf("Choose a move.\n");
            printf("1 - %s\n", defender->Move[0]);
            printf("2 - %s\n", defender->Move[1]);
            if (defender->Move[2] != NULL) {
                printf("3 - %s\n", defender->Move[2]);
            }
            scanf("%d", &choice_move);
            if (choice_move < 1 || choice_move > 3) {
                printf("Invalid input. Please enter a number between 1 and 3.\n");
            }
            switch (choice_move) {
                case 1:
                    printf("%s used %s!\n", defender->name, defender->Move[0]);
                    break;
                case 2:
                    printf("%s used %s!\n", defender->name, defender->Move[1]);
                    break;
                case 3:
                    printf("%s used %s!\n", defender->name, defender->Move[2]);
                    break;
            }
            break;
        case 2:
            printf("Choose a Supemon\n");
            break;
            
        case 3:
            item_use(player,response,choice_item,defender);
            break;
        case 4:
            check_ball(attacker, defender, player,response,choice_ball);
            break;
        case 5:
            run_away(attacker, defender);
            break;

        default:
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            break;
    }
}