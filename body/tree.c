#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/dhira.h"
#include "../header/dhea.h"

address create_node() {
    address node;
    
    node = (address)malloc(sizeof(kingdom));
    if (node == NULL) {
        printf("Gagal Alokasi\n");
        exit(1);
    }

    node->pr = NULL;
    node->fs = NULL;
    node->nb = NULL;

    return node;
}

void fill_node(address node, int level, const char *name, boolean gender) {

    node->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    if (node->name == NULL) {
        printf("Gagal Alokasi\n");
        free(node);
    }

    switch (level) {
        case 0: // King
            strcpy(node->name, name);
            node->gender = 0;
            node->age = rand() % 51 + 50; // 50-100
            node->hp = 100;
            node->p_pow = 100;
            node->p_int = 100;
            node->p_inf = 100;
            break;
        case 1: // Queen and King's Mistresses
            strcpy(node->name, name);
            node->gender = 1;
            node->age = rand() % 31 + 70; // 30-100
            node->hp = 100;
            node->p_pow = rand() % 61 + 20; // 20-80
            node->p_int = rand() % 71 + 30; // 30-100
            node->p_inf = rand() % 51 + 50; // 50-100
            break;
        case 2: // King's Child
            strcpy(node->name, name);
            node->age = rand() % 41 + 50; // 40-50
            node->gender = gender;
            node->hp = 100;
            node->p_pow = rand() % 41 + 30; // 30-70
            node->p_int = rand() % 41 + 30; // 30-70
            node->p_inf = rand() % 41 + 30; // 30-70
            break;
        case 3: // King's Child Spouse
            strcpy(node->name, name);            
            if (node->pr->gender == 1)
            {
                node->gender = 0;
            } else {
                node->gender = 1;
            }
            
            node->age = rand() % 31 + 20; // 30-50
            node->hp = 100;
            node->p_pow = rand() % 21 + 20; // 20-40
            node->p_int = rand() % 21 + 20; // 20-40
            node->p_inf = rand() % 41 + 20; // 20-60
            break;
        case 4: // King's Grandchild
            strcpy(node->name, name);
            node->age = rand() % 21;
            node->gender = gender;
            node->hp = 100;
            node->p_pow = rand() % 41; // 0-40
            node->p_int = rand() % 41; // 0-40
            node->p_inf = rand() % 41; // 0-40
            break;
        default:
            break;
    }
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
    child->pr = parent;
}

address search_node(address root, const char *name) {
    if (root == NULL)
        return NULL;

    if (strcmp(root->name, name) == 0)
        return root;

    address result = search_node(root->fs, name); // Search in first son
    if (result == NULL)
        result = search_node(root->nb, name);     // Search in next brother
    
    return result;
}

void show_royal_tree(address node, int depth) {
    if (node == NULL) return;
    // printf("%*c",' ');
    if (depth == 0) {
        printf("- King ");
    } else if (depth == 1 && node->nb != NULL) {
        printf("+ + Queen ");
    } else if (depth == 1 && node->nb == NULL) {
        printf("+ + Mistress ");
    } else if (depth == 2 && node->gender == 0) {
        printf("- - - Prince ");
    } else if (depth == 2 && node->gender == 1) {
        printf("- - - Princess ");
    } else if (depth == 3 && node->gender == 0) {
        printf("+ + + Prince ");
    } else if (depth == 3 && node->gender == 1) {
        printf("+ + + Princess ");
    } else if (depth > 3 && node->gender == 0) {
        printf("- - - - Prince ");
    } else if (depth > 3 && node->gender == 1) {
        printf("- - - - Princess ");
    }

    printf("%s\n", node->name); // Print the entire name
    show_royal_tree(node->fs, depth + 1); // print first son recursively
    show_royal_tree(node->nb, depth); // print next brother recursively at the same depth
}


void build_tree() {
    address queen, mistress, first_prince, second_prince, third_prince, fourth_prince, first_princess, second_princess, third_princess, fourth_princess, first_inlaw, second_inlaw, third_inlaw;
    
    king = create_node();
    queen = create_node();
    mistress = create_node(); 
    first_prince = create_node(); 
    second_prince = create_node();
    third_prince = create_node();
    fourth_prince = create_node();
    first_princess = create_node(); 
    second_princess = create_node(); 
    third_princess = create_node(); 
    fourth_princess = create_node();
    first_inlaw = create_node(); 
    second_inlaw = create_node(); 
    third_inlaw = create_node(); 
    
    add_child(king, queen);
    add_child(king, mistress);

    add_child(queen, first_prince);
    add_child(queen, first_princess);

    add_child(mistress, second_prince);

    add_child(first_prince, first_inlaw);
    add_child(first_princess, second_inlaw);
    add_child(second_prince, third_inlaw);

    fill_node(king, 0, "George", 0);
    fill_node(queen, 1, "Mary", 1);
    fill_node(mistress, 1, "Rashta", 1);
    fill_node(first_prince, 2, "Zayne", 0);
    fill_node(second_prince, 2, "Xavier", 0);
    fill_node(first_princess, 2, "Elizabeth", 1);

    fill_node(third_prince, 4, "Louis", 0);
    fill_node(fourth_prince, 4, "Rafayel", 0);
    fill_node(second_princess, 4, "Victoria", 1);
    fill_node(third_princess, 4, "Shuri", 1);
    fill_node(fourth_princess, 4, "Charlotte", 1);
    
    fill_node(first_inlaw, 3, "Lena", 1);
    fill_node(second_inlaw, 3, "Vyn", 0);
    fill_node(third_inlaw, 3, "Selene", 1);

    add_child(first_inlaw, third_prince);
    add_child(first_inlaw, second_princess);

    add_child(third_inlaw, third_princess);
    add_child(third_inlaw, fourth_prince);
    add_child(third_inlaw, fourth_princess);
}

int max_point(address node1, address node2) {
    int max1 = node1->hp + node1->p_pow + node1->p_int + node1->p_inf;
    int max2 = node2->hp + node2->p_pow + node2->p_int + node2->p_inf;
    return (max1 > max2) ? max1 : max2;
}

void choose_character(const char *name, int age, char gender) {
    address player;
    if (gender == 'L')
    {
        player = search_node(king, "Zayne");
        printf("\nnama pemain asalnya: %s\n", player->name);
    } else {
        player = search_node(king, "Elizabeth");
        printf("\nnama pemain asalnya: %s\n", player->name);
    }

    if (player != NULL)
    {
        free(player->name); // free nama sebelumnya

        player->name = (char *)malloc((strlen(name) + 1) * sizeof(char)); // alokasikan nama yang baru
        if (player->name == NULL)
        {
            printf("Gagal Alokasi");
            exit(1);
        }

        strcpy(player->name, name);        
        player->age = age;
    } else {
        printf("Karakter tidak ditemukan!");
    }
    
    strcpy(player->name, name);

}

// int main() {
//     const char *name = "Sel";
//     int age = 21;
//     char gender = 'L';

//     build_tree();
//     choose_character(name, age, gender);
//     show_royal_tree(king, 0);

//     return 0;
// }


void display_main_character () {
    
}
