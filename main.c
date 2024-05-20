#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/boolean.h"
#include "header/dhira.h"
#include <conio.h> // for Windows

int main() {
    int choice;
    int highlight = 1;
    int prev_highlight = -1;
    char name[50];
    int age;
    char gender;
    int start_new_game = 1;

    build_tree();

    while (1) {
        if (highlight != prev_highlight) {
            system("cls");
            display_menu(highlight);
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
                if (highlight < MENU_ITEMS) {
                    highlight++;
                }
                break;
            case 13: // Enter key
                switch(highlight) {
                    case 1:
                        if (start_new_game) {
                            system("cls");
                            printf("Starting New Game...\n");
                            printf("Enter your name: ");
                            scanf("%s", name);
                            printf("Enter your age: ");
                            scanf("%d", &age);
                            printf("Enter your gender (L/P): ");
                            scanf(" %c", &gender);
                            choose_character(name, age, gender);
                            system("cls");
                            start_new_game = 0; // Set flag to false to avoid entering name again
                        }
                        game_menu(name);
                        prev_highlight = -1; // Reset highlight to refresh the menu
                        break;
                    case 2:
                        system("cls");
                        display_help_screen();
                        printf("\nPress any key to return to the main menu...\n");
                        getch();
                        prev_highlight = -1; // Reset highlight to refresh the menu
                        break;
                    case 3:
                        system("cls");
                        display_credits_screen();
                        printf("\nPress any key to return to the main menu...\n");
                        getch();
                        prev_highlight = -1; // Reset highlight to refresh the menu
                        break;
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

    return 0;
}