#include <stdio.h>
#include <stdlib.h>

// Definisi struktur kerajaan
typedef struct t_kerajaan *address;
typedef struct t_kerajaan {
    char nama;
    int hp; // health point
    int p_pow, p_int, p_inf; // power, intelligence, influence
    address nb, fs, parent; // next brother, first son, parent
} kerajaan;
typedef address royal_tree;
typedef address king;

// Fungsi untuk menetapkan nilai-nilai awal untuk node baru
/*address createNode(char name, int hp, int power, int intelligence, int influence) {
    address newNode = (address)malloc(sizeof(kerajaan));
    newNode->nama = name;
    newNode->hp = hp;
    newNode->p_pow = power;
    newNode->p_int = intelligence;
    newNode->p_inf = influence;
    newNode->fs = NULL;
    newNode->nb = NULL;
    newNode->parent = NULL;
    return newNode;
}
*/

// Fungsi untuk menghitung rerata dari p_pow, p_int, dan p_inf dari suatu node
float calculateAverage(address node) {
    if (node == NULL)
        return 0;

    // Menghitung rerata dari p_pow, p_int, dan p_inf
    float avg = (node->p_pow + node->p_int + node->p_inf) / 3.0;
    return avg;
}

int main() {
    // Contoh penggunaan: Membuat node kerajaan
    address node = createNode('A', 100, 10, 20, 30);

    // Menghitung rerata dari p_pow, p_int, dan p_inf dari node tersebut
    float avg = calculateAverage(node);
    printf("Average of p_pow, p_int, and p_inf: %.2f\n", avg);

    // Dealokasi memori
    free(node);

    return 0;
}

