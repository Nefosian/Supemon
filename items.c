#include <stdio.h>
#include <string.h>
#include "items.h"
#include "player.h"

void itemName(Items item){
    switch (item){
        case Potion:
            printf("Potion");
            break;
        case SuperPotion:
            printf("SuperPotion");
            break;
        case RareCandy:
            printf("RareCandy");
            break;
        case Supeball:
            printf("Supeball");
            break;
        case SuperSupeball:
            printf("SuperSupeball");
            break;
        case NetBall:
            printf("NetBall");
            break;
        default:
            printf("Invalid item");
            break;
    }
}