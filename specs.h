/* This is header template, create your own header */
#ifndef SPECS_H
#define SPECS_H

typedef struct t_kerajaan *address; 
typedef struct t_kerajaan { 
    char nama;
    int hp; // heath point
    int p_pow, p_int, p_inf; // power, intelligence, influence
    address nb, fs, parent; // next brother, first son, parent
} kerajaan; 
typedef address royal_tree;
typedef address king;

// menu utama

// Tujuan : menampilkan menu utama aplikasi
void display_main_menu();

// fitur arena pertandingan

// Tujuan : menampilkan menu arena game
void display_arena();

// Tujuan : membuat node kosong dengan alokasi dinamis
address create_node();

// Tujuan : Mengisi node kosong
void fill_node();

// Tujuan : untuk membuat struktur tree
void build_tree();

// Tujuan : untuk mengecek level dari tree
int level_tree();

// Tujuan : mencetak royal family tree
void show_royal_tree();

// Tujuan : membandingkan poin 2 node 
int max_point();

// Tujuan : mencari node
address search_node();

// fitur pemilihan putra mahkota

// Tujuan : menampilkan menu pemilihan
void display_stage();

// Tujuan : menampilkan adegan saat pemilihan
void display_scene();

// Tujuan : menghitung rata-rata semua poin dari node
int sum_points();

// Tujuan : menunjuk node yang menjadi putra mahkota
void crowning();

#endif