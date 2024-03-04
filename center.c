#include "center.h"
#include "player.h"
#include "supemon.h"
#include <stdio.h>

void healSupemons(Player *player){
    if (player == NULL) {
        printf("Error: Player data is null.\n");
        return;
    }

    if (player->numberDeckSupemons == 0 && player->supemonSelected != NULL){
        player->supemonSelected->currentLife = player->supemonSelected->maxLife;
        printf("Your selected Supemon is now healed and at full life!\n");
    } else {
        for (int i = 0; i < player->numberDeckSupemons; i++) {
            player->deckSupemons[i].currentLife = player->deckSupemons[i].maxLife;
        }
        printf("Your Supemons are now healed and at full life!\n");
    }
}

void displayPC(const Player *player){
    if (player == NULL) {
        printf("Error: Cannot display PC, player data is null.\n");
        return;
    }

    printf("Number of Supemons in PC: %d\n", player->numberSupemons);
    if (player->numberSupemons == 0) {
        printf("The PC is currently empty.\n");
        return;
    }

    printf("+-<3----<3----<3----<3----<3----<3-----+\n");
    printf("| Your current Supemon PC:             |\n");
    for (int i = 0; i < player->numberSupemons; i++) {
        printf("| %d - %s, Level: %d, HP: %d/%d    \n", 
               i + 1, 
               player->collectionSupemons[i].name, 
               player->collectionSupemons[i].level, 
               player->collectionSupemons[i].currentLife, 
               player->collectionSupemons[i].maxLife);
    }
    printf("+---------------------------------------+\n\n");
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