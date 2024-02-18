#include <stdio.h>
#include "ui.h"
#include "items.h"
#include "supemon.h"
#include "action.h"
#include "shop.h"

int main() {
    Player player;
    player.supcoins = 1000;
    initializePlayer(&player);
    action();
    shop(&player);
    return 0;
}
