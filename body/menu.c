#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../header/boolean.h"
#include "../header/dhira.h"

void game_menu() {
    int choice;
    int highlight = 1;
    int prev_highlight = -1;

    while (1) {
        if (highlight != prev_highlight) {
            // system("cls");
            printf("1. Battle Arena\n");
            printf("2. Election\n");
            printf("3. Exit to Main Menu\n");
            printf("4. Exit\n");
            prev_highlight = highlight;
        }

        choice = getch(); // Get input from keyboard

        switch(choice) {
            case 72: // Arrow key up
                if (highlight > 1) {
                    highlight--;
                }
                break;
            case 80: // Arrow key down
                if (highlight < 4) {
                    highlight++;
                }
                break;
            case 13: // Enter key
                switch(highlight) {
                    case 1:
                        printf("Battle Arena selected.\n");
                        break;
                    case 2:
                        printf("Election selected.\n");
                        break;
                    case 3:
                        printf("Exiting to Main Menu...\n");
                        return; // Return to previous menu
                    case 4:
                        printf("Exiting...\n");
                        exit(0);
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
        }
    }
}

void display_menu(int highlight) {
    printf("The Crown : Battle to the top\n");
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
