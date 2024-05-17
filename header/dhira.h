/* File        : dhira.h */
/* Deskripsi   : spesifikasi program*/
/* Dibuat oleh : Dhira Ramadini @dirarmdn 2024 */
#include "..\header\boolean.h"
#ifndef DHIRA_H
#define DHIRA_H

#define MENU_ITEMS 4 // Jumlah item dalam menu
#define MAX_NAME_LENGTH 50

typedef struct t_kingdom *address; 
typedef struct t_kingdom { 
    char *name;
    int age;
    boolean gender;
    int hp; // health point
    int p_pow, p_int, p_inf; // power, intelligence, influence
    address nb, fs, pr; // next brother, first son, parent
} kingdom; 
typedef address royal_tree;
address king;
address player;

// Interface

// Tujuan : menampilkan menu utama aplikasi
void display_menu(int highlight);

void game_menu(const char *name);

// Tujuan : untuk menampilkan layar "Enter Your Name"
void display_enter_name_screen();

// Tujuan : untuk menampilkan layar "Welcome" dengan nama pemain
// void display_welcome_screen(const char *name, int highlight);

// Tujuan : untuk menampilkan layar "How to Play This Game?"
void display_help_screen();

// Tujuan : untuk menampilkan layar Credits
void display_credits_screen();

// Tree Processing

// Tujuan : membuat node kosong dengan alokasi dinamis
address create_node(const char *name, int age, boolean gender, int hp, int p_pow, int p_int, int p_inf);

// Tujuan : untuk membuat struktur tree
void build_tree();

// Fungsi untuk menambahkan anak ke dalam sebuah node
void add_child(address parent, address child);

// Tujuan : untuk memilih player node
void choose_character(address player, const char *name, int age, boolean gender);

// Tujuan : untuk mencetak player node
void display_main_character ();

// Tujuan : mencetak royal family tree
void show_royal_tree();

#endif