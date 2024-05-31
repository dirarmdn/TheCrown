/* File        : dhea.h */
/* Deskripsi   :  */
/* Dibuat oleh : Dhea Dria Spralia @dheaasprla 2024 */
#include "dhira.h"
#ifndef DHEA_H
#define DHEA_H

// Define color codes for improved aesthetics
#define RESET_COLOR "\033[0m"
#define HIGHLIGHT_COLOR "\033[1;32m"  // Bright green
#define MENU_COLOR "\033[1;34m"       // Bright blue
#define TITLE_COLOR "\033[1;35m"      // Bright magenta
#define BORDER_COLOR "\033[1;36m"     // Bright cyan
#define YELLOW_COLOR "\033[1;33m"

// Tujuan : Mengisi node kosong 
void fill_node(address node, int level, const char *name, boolean gender);
// Tujuan : membandingkan poin 2 node 
int max_point(address node1, address node2);
// Tujuan : mencari node 
address search_node(address root, const char *name);
//Tujuan : memfasilitasi pertarungan antara karakter pemain yang ditentukan oleh player dengan karakter musuh yang dipilih oleh pemain.
void arena_battle(address player);
//Tujuan : menampilkan layar atau prompt yang meminta pemain untuk memasukkan nama mereka. 
void display_enter_name_screen();
//Tujuan : untuk memperbarui statistik (atribut) dari karakter yang menang dan karakter yang kalah setelah suatu pertandingan. 
void update_stats(address winner, address loser, int win_points, int lose_points);
//Gambar kastil untuk menu utama agar menu terlihat menarik
void print_kastil();

#endif
