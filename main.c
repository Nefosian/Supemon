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
    Supemon defender;
    player.supcoins = 1000;
    initializeSupfox(&player);
    welcomeScreen(&player);
    return 0;
}
