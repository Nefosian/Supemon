//
// Created by Elise on 18/02/2024.
//

#include "battle.h"
#include "supemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"


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

void capture(Supemon *attacker, Supemon *defender, Player *player){
    printf("You throw a ball!\n");
    printf("The Supemon is at %d/%d HP\n", attacker->currentLife, attacker->maxLife);
    printf("%d,%d", (float)attacker->maxLife, (float)attacker->currentLife);
    float chance_to_cap = ((float)attacker->maxLife - (float)attacker->currentLife) / (float)attacker->maxLife - 0.5;
    printf("Chance to capture: %f\n", chance_to_cap);
    srand(time(NULL));
    int random_number = rand() % 100;
    if (random_number <= chance_to_cap) {
        printf("You captured the Supemon!\n");
        //addSupemon(player, defender);
    } else {
        printf("The Supemon broke free!\n");
    }
}


void affichage(Supemon *attacker, Supemon *defender, Player *player){
    int choice = 0;
    int choice_move = 0;
    int choice_ball = 0;
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
            printf("Choose an item\n");
            printf("1 - Potion\n");
            printf("2 - SuperPotion\n");
            printf("3 - RareCandy\n");
            break;
        case 4:
            do {
                printf("Do you want to use a Supeball, SuperSupeball or NetBall? Y for yes N for no\n");
                if (scanf(" %c", &response) != 1 || (response != 'y' && response != 'Y' && response != 'n' && response != 'N')) {
                    printf("Invalid response. Please enter 'Y' for yes or 'N' for no.\n"); 
                } 
                } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
                if (response == 'Y' || response == 'y') {
                    printf("Choose a Ball to use\n");
                    printf("1 - Supeball\n");
                    printf("2 - SuperSupeball\n");
                    printf("3 - NetBall\n");
                    switch (choice_ball) {
                        case 1:
                            //check if player has supeball avant de le faire
                            printf("You used a Supeball!\n");
                            break;
                        case 2:
                            //check if player has superspuball avant de le faire
                            printf("You used a SuperSupeball!\n");
                            break;
                        case 3:
                            //check if player has netball avant de le faire 
                            printf("You used a NetBall!\n");
                            break;
                    }
                } else {
                    printf("You chose not to use a ball.\n");
                    capture(attacker, defender, player);
                    break;
            }
        case 5:
            run_away(attacker, defender);
            break;

        default:
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            break;
    }

}

