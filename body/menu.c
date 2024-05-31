#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../header/boolean.h"
#include "../header/dhira.h"
#include "../header/gia.h"
#include "../header/dhea.h"

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
    int highlight = 1;
    int prev_highlight = -1;
    do {
        printf("\n=====================================\n");
        printf("       PEMILIHAN PUTRA/PUTRI MAHKOTA\n");
        printf("=====================================\n");
        printf("\nTampilkan Pohon Kerajaan\n");
        show_royal_tree(king, 0);

        printf("\nTampilkan Spesifikasi Karakter Utama\n");
        display_main_character(player);

		printf("\nPara Kandidat:\n");
		printLevel2Nodes(king);

        printf("\n Pilihan : \n");
        printf("1. Lakukan Pemilihan Putra atau Putri Mahkota\n");
        printf("2. Kembali\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                crowning(king);
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
                        printf("Election selected.\n");
                        crowning(king);
                        printf("\nPress any key to return to the menu...\n");
                        getch(); // Wait for key press to return to menu
                        prev_highlight = -1;
                        break;
                    case 2:
                        return;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
        }
    } while (choice != 2);
    return 0;
}


void game_menu(const char *name, address player) { // Tambahkan parameter player
    int choice;
    int highlight = 1;
    int prev_highlight = -1;

    while (1) {
        if (highlight != prev_highlight) {
            system("cls");
            printf(TITLE_COLOR " Welcome, %s! \n" RESET_COLOR, player->name);
            printf(BORDER_COLOR "===========================\n" RESET_COLOR);
            printf(TITLE_COLOR "       Royal Tree:\n" RESET_COLOR);
            show_royal_tree(king, 0);
            
            printf(TITLE_COLOR "     Your Character:\n" RESET_COLOR);
            display_main_character(player);
            
            printf("%s1. Battle Arena\n" RESET_COLOR, (highlight == 1) ? HIGHLIGHT_COLOR "> " : "  ");
            printf("%s2. Election\n" RESET_COLOR, (highlight == 2) ? HIGHLIGHT_COLOR "> " : "  ");
            printf("%s3. Exit to Main Menu\n" RESET_COLOR, (highlight == 3) ? HIGHLIGHT_COLOR "> " : "  ");
            printf("%s4. Exit\n" RESET_COLOR, (highlight == 4) ? HIGHLIGHT_COLOR "> " : "  ");
            printf(BORDER_COLOR "===========================\n" RESET_COLOR);
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

void print_kastil() {
    printf("\033[1;35m"); // Set color to magenta (pink)
    printf("   /\\                                                       /\\ \n");
    printf("  |  |                     \033[1;35mThe Crown\033[0m                       |  |\n");
    printf(" /----\\                \033[1;34mBattle to the top\033[0m                  /----\\\n");
    printf("[______]                                                 [______]\n");
    printf("|    |         \033[1;35m_____\033[0m                        \033[1;35m_____\033[0m         |    |\n");
    printf("|[]  |        \033[1;35m[     ]\033[0m                      \033[1;35m[     ]\033[0m        |  []|\n");
    printf("|    |       \033[1;35m[_______][ ][ ][ ][][ ][ ][ ][_______]\033[0m       |    |\n");
    printf("|    [ ][ ][ ]\033[1;34m|     |  ,----------------,  |     |\033[0m[ ][ ][ ]    |\n");
    printf("|             \033[1;34m|     |/'    ____..____    '\\|     |\033[0m             |\n");
    printf("\\  []         \033[1;34m|     |    /'    ||    '\\    |     |\033[0m        []   /\n");
    printf("|      []     \033[1;34m|     |   |o     ||     o|   |     |\033[0m  []         |\n");
    printf("|             \033[1;34m|  _  |   |     _||_     |   |  _  |\033[0m             |\n");
    printf("|   []        \033[1;34m| (_) |   |    (_||_)    |   | (_) |\033[0m       []    |\n");
    printf("|             \033[1;34m|     |   |     (||)     |   |     |\033[0m             |\n");
    printf("|             \033[1;34m|     |   |      ||      |   |     |\033[0m             |\n");
    printf("/''           \033[1;34m|     |   |o     ||     o|   |     |\033[0m           ''\\\n");
    printf("[_____________\033[1;35m[_______]--'------''------'--[_______]\033[0m_____________]\n");
    printf("\033[0m"); // Reset color
}

void display_menu(int highlight) {
    print_kastil();
    char *menu_items[] = {"Start New Game", "Help", "Credits", "Game Scenario", "Exit"};
    int num_menu_items = sizeof(menu_items) / sizeof(menu_items[0]); // Calculate the number of menu items

    int i; // Declare the loop variable outside the loop
    for (i = 0; i < num_menu_items; i++) {
        if(highlight == i + 1) {
            printf(HIGHLIGHT_COLOR "-> %d. %s\n" RESET_COLOR, i + 1, menu_items[i]);
        } else {
            printf("   %d. %s\n", i + 1, menu_items[i]);
        }
    }
}

void display_enter_name_screen() {
    printf(MENU_COLOR "Enter your name: " RESET_COLOR);
}

void display_help_screen() {
    printf("\033[1;35m"); //pink
    printf("\n ============================= CARA UNTUK MEMAINKAN THE CROWN ============================== \n");
    printf("\033[0m"); 

    printf("\033[1;32m"); 
    printf(" Tujuan : \n");
    printf("\033[0m"); 

    printf(" The Crown merupakan Game Roleplay \n");
    printf(" Game ini bertujuan untuk menentukan pada siapa gelar putra/putri mahkota diberikan \n");

    printf("\033[1;32m"); 
    printf("\n Cara memainkan The Crown\n");
    printf("\033[0m"); 

    printf(" Pemain harus mengimputkan nama dan jenis kelamin terlebih dahulu\n");
    printf(" Dalam Game ini anda memerankan sebagai seorang putra / putri seorang Raja \n");
    printf(" Untuk memenangkan permainan ini anda harus terpilih menjadi seorang putra/putri mahkota\n");

    printf("\033[1;32m"); 
    printf("\n Fitur yang dapat anda pilih adalah fitur pertandingan atau pemilihan\n");
    printf("\033[0m"); 

    printf("\033[1;34m"); 
    printf("\n Dalam pertandingan pemain diharuskan memasukan nama lawan\n");
    printf("\033[0m"); 

    printf(" Nama lawan harus sama persis seperti nama dalam silsilah keluarga yang ditampilkan\n");
    printf("\t Setiap kamu melakukan pertandingan \033[1;31mHP point\033[0m mu itu berkurang 10 point\n"); // Set color to red for HP point
    printf("\t Setiap kamu memenangkan pertandingan \033[1;32mpoint pow, int, inf\033[0m mu bertambah 10 point\n"); // Set color to green for pow, int, inf
    printf("\t Setiap kamu kalah dalam pertandingan \033[1;31mpoint pow, int, inf\033[0m mu berkurang 10 point\n"); // Set color to red for pow, int, inf

    printf("\033[1;34m"); 
    printf("\n Dalam pemilihan putra/putri mahkota kandidat yang berhak hanyalah anak dari King\n");
    printf("\033[0m"); 

    printf(" Dalam penentuan putra/putri mahkota point dari \033[1;32mpow, int, dan inf\033[0m sangat berpengaruh\n"); // Set color to green for pow, int, inf

    printf("\033[1;35m"); 
    printf("\n\n ======================================= HAVE FUN!!! ======================================= \n");
    printf("\033[0m"); 
}


void display_credits_screen() {
    printf(MENU_COLOR "Our Team:\n" RESET_COLOR);
    printf("Dhea Dria Spralia (231511040)\n");
    printf("Dhira Ramadini (231511041)\n");
    printf("Firgianathyas Siti Fadillah (231511047)\n");
}