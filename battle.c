//
// Created by Elise on 18/02/2024.
//

#include "battle.h"
#include "supemon.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void supemonAttack(Supemon *attacker, Supemon *defender);


void supemonBattle(Supemon *supemon1, Supemon *supemon2) {
    if (supemon1 == NULL || supemon2 == NULL) {
        printf("Erreur : Un des Supémons est invalide (NULL).\n");
        return;
    }

    supemonAttack(supemon1, supemon2);
}

void supemonAttack(Supemon *attacker, Supemon *defender) {
    if (attacker == NULL || defender == NULL) {
        printf("Erreur : Attaquant ou défenseur invalide (NULL).\n");
        return;
    }

    int baseDamage = 3;
    int finalDamage;
    double hitChance;

    srand((unsigned int)time(NULL));

    hitChance = (double)attacker->Precision / (attacker->Precision + defender->Dodge) + 0.1;

    if ((rand() % 100) < (hitChance * 100)) {
        finalDamage = attacker->Attack * baseDamage / defender->Defense;

        if (rand() % 2) {
            finalDamage++;
        }
        defender->currentLife -= finalDamage;
        printf("%s inflige %d dégâts à %s.\n", attacker->name, finalDamage, defender->name);
    } else {
        printf("%s esquive l'attaque de %s.\n", defender->name, attacker->name);
    }

    if (defender->currentLife <= 0) {
        printf("%s est vaincu!\n", defender->name);
    }
}
