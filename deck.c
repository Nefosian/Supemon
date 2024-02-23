#include "deck.h"
#include <stdio.h>
#include <string.h>
#include "supemon.h"
#include "player.h"


void initializeDeck(Player *player) {
    if (player == NULL) {
        printf("Error: Cannot initialize deck, player data is null.\n");
        return;
    }

    player->numberDeckSupemons = 0; 
    printf("Deck initialized successfully.\n");
}

void displayDeck(const Player *player) {
    if (player == NULL) {
        printf("Error: Cannot display deck, player data is null.\n");
        return;
    }

    printf("Number of Supemons in deck: %d\n", player->numberDeckSupemons);
    if (player->numberDeckSupemons == 0) {
        printf("The deck is currently empty.\n");
        return;
    }

    printf("+-<3----<3----<3----<3----<3----<3-----+\n");
    printf("| Your current Supemon deck:           |\n");
    for (int i = 0; i < player->numberDeckSupemons; i++) {
        printf("| %d - %s, Level: %d, HP: %d/%d    |\n", 
               i + 1, 
               player->deckSupemons[i].name, 
               player->deckSupemons[i].level, 
               player->deckSupemons[i].currentLife, 
               player->deckSupemons[i].maxLife);
    }
    printf("+---------------------------------------+\n\n");
}


void addSupemonToDeck(Player *player, Supemon newSupemon) {
    if (player == NULL) {
        printf("Error: Cannot add Supemon to deck, player data is null.\n");
        return;
    }
    if (player->numberDeckSupemons >= deckSize) {
        printf("Error: Deck is full. Please remove a Supemon before adding a new one.\n");
        return;
    }

    player->deckSupemons[player->numberDeckSupemons++] = newSupemon;
    printf("Supemon %s successfully added to the deck.\n", newSupemon.name);
}

void replaceSupemonInDeck(Player *player, int deckPosition, Supemon newSupemon) {
    if (player == NULL) {
        printf("Error: Cannot replace Supemon in deck, player data is null.\n");
        return;
    }

    if (deckPosition < 1 || deckPosition > deckSize) {
        printf("Error: Invalid deck position. Please select a position between 1 and %d.\n", deckSize);
        return;
    }

    if (deckPosition > player->numberDeckSupemons) {
        printf("Error: The specified position is currently empty. Use addSupemonToDeck to add new Supemons.\n");
        return;
    }

    player->deckSupemons[deckPosition - 1] = newSupemon;
    printf("Supemon %s successfully replaced in position %d of the deck.\n", newSupemon.name, deckPosition);
}

void removeSupemonFromDeck(Player *player, int deckPosition) {
    if (player == NULL) {
        printf("Error: Cannot remove Supemon from deck, player data is null.\n");
        return;
    }

    if (deckPosition < 1 || deckPosition > deckSize) {
        printf("Error: Invalid deck position. Please select a position between 1 and %d.\n", deckSize);
        return;
    }

    if (deckPosition > player->numberDeckSupemons) {
        printf("Error: The specified position is currently empty. Use addSupemonToDeck to add new Supemons.\n");
        return;
    }

    for (int i = deckPosition - 1; i < player->numberDeckSupemons - 1; i++) {
        player->deckSupemons[i] = player->deckSupemons[i + 1];
    }
    player->numberDeckSupemons--;
    printf("Supemon successfully removed from position %d of the deck.\n", deckPosition);
}

void changeSupemon(Player *player, int deckPosition) {
    if (player == NULL) {
        printf("Error: Cannot change Supemon, player data is null.\n");
        return;
    }

    if (deckPosition < 1 || deckPosition > player->numberDeckSupemons) {
        printf("Error: Invalid deck position. Please select a position between 1 and %d.\n", player->numberDeckSupemons);
        return;
    }

    if (player->supemonSelected == &player->deckSupemons[deckPosition - 1]) {
        printf("Error: The selected Supemon is already the one in battle.\n");
        return;
    }

    player->supemonSelected = &player->deckSupemons[deckPosition - 1];
    printf("Supemon %s is now selected for battle!\n", player->supemonSelected->name);
}