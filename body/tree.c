#include <stdio.h>
#include <stdlib.h>

// Definisi struktur data
typedef struct t_kerajaan *address;
typedef struct t_kerajaan {
    char nama;
    int hp; // health point
    int p_pow, p_int, p_inf; // power, intelligence, influence
    address nb, fs, parent; // next brother, first son, parent
} kerajaan;
typedef address royal_tree;
typedef address king;

void fill_node(address node, int level) {
    if (node == NULL)
        return;

    switch (level) {
        case 0: // King
            node->hp = 100;
            node->p_pow = 100;
            node->p_int = 100;
            node->p_inf = 100;
            break;
        case 1: // Queen and King�s Mistresses
            node->hp = 100;
            node->p_pow = rand() % 61 + 20; // 20-80
            node->p_int = rand() % 71 + 30; // 30-100
            node->p_inf = rand() % 51 + 50; // 50-100
            break;
        case 2: // King�s Child
            node->hp = 100;
            node->p_pow = rand() % 41 + 30; // 30-70
            node->p_int = rand() % 41 + 30; // 30-70
            node->p_inf = rand() % 41 + 30; // 30-70
            break;
        case 3: // King�s Child Spouse
            node->hp = 100;
            node->p_pow = rand() % 21 + 20; // 20-40
            node->p_int = rand() % 21 + 20; // 20-40
            node->p_inf = rand() % 41 + 20; // 20-60
            break;
        case 4: // King�s Grandchild
            node->hp = 100;
            node->p_pow = rand() % 41; // 0-40
            node->p_int = rand() % 41; // 0-40
            node->p_inf = rand() % 41; // 0-40
            break;
        default:
            break;
    }
}
#include <string.h>
#include "../header/dhira.h"

address create_node(const char *name, int age, boolean gender, int hp, int p_pow, int p_int, int p_inf) {
    address p_new;
    
    p_new = (address)malloc(sizeof(kingdom));
    if (p_new == NULL) {
        printf("Gagal Alokasi\n");
    }

    // Alokasi memori untuk menyimpan nama
    p_new->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    if (p_new->name == NULL) {
        printf("Gagal Alokasi\n");
        free(p_new);
        return NULL;
    }

    // Salin nama ke dalam struktur
    strcpy(p_new->name, name);
    p_new->gender = gender;
    p_new->age = age;
    p_new->hp = hp;
    p_new->p_pow = p_pow;
    p_new->p_int = p_int;
    p_new->p_inf = p_inf;
    p_new->fs = NULL;
    p_new->nb = NULL;
    return p_new;
}

void add_child(address parent, address child) {
    if (parent->fs == NULL) {
        parent->fs = child;
    } else {
        address sibling = parent->fs;
        while (sibling->nb != NULL) {
            sibling = sibling->nb;
        }
        sibling->nb = child;
    }
}

void show_royal_tree(address node, int depth) {
    if (node == NULL) return;
    printf("%*c", depth * 4, ' ');
    if (depth == 0) {
        printf("King ");
    } else if (depth == 1 && node->gender == 0) {
        printf("Queen ");
    } else if (depth == 1 && node->gender == 1) {
        printf("Mistress ");
    } else if (depth > 1 && node->gender == 0) {
        printf("Prince ");
    } else if (depth > 1 && node->gender == 1) {
        printf("Princess ");
    }
    printf("%s\n", node->name); // Print the entire name
    show_royal_tree(node->fs, depth + 1); // print first son recursively
    show_royal_tree(node->nb, depth); // print next brother recursively at the same depth
}


void build_tree() {
    king = create_node("George", 56, 1, 100, 90, 80, 95);
    address queen = create_node("Mary", 45, 0, 95, 85, 90, 95);
    address first_prince = create_node("Edward", 26, 1, 90, 85, 80, 90);
    address first_princess = create_node("Elizabeth", 23, 0, 85, 80, 85, 90);
    address second_princess = create_node("Victoria", 23, 0, 85, 80, 85, 90);

    add_child(king, queen);
    add_child(queen, first_prince);
    add_child(queen, first_princess);
    add_child(first_prince, create_node("Philip", 13, 0, 80, 75, 70, 85));
    add_child(first_princess, create_node("Selene", 12, 1, 80, 75, 70, 85));

    address mistress = create_node("Rashta", 35, 1, 95, 85, 90, 95);
    address second_prince = create_node("Richard", 20, 0, 90, 85, 80, 90);
    address thePrincess3 = create_node("Charlotte", 10, 1, 85, 80, 85, 90);
    address thePrincess4 = create_node("Anne", 8, 1, 85, 80, 85, 90);
    address thePrincess5 = create_node("Caroline", 3, 1, 85, 80, 85, 90);

    add_child(king, mistress);
    add_child(mistress, second_prince);
    add_child(mistress, second_princess);
    add_child(second_prince, create_node("Louis", 2, 0, 80, 75, 70, 85));
    add_child(second_princess, create_node("Lorde", 1, 1, 80, 75, 70, 85));
    add_child(second_princess->fs, create_node("Shuri", 1, 1, 80, 75, 70, 85));
}

void choose_character(address player, const char *name, int age, boolean gender) {
    if (gender == 0)
    {
        
    }
    
}

void display_main_character () {
    
}
