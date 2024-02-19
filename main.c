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
    Supemon supmander;
    player.supcoins = 1000;
    initializeSupasaur(&supasaur);
    initializeSupmander(&supmander);
    initializePlayer(&player);
    addItem(&player, Supeball,1);
    addItem(&player, Potion,1);
    affichage(&supasaur, &supmander, &player);
    action();
    shop(&player);
    return 0;
}
