#include "items.h"
#include "supemon.h"

#define max_supemons 300
#define max_items 20

typedef struct{
    Items items[max_items];
    int itemsCounts[max_items];
    Supemon supemons[max_supemons]; 
} PlayerInvotory;

void addItem(PlayerInvotory *inventory, Items item, int quantity);
