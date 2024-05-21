/* File        : GIA.h */
/* Deskripsi   :  */
/* Dibuat oleh : Firgianathyas Siti Fadillah @fnathyas 2024 */
#ifndef GIA_H
#define GIA_H
#include "dhira.h"

// Tujuan : menampilkan menu pemilihan 
void display_stage();
// Tujuan : untuk mencetak player node
void display_main_character(address node);

float calculateAverage(address node);

void crowning(address king);

void election();

// Tujuan : untuk menampilkan layar "How to Play This Game?"
void display_help_screen();

void nodes_at_level(address root, int level, address *result, int *index);

float calculateAverage(address node);

#endif