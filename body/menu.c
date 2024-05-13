#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/boolean.h"
#include "../header/dhira.h"

void display_menu(int highlight) {
    printf("Menu Awal\n");
    char *menu_items[MENU_ITEMS] = {"Start New Game", "Help", "Credits", "Exit"};
    for (int i = 0; i < MENU_ITEMS; i++) {
        if(highlight == i + 1) {
            printf("-> %d. %s\n", i + 1, menu_items[i]);
        } else {
            printf("%d. %s\n", i + 1, menu_items[i]);
        }
    }
}

void display_enter_name_screen() {
    printf("Enter your name: ");
}

void display_welcome_screen(const char *name, int highlight) {
    printf("Welcome, %s!\n", name);
    printf("Royal Tree:\n");
    show_royal_tree(king, 0);
    char *menu_items[MENU_ITEMS] = {"Battle Arena", "Election", "Exit to Main Menu", "Exit"};
    for(int i = 0; i < MENU_ITEMS; i++) {
        if(highlight == i + 1) {
            printf("%d. %s\n", i + 1, menu_items[i]);
        } else {
            printf("%d. %s\n", i + 1, menu_items[i]);
        }
    }
}

void display_help_screen() {
    printf("How to play this game?\n");
    printf("Instructions.\n");
}

void display_credits_screen() {
    printf("Our Team:\n");
    printf("Dhea Dria Spralia (231511040)\n");
    printf("Dhira Ramadini (231511041)\n");
    printf("Firgianathyas Siti Fadillah (231511047)\n");
}
