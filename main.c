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
    char gender;

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
                        system("cls");
                        printf("Starting New Game...\n");
                        printf("Enter your name: ");
                        scanf("%s", name);
                        printf("Enter your gender (L/P): ");
                        scanf(" %c", &gender); //kok berhenti disini sih
                        system("cls");
                        printf("Hello, %s! Welcome to the game!\n", name);
                        printf("Royal Tree:\n");
                        show_royal_tree(king, 0);
                        game_menu();
                        break;
                    case 2:
                        printf("Help selected.\n");
                        break;
                    case 3:
                        printf("Credits selected.\n");
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
