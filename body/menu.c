#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../header/boolean.h"
#include "../header/dhira.h"
#include "../header/gia.h"

void game_menu(const char *name) {
    int choice;
    int highlight = 1;
    int prev_highlight = -1;

    while (1) {
        if (highlight != prev_highlight) {
            system("cls");
            printf("Welcome, %s!\n", name);
            printf("Royal Tree:\n");
            show_royal_tree(king, 0);
            printf("%s1. Battle Arena\n", (highlight == 1) ? "> " : "  ");
            printf("%s2. Election\n", (highlight == 2) ? "> " : "  ");
            printf("%s3. Exit to Main Menu\n", (highlight == 3) ? "> " : "  ");
            printf("%s4. Exit\n", (highlight == 4) ? "> " : "  ");
            prev_highlight = highlight;
        }

        choice = getch(); // Get input from keyboard

        switch(choice) {
            case 72: // Up arrow
                if (highlight > 1) {
                    highlight--;
                }
                break;
            case 80: // Down arrow
                if (highlight < 4) {
                    highlight++;
                }
                break;
            case 13: // Enter
                switch(highlight) {
                    case 1:
                        system("cls");
                        printf("Battle Arena selected.\n");
                        arena_battle(player);
                        printf("\nPress any key to return to the menu...\n");
                        getch(); // Wait for key press to return to menu
                        break;
                    case 2:
                        system("cls");
                        printf("Election selected.\n");
                        printf("\nPress any key to return to the menu...\n");
                        getch(); // Wait for key press to return to menu
                        break;
                    case 3:
                        return; // Exit to main menu
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
    char *menu_items[] = {"Start New Game", "Help", "Credits", "Exit"};
    int num_menu_items = sizeof(menu_items) / sizeof(menu_items[0]); // Calculate the number of menu items

    int i; // Declare the loop variable outside the loop
    for (i = 0; i < num_menu_items; i++) {
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

void arena_battle(address player) {
    char enemy_name[50];
    address enemy;
    int winner;

    show_royal_tree(king, 0);
    display_main_character(player);

    if (player->hp >
     10) {
        printf("Masukkan lawan: ");
        scanf("%s", enemy_name);
        enemy = search_node(king, enemy_name);
        display_main_character(enemy);

        winner = max_point(player, enemy);

        if (winner == 1) {
            printf("Congratulations, You win the battle!");
            player->p_inf += 10;
            player->p_int += 10;
            player->p_pow += 10;
            enemy->p_inf -= 10;
            enemy->p_int -= 10;
            enemy->p_pow -= 10;
        } else if (winner == 2) {
            printf("You Lose, try again next time");
            player->p_inf -= 10;
            player->p_int -= 10;
            player->p_pow -= 10;
            enemy->p_inf += 10;
            enemy->p_int += 10;
            enemy->p_pow += 10;
        } else {
            printf("It's a tie, try again next time");
        }

        player->hp -= 10;
        enemy->hp -= 10;
    } else {
        printf("Your health is too low, you cannot participate in a battle anymore.\nPlease proceed to the election.");
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

// void arena_battle(address player) {
//     char enemy_name[50];
//     address enemy;

//     show_royal_tree(king, 0);
//     display_main_character(player);
//     printf("Masukkan lawan: ");
//     scanf("%s", enemy_name);
//     enemy = find_enemy_by_name(king, enemy_name); // Assuming you have a function to find the enemy by name
//     max_point(player, enemy);
// }