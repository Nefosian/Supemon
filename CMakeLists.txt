cmake_minimum_required(VERSION 3.24)
project(SUPEMON C)

set(CMAKE_C_STANDARD 11)

add_executable(SUPEMON supemon.h supemon.c player.h shop.h shop.c items.h items.c ui.h ui.c move_cat.h skill_cat.h main.c
        action.c
        action.h
        battle.c
        inventory.c
        deck.c
        deck.h
        center.c
        center.h
)
