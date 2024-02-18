#include "items.h"
#include "supemon.h"
#include "player.h"

#define max_supemons 300
#define max_items 20

typedef struct{
    Items items[max_items];
    int itemsCounts[max_items];
    Supemon supemons[max_supemons]; 
} PlayerInventory;

void addItem(Player *player, Items item, int quantity);
void removeItem(Player *player, Items item, int quantity);
void addSupemon(Player *player, Supemon newSupemon);
void removeSupemon(Player *player, Supemon supemon);
int hasItem(const Player *player, Items item);
void useItem(Player *player, Items item);
