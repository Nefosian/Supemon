//
// Created by Elise on 16/02/2024.
//

#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "player.h"
#include "supemon.h"
#include "items.h"
#include "inventory.h"
#include "deck.h"

void initializePlayer(Player *player) {
    int choice = 0;
    char starterName[80];
    char temp[256];

    printf("Enter your name: \n");
    fgets(player->name, sizeof(player->name), stdin);
    size_t ln = strlen(player->name) - 1;
    if (player->name[ln] == '\n') {
        player->name[ln] = '\0';
    }

    printf("Enter your age: \n");
    while (fgets(temp, sizeof(temp), stdin)) {
        if (sscanf(temp, "%d", &player->age) == 1) break;
        printf("Invalid input. Please enter a valid age.\n");
    }

    printf("Hello %s!\n", player->name);
    printf("Welcome in Supemon World!\n");

    printf("+-<3----<3----<3----<3----<3----<3-+\n");
    printf("|Choose your starter Supemon:      |\n");
    printf("| 1 - Supmander                    |\n");
    printf("| 2 - Supasaur                     |\n");
    printf("| 3 - Supirtle                     |\n");
    printf("+----------------------------------+\n\n");

    printf("Choose 1, 2, or 3 for your starter Supemon: \n");
    while (choice < 1 || choice > 3) {
        fgets(temp, sizeof(temp), stdin);
        if (sscanf(temp, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            choice = 0;
        } else if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please choose 1, 2, or 3.\n");
        }
    }

    switch(choice) {
        case 1:
            strcpy(starterName, "Supmander");
            printf("You have chosen Supmander!\n");
            break;
        case 2:
            strcpy(starterName, "Supasaur");
            printf("You have chosen Supasaur!\n");
            break;
        case 3:
            strcpy(starterName, "Supirtle");
            printf("You have chosen Supirtle!\n");
            break;
    }
    Supemon starterSupemon;
    initializeSupemon(&starterSupemon, starterName); 
    addSupemonToDeck(player, starterSupemon);
    displayDeck(player);
}
