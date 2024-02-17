//
// Created by Elise on 16/02/2024.
//

#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "player.h"


void initializePlayer(Player *player) {
    int choix;
    char starterName[80];

    printf("Enter your name: \n");
    fgets(player->name, sizeof(player->name), stdin);
    size_t ln = strlen(player->name) - 1;
    if (player->name[ln] == '\n') {
        player->name[ln] = '\0';
    }

    printf("+-<3----<3----<3----<3----<3----<3-+\n");
    printf("|Choose your starter Supemon:      |\n");
    printf("| 1 - Supmander                    |\n");
    printf("| 2 - Supasaur                     |\n");
    printf("| 3 - Supirtle                     |\n");
    printf("+----------------------------------+\n\n");

    printf("1, 2 or 3: ");
    scanf("%d", &choix);

    switch(choix) {
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
        default:
            printf("Invalid choice. Please choose 1, 2, or 3.\n");
            return;
    }

}