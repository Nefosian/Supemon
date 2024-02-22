//
// Created by Elise on 16/02/2024.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ui.h"
#include "items.h"
#include "supemon.h"
#include "action.h"


void welcomeScreen(Player *player){
    int choice = 0;
    printf("+-<3----<3----<3----<3----<3------+\n");
    printf("| Welcome in Supemon World!       |\n");
    printf("| What do you want to do?         |\n");
    printf("| 1- New game                     |\n");
    printf("| 2- Load a game                  |\n");
    printf("| 3- Leave the game               |\n");
    printf("+-<3----<3----<3----<3----<3------+\n");


    while (choice < 1 || choice > 2) {
        printf("Choice 1, 2 or 3 : \n");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                startNewGame(player);
                break;
            case 2:
                loadGame(player);
                break;
            case 3:
                printf("You leave the game!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter 1,2 or 3\n");
                choice = 0;
                break;
        }
    }
}

void PlayerData(Player *player) {
    char filename[100];
    sprintf(filename, "%s.txt", player->name);

    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error creating file %s.\n", filename);
        return;
    }
    fprintf(file, "Name: %s\nAge: %d\nSupcoins: %d\n", player->name, player->age, player->supcoins);
    fprintf(file, "Number of Items in inventory: %d\n", player->numberItems);

    for (int i = 0; i < player->numberItems; i++) {
        char itemName[30];
        itemNameChoose(player->objets[i].item, itemName);
        fprintf(file, "Item %d: %s, Quantity: %d\n", i + 1, itemName, player->objets[i].quantity);
    }
    fprintf(file, "Number of Supemons in Deck: %d\n", player->numberDeckSupemons);
    for (int i = 0; i < player->numberDeckSupemons; i++) {
        fprintf(file, "Deck Supemon %d: %s, Level: %d, HP: %d, Attack: %d, Defense: %d, Speed: %d, Dodge: %d\n",
                i + 1,
                player->deckSupemons[i].name,
                player->deckSupemons[i].level,
                player->deckSupemons[i].currentLife,
                player->deckSupemons[i].Attack,
                player->deckSupemons[i].Defense,
                player->deckSupemons[i].Speed,
                player->deckSupemons[i].Dodge);
    }
    fprintf(file, "Number of Supemons in collection: %d\n", player->numberSupemons);
    for (int i = 0; i < player->numberSupemons; i++) {
        fprintf(file, "Collection Supemon %d: %s, Level: %d, HP: %d, Attack: %d, Defense: %d, Speed: %d, Dodge: %d\n",
                i + 1,
                player->collectionSupemons[i].name,
                player->collectionSupemons[i].level,
                player->collectionSupemons[i].currentLife,
                player->collectionSupemons[i].Attack,
                player->collectionSupemons[i].Defense,
                player->collectionSupemons[i].Speed,
                player->collectionSupemons[i].Dodge);
    }

    fclose(file);
    printf("Game data saved to %s\n", filename);
}

void startNewGame(Player *player){
    initializePlayer(player);
    PlayerData(player);
}

void itemNameChoose(Items item, char* outName) {
    switch (item) {
        case Potion: strcpy(outName, "Potion"); break;
        case SuperPotion: strcpy(outName, "SuperPotion"); break;
        case RareCandy: strcpy(outName, "RareCandy"); break;
        case Supeball: strcpy(outName, "Supeball"); break;
        case SuperSupeball: strcpy(outName, "SuperSupeball"); break;
        case NetBall: strcpy(outName, "NetBall"); break;
        default: strcpy(outName, "Invalid item"); break;
    }
}

void loadGame(Player *player){
    char filename[256];
    printf("Enter the filename to load: \n");
    scanf("%255s", filename);
    while (getchar() != '\n'); 

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s for loading.\n", filename);
        return;
    }
    memset(player, 0, sizeof(Player));

    fscanf(file, "Name: %79[^\n]\n", player->name);
    fscanf(file, "Age: %d\n", &player->age);
    fscanf(file, "Supcoins: %d\n", &player->supcoins);

    fscanf(file, "Number of Items in inventory: %d\n", &player->numberItems);
    for (int i = 0; i < player->numberItems && i < maxItem; i++) {
        int nb; 
        char itemName[30];
        int quantity;
        fscanf(file, "Item %d: %29[^,], Quantity: %d\n", &nb, itemName, &quantity);
        player->objets[i].item = itemNameToEnum(itemName);
        player->objets[i].quantity = quantity;
    }
    printf("Number of Items in inventory: %d\n", player->numberItems);

    fscanf(file, "Number of Supemons in Deck: %d\n", &player->numberDeckSupemons);
    for (int i = 0; i < player->numberDeckSupemons && i < deckSize; i++) {
        int nb;
        fscanf(file, "Deck Supemon %d: %79[^,], Level: %d, HP: %d, Attack: %d, Defense: %d, Speed: %d, Dodge: %d\n",
               &nb, player->deckSupemons[i].name, &player->deckSupemons[i].level, &player->deckSupemons[i].currentLife,
               &player->deckSupemons[i].Attack, &player->deckSupemons[i].Defense, &player->deckSupemons[i].Speed,
               &player->deckSupemons[i].Dodge);
    }
    printf("Number of Supemon in deck: %d\n", player->numberDeckSupemons);

    fscanf(file, "Number of Supemons in collection: %d\n", &player->numberSupemons);
    for (int i = 0; i < player->numberSupemons && i < maxSize; i++) {
        int nb;
        fscanf(file, "Collection Supemon %d: %79[^,], Level: %d, HP: %d, Attack: %d, Defense: %d, Speed: %d, Dodge: %d\n",
               &nb, player->collectionSupemons[i].name, &player->collectionSupemons[i].level, &player->collectionSupemons[i].currentLife,
               &player->collectionSupemons[i].Attack, &player->collectionSupemons[i].Defense, &player->collectionSupemons[i].Speed,
               &player->collectionSupemons[i].Dodge);
    }
    printf("Number of Supemon in collection: %d\n", player->numberSupemons);

    fclose(file);
    printf("Game successfully loaded from %s\n", filename);
    printf("Welcome back %s!\n", player->name);
    action();
}

Items itemNameToEnum(const char* itemName) {
    if (strcmp(itemName, "Potion") == 0) return Potion;
    if (strcmp(itemName, "SuperPotion") == 0) return SuperPotion;
    if (strcmp(itemName, "RareCandy") == 0) return RareCandy;
    if (strcmp(itemName, "Supeball") == 0) return Supeball;
    if (strcmp(itemName, "SuperSupeball") == 0) return SuperSupeball;
    if (strcmp(itemName, "NetBall") == 0) return NetBall;
    return EmptySlot;
}

void initializePlayer(Player *player){
    int choice = 0;
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
    printf("Welcome in Supemon World! Have a good game\n");

    printf("+-<3----<3----<3----<3----<3----<3-------+\n");
    printf("|Choose your starter Supemon:            |\n");
    printf("| 1 - Supmander                          |\n");
    printf("| 2 - Supasaur                           |\n");
    printf("| 3 - Supirtle                           |\n");
    printf("+----------------------------------------+\n\n");

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

    Supemon starterSupemon;
    initializeSupemon(&starterSupemon, choice);
    player->supcoins = 1000;
    addItem(player,Potion,5);
    addItem(player,Supeball,5);
    player->numberSupemons = 0;
    player->numberDeckSupemons = 0;
    printf("You have chosen %s as your starter Supemon!\n", starterSupemon.name);
    addSupemonToDeck(player, starterSupemon);
}