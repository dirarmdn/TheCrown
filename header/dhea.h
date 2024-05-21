/* File        : dhea.h */
/* Deskripsi   :  */
/* Dibuat oleh : Dhea Dria Spralia @dheaasprla 2024 */
#include "dhira.h"
#ifndef DHEA_H
#define DHEA_H

// Tujuan : Mengisi node kosong 
void fill_node(address node, int level, const char *name, boolean gender);
// Tujuan : membandingkan poin 2 node 
int max_point(address node1, address node2);
// Tujuan : mencari node 
address search_node(address root, const char *name);
// Tujuan : menampilkan menu pemilihan 
void display_stage();

void arena_battle(address player);

void display_enter_name_screen();

#endif
