#include <stdio.h>
#include "ui.h"
#include "items.h"
#include "supemon.h"
#include "action.h"
#include "shop.h"
#include "battle.h"
#include <time.h>
#include "inventory.h"
#include "player.h"


int main() {
    Player player;
    Supemon supasaur;
    Supemon supfox;
    player.supcoins = 1000;
    initializeSupasaur(&supasaur);
    initializeSupfox(&supfox);
    initializePlayer(&player);
    addItem(&player, RareCandy,1);
    addItem(&player, Supeball,1);
    affichage(&supasaur, &supfox, &player);
    action();
    shop(&player);
    return 0;
}
