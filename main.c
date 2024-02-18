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
    Supemon supasaur, defender;
    player.supcoins = 1000;
    initializeSupasaur(&supasaur);
    initializeSupasaur(&defender);
    initializePlayer(&player);
    
    affichage(&supasaur, &defender, &player);
    action();
    shop(&player);
    return 0;
}
