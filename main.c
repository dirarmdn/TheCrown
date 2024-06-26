#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/boolean.h"
#include "header/dhira.h"
#include "header/dhea.h"
#include "header/gia.h"
#include <conio.h>

int main()
{
    int choice;
    int highlight = 1;
    int prev_highlight = -1;
    char name[50];
    int age;
    char gender;
    int start_new_game = 1;

    while (1)
    {
        if (highlight != prev_highlight)
        {
            system("cls");
            display_menu(highlight);
            prev_highlight = highlight;
        }

        choice = getch(); // Get input from keyboard

        switch (choice)
        {
        case 72: // Arrow key up
            if (highlight > 1)
            {
                highlight--;
            }
            break;
        case 80: // Arrow key down
            if (highlight < MENU_ITEMS)
            {
                highlight++;
            }
            break;
        case 13: // Enter key
            switch (highlight)
            {
            case 1:
                if (start_new_game)
                {
                    if (start_new_game == 1)
                    {
                        build_tree();
                    }
                    system("cls");
                    printf("Starting New Game...\n");
                    printf("Enter your name: ");
                    scanf("%s", name);
                    printf("Enter your gender (L/P): ");
                    scanf(" %c", &gender);
                    choose_character(name, gender);
                    display_hello(player);
                    system("cls");
                    start_new_game = 0;
                }
                game_menu(name, player);
                prev_highlight = -1; // Reset highlight to refresh the menu
                break;
            case 2:
                system("cls");
                display_help_screen();
                printf("\nPress any key to return to the main menu...\n");
                getch();
                prev_highlight = -1;
                break;
            case 3:
                system("cls");
                display_credits_screen();
                printf("\nPress any key to return to the main menu...\n");
                getch();
                prev_highlight = -1;
                break;
            case 4:
                printf("Game Scenario - Testing Area\n");
                // printf("1. Tie Condition");
                isTesting = 1;
                printf("Condition 1 : Draw");
                if (isTesting == 1)
                {
                    build_tree();
                    choose_character("MC", 0);
                    game_menu(name, player);
                }

                build_tree();
                // printf("Enter your choice:");
                // scanf("%d", scenario_choice);

                exit(0);
                prev_highlight = -1;
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
                int choice = 1;
                while (1)
                {
                    system("cls");
                    display_menu(choice);
                    choice = getch();
                }
                return 0;
            }
            break;
        }
    }

    return 0;
}