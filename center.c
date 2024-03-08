#include "center.h"
#include "player.h"
#include "supemon.h"
#include <stdio.h>

void healSupemons(Player *player){
    if (player == NULL) {
        printf("Error: Player data is null.\n");
        return;
    }
    player->supemonSelected->currentLife = player->supemonSelected->maxLife;
    for (int i = 0; i < player->numberDeckSupemons; i++) {
        player->deckSupemons[i].currentLife = player->deckSupemons[i].maxLife;
    }
    printf("Your Supemons are now healed and at full life!\n");
}


void displayPC(const Player *player){
    char choice;
    if (player == NULL) {
        printf("Error: Cannot display PC, player data is null.\n");
        return;
    }
    do {
        printf("Do you want to change your active Supemon? (y/n)\n");
        if (scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            printf("Invalid response. Please enter 'Y' for yes or 'N' for no.\n"); 
        } 
        } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
        if (choice == 'Y' || choice == 'y') {
            changeSup(player);
        } else {
            printf("Number of Supemons in PC: %d\n", player-> numberDeckSupemons);
            if (player->numberDeckSupemons == 0) {
                printf("The PC is currently empty.\n");
                return;
            }

            printf("+-<3----<3----<3----<3----<3----<3-----+\n");
            printf("| Your current Supemon PC:             \n");
            for (int i = 0; i < 1; i++) {
                printf("| 1 - %s, Level: %d, HP: %d/%d    \n", 
                    player->supemonSelected->name,
                    player->supemonSelected->level,
                    player->supemonSelected->currentLife,
                    player->supemonSelected->maxLife);
            }
            for (int i = 1; i < player->numberDeckSupemons; i++) {
                printf("| %d - %s, Level: %d, HP: %d/%d    \n", 
                    i + 1, 
                    player->deckSupemons[i].name, 
                    player->deckSupemons[i].level, 
                    player->deckSupemons[i].currentLife, 
                    player->deckSupemons[i].maxLife);
            }
            printf("+---------------------------------------+\n\n");
        }
}

void initializeSupemonCenter(Player *player){
    if (player == NULL) {
        printf("Error: Player data is null.\n");
        return;
    }

    int choice = 0;
    printf("+-<3----<3----<3----<3----<3------+\n");
    printf("| Welcome in Supemon Center!      |\n");
    printf("| What do you want to do?         |\n");
    printf("| 1- Heal your Supemons           |\n");
    printf("| 2- Go to PC                     |\n");
    printf("| 3- Leave the Supemon Center     |\n");
    printf("+-<3----<3----<3----<3----<3------+\n");

    printf("Enter your choice (1-3): \n");
    while (choice < 1 || choice > 3) {
        int result = scanf("%d", &choice);
        while (getchar() != '\n'); 
        if (result != 1) {
            printf("Invalid input. Please enter a number between 1 and 3 : ");
            continue; 
        }
        switch (choice) {
            case 1:
                healSupemons(player);
                break;
            case 2:
                printf("Welcome to your PC!\n");
                displayPC(player);
                break;
            case 3:
                printf("You leave the Supemon Center!\n");
                return; 
            default:
                printf("Invalid choice. Please enter a number between 1 and 3 : \n");
                choice = 0; 
                break;
        }
    }
}