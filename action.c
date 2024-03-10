//
// Created by corns on 17/02/2024.
//

#include "action.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ui.h"
#include "items.h"
#include "supemon.h"
#include "player.h"


void action(Supemon *defender, Player *player) {
    int choice = 0;
    char place[80];
    char temp[256];
    while (choice != 4){
        int choice = 0;
        printf("+-<3----<3----<3----<3----<3----<3-----+\n");
        printf("|Where do you want to go?              |\n");
        printf("| 1 - Into the wild                    |\n");
        printf("| 2 - In the shop                      |\n");
        printf("| 3 - In the Supemon Center            |\n");
        printf("| 4 - Leave the game                   |\n");
        printf("+--------------------------------------+\n\n");

        printf("Choose 1, 2, 3 or 4 to go: \n");
        while (choice < 1 || choice > 4) {
            fgets(temp, sizeof(temp), stdin);
            if (sscanf(temp, "%d", &choice) != 1) {
                printf("Invalid input. Please enter a number.\n");
                choice = 0;
            } else if (choice < 1 || choice > 4) {
                printf("Invalid choice. Please choose 1, 2, 3 or 4.\n");
            }
        }
        switch(choice) {
            case 1:
                printf("You go into the wild!\n");
                Supemon attacker;
                randomSupemon(&attacker);
                affichage(attacker,defender,player);
                break;
            case 2:
                strcpy(place, "Shop");
                printf("You go in the shop!\n");
                shop(player);
                break;
            case 3:
                strcpy(place, "Center");
                printf("You go in the Supemon Center!\n");
                initializeSupemonCenter(player);
                break;
            case 4:
                quitGame(player);
                break;
        }
    } 
    return;
}