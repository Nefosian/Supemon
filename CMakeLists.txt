cmake_minimum_required(VERSION 3.24)
project(SUPEMON C)

set(CMAKE_C_STANDARD 11)

add_executable(SUPEMON supemon.h supemon.c player.h player.c shop.h shop.c items.h items.c save.h save.c game_det.h game_det.c ui.h ui.c move_cat.h skill_cat.h main.c
        action.c
        action.h
        battle.c
        inventory.c
        deck.c
        deck.h
        center.c
        center.h
)
