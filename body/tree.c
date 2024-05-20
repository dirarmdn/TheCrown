#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/dhira.h"
#include "../header/dhea.h"
#include "../header/gia.h"

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
        exit(1);
    }

    strcpy(node->name, name);

    switch (level) {
        case 0: // King
            node->gender = 0;
            node->age = rand() % 51 + 50; // 50-100
            node->hp = 100;
            node->p_pow = 100;
            node->p_int = 100;
            node->p_inf = 100;
            break;
        case 1: // Queen and King's Mistresses
            node->gender = 1;
            node->age = rand() % 31 + 70; // 70-100 (not 30-100)
            node->hp = 100;
            node->p_pow = rand() % 61 + 20; // 20-80
            node->p_int = rand() % 71 + 30; // 30-100
            node->p_inf = rand() % 51 + 50; // 50-100
            break;
        case 2: // King's Child
            node->age = rand() % 41 + 10; // 10-50 (corrected from 40-50)
            node->gender = gender;
            node->hp = 100;
            node->p_pow = rand() % 41 + 30; // 30-70
            node->p_int = rand() % 41 + 30; // 30-70
            node->p_inf = rand() % 41 + 30; // 30-70
            break;
        case 3: // King's Child Spouse
            if (node->pr->gender == 1) {
                node->gender = 0;
            } else {
                node->gender = 1;
            }
            node->age = rand() % 31 + 20; // 20-50 (corrected from 30-50)
            node->hp = 100;
            node->p_pow = rand() % 21 + 20; // 20-40
            node->p_int = rand() % 21 + 20; // 20-40
            node->p_inf = rand() % 41 + 20; // 20-60
            break;
        case 4: // King's Grandchild
            node->age = rand() % 21; // 0-20
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
    int maxCount1 = 0;
    int maxCount2 = 0;

    if (node1->p_pow > node2->p_pow) maxCount1++;
    else if (node1->p_pow < node2->p_pow) maxCount2++;

    if (node1->p_int > node2->p_int) maxCount1++;
    else if (node1->p_int < node2->p_int) maxCount2++;

    if (node1->p_inf > node2->p_inf) maxCount1++;
    else if (node1->p_inf < node2->p_inf) maxCount2++;

    if (maxCount1 > maxCount2) return 1;
    else if (maxCount2 > maxCount1) return 2;
    else return 0; // Jika seri
}


// Fungsi untuk menghitung rerata dari p_pow, p_int, dan p_inf dari suatu node
float calculateAverage(address node) {
    if (node == NULL)
        return 0;

    // Menghitung rerata dari p_pow, p_int, dan p_inf
    float avg = (node->p_pow + node->p_int + node->p_inf) / 3.0;
    return avg;
}


void choose_character(const char *name, int age, char gender) {
    address chara = NULL; // Inisialisasi chara
    printf("%s", name);
    if (gender == 'L')
    {
        chara = search_node(king, "Zayne");
        if (chara != NULL) {
            printf("\nnama pemain asalnya: %s\n", chara->name);
        }
    } else {
        chara = search_node(king, "Elizabeth");
        if (chara != NULL) {
            printf("\nnama pemain asalnya: %s\n", chara->name);
        }
    }

    if (chara != NULL)
    {
        free(chara->name); // free nama sebelumnya jika dialokasikan secara dinamis

        chara->name = (char *)malloc((strlen(name) + 1) * sizeof(char)); // alokasikan nama yang baru
        if (chara->name == NULL)
        {
            printf("Gagal Alokasi");
            exit(1);
        }

        strcpy(chara->name, name);        
        // player->age = age;
    } else {
        printf("Karakter tidak ditemukan!");
    }
    player = chara;
}


void display_main_character (address node) {
    printf("\nSpesifikasi node yang dipegang saat ini:\n");
    printf("Nama: %s\n", node->name);
    printf("Umur: %d\n", node->age);
    if (node->gender == 1)
    {
        printf("Gender: Woman\n");
    } else {
        printf("Gender: Man\n");
    }
    printf("HP: %d\n", node->hp);
    printf("Power: %d\n", node->p_pow);
    printf("Intelligence: %d\n", node->p_int);
    printf("Influence: %d\n", node->p_inf);
}

// int main() {
//     const char *name = "Sel";
//     int age = 21;
//     char gender = 'P';

//     build_tree();
//     choose_character(name, age, gender);
//     show_royal_tree(king, 0);

//     player = search_node(king, name);

//     arena_battle(player);

//     return 0;
// }
void nodes_at_level(address root, int level, address *result, int *index) {
    if (root == NULL) {
        return;
    }
    if (level == 0) {
        result[(*index)++] = root;
    } else {
        nodes_at_level(root->fs, level - 1, result, index);
        nodes_at_level(root->nb, level, result, index);
    }
}

float calculateAverage(address node) {
    if (node == NULL)
        return 0;
    return (node->p_pow + node->p_int + node->p_inf) / 3.0;
}

void crowning(address king) {
    address nodes[100];
    int index = 0;

    nodes_at_level(king, 2, nodes, &index);

    if (index == 0) {
        printf("No heirs found at level 2\n");
        return;
    }

    address heir = nodes[0];
    float max_avg = calculateAverage(nodes[0]);
	int heir_index = 0;
	
	for (int i = 1; i < index; i++) {
	    float avg = calculateAverage(nodes[i]);
	    if (avg > max_avg) {
	        max_avg = avg;
	        heir = nodes[i];
	        heir_index = i;
	    } else if (avg == max_avg) {
	        if (nodes[i]->age > heir->age) {
	            heir = nodes[i];
	            heir_index = i;
	        } else if (nodes[i]->age == heir->age && i < heir_index) {
	            heir = nodes[i];
	            heir_index = i;
	        }
	    }
	}

    if (heir->gender == 0) {
        printf("SELAMAT KEPADA PANGERAN %s TELAH DIANGKAT MENJADI PUTRA MAHKOTA\n", heir->name);
    } else {
        printf("SELAMAT KEPADA PUTRI %s TELAH DIANGKAT MENJADI PUTRI MAHKOTA\n", heir->name);
    }
}

