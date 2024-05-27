#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../header/boolean.h"
#include "../header/dhira.h"
#include "../header/gia.h"

void arena_battle(address player) {
    int choice;
    char enemy_name[50];
    address enemy;
    int winner;

    while (1) {
        system("cls"); // Bersihkan layar setiap kali masuk loop
        show_royal_tree(king, 0);
        printf("\nYour Character:\n");
        display_main_character(player);

        printf("\n1. Mulai Pertandingan\n");
        printf("2. Kembali ke Menu Utama\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (player->hp > 10) {
                    system("cls");
                    show_royal_tree(king, 0);
                    printf("Masukkan lawan: ");
                    scanf("%s", enemy_name);
                    enemy = search_node(king, enemy_name);
                    printf("\nYour Enemy:\n");
                    display_main_character(enemy);

                    winner = max_point(player, enemy);

                    if (winner == 1) {
                    printf("Congratulations, You win the battle!\n");
                    update_stats(player, enemy, 10, 10);
                } else if (winner == 2) {
                    printf("You Lose, try again next time\n");
                    update_stats(enemy, player, 10, 10);
                } else {
                    printf("It's a tie, try again next time\n");
                }

                    player->hp -= 10;
                    enemy->hp -= 10;
                } else {
                    printf("Your health is too low, you cannot participate in a battle anymore.\nPlease proceed to the election.\n");
                }
                printf("\nPress any key to return to the menu...\n");
                getch();
                break;
            case 2:
                return; // Kembali ke menu utama
            default:
                printf("Pilihan tidak valid!\n");
                printf("Press any key to try again...\n");
                getch();
                break;
        }
    }
}

void election(address player) { // Tambahkan parameter player
    int choice;
    do {
        system("cls"); // Bersihkan layar setiap kali masuk loop
        printf("\n=====================================\n");
        printf("       PEMILIHAN PUTRA/PUTRI MAHKOTA\n");
        printf("=====================================\n");
        printf("\nTampilkan Pohon Kerajaan\n");
        show_royal_tree(king, 0);
        
        printf("\nYour Character:\n");
        display_main_character(player);
        
        printf("\n Pilihan : \n");
        printf("1. Lakukan Pemilihan Putra atau Putri Mahkota\n");
        printf("2. Keluar kembali ke menu utama\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                crowning(king);
                printf("\nPress any key to return to the menu...\n");
                getch();
                break;
            case 2:
                printf("Terima kasih!\n"); // ini harusnya balik ke menu utama
                return; // Keluar dari loop dan kembali ke menu utama
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (choice != 2);
}

void game_menu(const char *name, address player) { // Tambahkan parameter player
    int choice;
    int highlight = 1;
    int prev_highlight = -1;

    while (1) {
        if (highlight != prev_highlight) {
            system("cls");
            printf("Welcome, %s!\n", name);
            printf("Royal Tree:\n");
            show_royal_tree(king, 0);
            printf("\nYour Character:\n");
            display_main_character(player);
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
                        prev_highlight = -1;
                        break;
                    case 2:
                        system("cls");
                        printf("Election selected.\n");
                        election(player); // Panggil election dengan parameter player
                        printf("\nPress any key to return to the menu...\n");
                        getch(); // Wait for key press to return to menu
                        prev_highlight = -1;
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
    char *menu_items[] = {"Start New Game", "Help", "Credits", "Game Scenario", "Exit"};
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