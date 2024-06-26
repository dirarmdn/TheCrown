/* File        : dhira.h */
/* Deskripsi   : spesifikasi program*/
/* Dibuat oleh : Dhira Ramadini @dirarmdn 2024 */
#include "..\header\boolean.h"
#ifndef DHIRA_H
#define DHIRA_H

#define MENU_ITEMS 5 // Jumlah item dalam menu
#define MAX_NAME_LENGTH 50

typedef struct t_kingdom *address;
typedef struct t_kingdom
{
    char *name;
    int age;
    boolean gender;
    int hp;                  // health point
    int p_pow, p_int, p_inf; // power, intelligence, influence
    address nb, fs, pr;      // next brother, first son, parent
    boolean isCrowned;             // pernah terpilih (sebagai putra/putri mahkota)
} kingdom;
typedef address royal_tree;
address king;
address player;
boolean isTesting;

// Interface

// Tujuan : menampilkan menu utama aplikasi
void display_menu(int highlight);

// Tujuan : menjalankan menu utama
void game_menu(const char *name, address player);

// Tujuan : untuk menampilkan layar Credits
void display_credits_screen();

// Tujuan : membuat node kosong dengan alokasi dinamis
address create_node();

// Tujuan : untuk membuat struktur tree
void build_tree();

// Tujuan: untuk menambahkan anak ke dalam sebuah node
void add_child(address parent, address child);

// Tujuan : untuk memilih player node
void choose_character(const char *name, char gender);

// Tujuan : mencetak royal family tree
void show_royal_tree(address root, int level);

// Tujuan : untuk mencetak ucapan selamat datang di sebelum menu awal
void display_hello(address player);

// Tujuan untuk mencetak informasi kesalahan pada program
void error_handling(int error_type, char *error_msg);
#endif