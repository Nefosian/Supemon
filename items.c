#include "items.h"
#include <stdio.h>
#include <string.h>
#include "player.h"

void shop(Player *player){
    int choice = 0;
    char temp[256];

    printf("+-<3----<3----<3----<3----<3----<3----<3----<3----<3----<3----<3----+\n");
    printf("|Welcome to the shop!                                               |\n");
    printf("| 1 - Buy a Potion [+5HP] (100 Supcoins)                            |\n");
    printf("| 2 - Buy a SuperPotion [+10HP] (300 Supcoins)                      |\n");
    printf("| 3 - Buy a RareCandy [adds a level to the Supemon] (700 Supcoins)  |\n");
    printf("| 4 - Buy a Supeball (250 Supcoins)                                 |\n");
    printf("| 5 - Buy a SuperSupeball (500 Supcoins)                            |\n");
    printf("| 6 - Buy a NetBall (750 Supcoins)                                  |\n");
    printf("| 7 - Leave the game                                                |\n");
    printf("+-------------------------------------------------------------------+\n\n");

    printf("Choose a number between 1 and 7 to buy an item: \n");
    while (choice < 1 || choice > 7) {
        fgets(temp, sizeof(temp), stdin);
        if (sscanf(temp, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            choice = 0;
        } else if (choice < 1 || choice > 7) {
            printf("Invalid choice. Please choose a number between 1 and 7.\n");
        }
    }

    switch(choice) {
        case 1:
            if (player->supcoins >= 100){
                printf("You bought a Potion!\n");
                player->supcoins -= 100;
                break;
            } else {
                printf("You don't have enough Supcoins!\n");
                break;
            }
        case 2:
            if (player->supcoins >= 300){
                printf("You bought a SuperPotion!\n");
                player->supcoins -= 300;
                break;
            } else {
                printf("You don't have enough Supcoins!\n");
                break;
            }
        case 3:
            if (player->supcoins >= 700){
                printf("You bought a RareCandy!\n");
                player->supcoins -= 700;
                break;
            } else {
                printf("You don't have enough Supcoins!\n");
                break;
            }
        case 4:
            if (player->supcoins >= 250){
                printf("You bought a Supeball!\n");
                player->supcoins -= 250;
                break;
            } else {
                printf("You don't have enough Supcoins!\n");
                break;
            }
        case 5:
            if (player->supcoins >= 500){
                printf("You bought a SuperSupeball!\n");
                player->supcoins -= 500;
                break;
            } else {
                printf("You don't have enough Supcoins!\n");
                break;
            }
        case 6:
            if (player->supcoins >= 750){
                printf("You bought a NetBall!\n");
                player->supcoins -= 750;
                break;
            } else {
                printf("You don't have enough Supcoins!\n");
                break;
            }
        case 7:
            printf("You leave the game!\n");
            break;
    }
}