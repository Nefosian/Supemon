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
#include "deck.h"
#include "items.h"
#include "action.h"


void run_away(Supemon *attacker, Supemon *defender,Player *player){
    printf("You try to run away!\n");
    srand(time(NULL));
    float chance_to_escape = (float)defender->Speed / ((float)defender->Speed + (float)attacker->Speed);
    int escape_chance = (int)(chance_to_escape * 100);
    int random_number = rand() % 100;
    if (random_number <= escape_chance) {
        printf("You successfully escaped!\n");
        action(defender,player);
    } else {
        printf("You failed to escape!\n");
    }
    return;
}

void capture(Supemon *attacker, Supemon *defender, Player *player,float chance_ball){
    float chance_to_cap = (((float)attacker->maxLife - (float)attacker->currentLife) / (float)attacker->maxLife) - chance_ball;
    int capture_chance = (int)(chance_to_cap * 100);
    srand(time(NULL));
    int random_number = rand() % 100;
    if (random_number <= capture_chance) {
        printf("You captured the Supemon!\n");
        attacker->isCaptured = 1;
        addSupemonToDeck(player, *attacker);
        return;
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
            if (scanf("%d",&choice_ball) != 1 || choice_ball < 1 || choice_ball > 4) {
                printf("Invalid input. Please enter a number between 1 and 4.\n");
            } else {
                switch (choice_ball) {
                    case 1:
                        if (hasItem(player, Supeball)){
                            printf("You used a Supeball your chance to Capture is now increased by 2!\n");
                            printf("You throw a Supeball!\n");
                            removeItem(player, Supeball, 1);
                            capture(attacker, defender, player,0.25);
                            printf("You have %d Supeball, %d SuperSupeball and %d NetBall\n",nbitem(player, Supeball),nbitem(player, SuperSupeball),nbitem(player, NetBall));
                            break;
                        } else {
                            printf("You don't have any Supeball!\n");
                            check_ball(attacker, defender, player,response,choice_ball);
                            break;
                        }
                    case 2:
                        if (hasItem(player, SuperSupeball)){
                            printf("You used a SuperSupeball your chance to Capture is now increased by 4!\n");
                            printf("You throw a SuperSupeball!\n");
                            removeItem(player, SuperSupeball, 1);
                            capture(attacker, defender, player,0.25);
                            printf("You have %d Supeball, %d SuperSupeball and %d NetBall\n",nbitem(player, Supeball),nbitem(player, SuperSupeball),nbitem(player, NetBall));
                            break;
                        } else {
                            printf("You don't have any SuperSupeball!\n");
                            check_ball(attacker, defender, player,response,choice_ball);
                            break;
                        }
                    case 3:
                        if (hasItem(player, NetBall)){
                            printf("You used a NetBall your chance to Capture is now increased by 6!\n");
                            printf("You throw a NetBall!\n");
                            removeItem(player,NetBall, 1);
                            capture(attacker, defender, player,0);
                            printf("You have %d Supeball, %d SuperSupeball and %d NetBall\n",nbitem(player, Supeball),nbitem(player, SuperSupeball),nbitem(player, NetBall));
                            break;
                        } else {
                            printf("You don't have any NetBall!\n");
                            check_ball(attacker, defender, player,response,choice_ball);
                            break;
                        }
                    case 4:
                        printf("You chose not to use a special ball.\n");
                        printf("You throw a Ball!\n");
                        capture(attacker, defender, player,0.5);
                        return 0;
                }
            }
        } else {
            printf("You chose not to use a special ball.\n");
            printf("You throw a Ball!\n");
            capture(attacker, defender, player,0.5);
        }
}

void fct_for_item(Player *player,Supemon *defender,Items item){
    if (hasItem(player, item)){
        printf("You used a %c!\n",item);
        useItem(player, defender, item);
        removeItem(player, item, 1);
        return ;
    } else {
        printf("You don't have any %c!\n",item);
        return ;
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
            if (scanf("%d", &choice_item) != 1 || choice_item < 1 || choice_item > 4) {
                printf("Invalid input. Please enter a number between 1 and 4.\n");
            } else {
                switch (choice_item) {
                    case 1:
                        if (hasItem(player, Potion)){
                            useItem(player,defender, Potion);
                            removeItem(player, Potion, 1);
                            item_use(player,response,choice_item,defender);
                            printf("You have now %d Potion, %d SuperPotion and %d RareCandy!\n",nbitem(player, Potion),nbitem(player, SuperPotion),nbitem(player, RareCandy));
                            break;
                        } else {
                            printf("You don't have any Potion in your inventory!\n");
                            item_use(player,response,choice_item,defender);
                            break;
                        }
                    case 2:
                        if (hasItem(player, SuperPotion)){
                            useItem(player,defender, SuperPotion);
                            removeItem(player, SuperPotion, 1);
                            item_use(player,response,choice_item,defender);
                            printf("You have now %d Potion, %d SuperPotion and %d RareCandy!\n",nbitem(player, Potion),nbitem(player, SuperPotion),nbitem(player, RareCandy));
                            break;
                        } else {
                            printf("You don't have any SuperPotion in your inventory!\n");
                            item_use(player,response,choice_item,defender);
                            break;
                        }
                    case 3:
                        if (hasItem(player, RareCandy)){
                            useItem(player,defender, RareCandy);
                            removeItem(player, RareCandy, 1);
                            item_use(player,response,choice_item,defender);
                            printf("You have now %d Potion, %d SuperPotion and %d RareCandy!\n",nbitem(player, Potion),nbitem(player, SuperPotion),nbitem(player, RareCandy));
                            break;
                        } else {
                            printf("You don't have any RareCandy in your inventory!\n");
                            item_use(player,response,choice_item,defender);
                            break;
                        }
                    case 4:
                        printf("You chose to not use an item.\n");
                        return ;
                }
                return ;
            }
        } else {
            printf("You don't want to use item! The fight continue!\n");
            return;
        }
}

void changeSup(Player *player,int choice_supermon) {
    char temp[100];
    int i = 0;
    printf("Choose a Supemon\n");
    displayDeck(player);
    while (1) {
        fgets(temp, sizeof(temp), stdin);
        if (sscanf(temp, "%d", &i) == 1 && i >= 1 && i <= player->numberDeckSupemons) {
            break;
        }
        printf("Invalid choice. Please choose a number between 1 and %d.\n", player->numberDeckSupemons);
    }
    changeSupemon(player, i);
}


void affichage_battle(Supemon *attacker, Supemon *defender, Player *player){
    if (defender->currentLife <= 0) {
        printf("Your supemon doesn't have enough life to fight!\n");
        return;
    }
    int choice = 0;
    int choice_move = 0;
    int choice_ball = 0;
    int choice_item = 0;
    int choice_supermon = 0;
    char response;
    char temp[100];

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
        if (sscanf(temp, "%d", &choice) != 1) {;
            printf("Invalid input. Please enter a number.\n");
        } else if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
        }
    }

    switch (choice) {
        case 1:
            Move(defender,attacker,choice_move,temp,player);
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

void affichage(Supemon *attacker, Supemon *defender, Player *player){
    while (defender->currentLife > 0 && attacker->currentLife > 0 && attacker->isCaptured == 0){
        affichage_battle(attacker, defender, player);
        if (defender->currentLife <= 0) {
            return;
        }
        if (attacker->currentLife <= 0) {
            return;
        }
    }
}