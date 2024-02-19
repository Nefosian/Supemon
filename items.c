#include <stdio.h>
#include <string.h>
#include "items.h"
#include "player.h"

void itemName(Items item, char *name){
    switch (item){
        case Potion:
            strcpy(name, "Potion");
            break;
        case SuperPotion:
            strcpy(name, "SuperPotion");
            break;
        case RareCandy:
            strcpy(name, "RareCandy");
            break;
        case Supeball:
            strcpy(name, "Supeball");
            break;
        case SuperSupeball:
            strcpy(name, "SuperSupeball");
            break;
        case NetBall:
            strcpy(name, "NetBall");
            break;
        default:
            strcpy(name, "Unknown");
            break;
    }
}