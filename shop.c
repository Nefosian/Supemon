#include "shop.h"
#include "items.h"
#include <stdio.h>
#include <string.h>
#include "player.h"


void verify(char temp[], char response, Player *player) {
    do {
        printf("Would you want to buy another thing (Y for yes, N for no) ?\n");
        if (scanf(" %c", &response) != 1 || (response != 'y' && response != 'Y' && response != 'n' && response != 'N')) {
            printf("Invalid response. Please enter 'Y' for yes or 'N' for no.\n"); 
        } 
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    if (response == 'Y' || response == 'y') {
        shop(player);
    } else {
        return;
    }
}

void Buy(Player *player, Items item, Items price, char temp[256], char response) {
    if (player->supcoins >= price) {
        if (player->numberItems < maxItem) {
            player->supcoins -= price;
            addItem(player, item, 1);
            printf("Item purchased successfully! You now have %d Supcoins remaining.\n", player->supcoins);
            printf(", you now have %d in your inventory.\n", player->objets[player->numberItems - 1].quantity, itemName(item));
            verify(temp, response, player);
        } else {
            printf("Your inventory is full.\n");
            verify(temp, response, player);
        }
    } else {
        printf("You don't have enough Supcoins! You have %d Supcoins.\n", player->supcoins);
        verify(temp, response, player);
    }
}


void shop(Player *player){
    int choice = 0;
    char temp[256];
    char response;

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

    printf("What would you like to buy? (Enter number):\n");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
    }
    

    switch(choice) {
        case 1:
            Buy(player, Potion, 100, temp, response);
            break;
        case 2:
            Buy(player, SuperPotion, 300, temp, response);
            break;
        case 3:
            Buy(player, RareCandy, 700, temp, response);
            break;  
        case 4:
            Buy(player, Supeball, 250, temp, response);
            break;
        case 5:
            Buy(player, SuperSupeball, 500, temp, response);
            break;
        case 6:
            Buy(player, NetBall, 750, temp, response);
            break;
        case 7:
            printf("You leave the shop!\n");
            break;
    }
}