#include <stdio.h>
#include "ui.h"
#include "items.h"
#include "supemon.h"
#include "action.h"
#include "shop.h"
#include "battle.h"
#include <time.h>

int main() {
    Player player;
    Supemon supasaur;
    Supemon supmander;
    player.supcoins = 1000;
    player.objets=Potion;
    initializeSupasaur(&supasaur);
    initializeSupmander(&supmander);
    initializePlayer(&player);
    affichage(&supasaur, &supmander, &player);
    action();
    shop(&player);
    return 0;
}
