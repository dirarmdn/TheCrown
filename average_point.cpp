#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define boolean unsigned char 

// Definisi struktur kerajaan
typedef struct t_kerajaan *address; 
typedef struct t_kerajaan {
    char nama;
    int umur;
    boolean gender;
    int hp; //health point
    int p_pow; //poin power
    int p_int; //poin intelligence
    int p_inf; //poin influence
    address nb; //next brother (dalam tree, bukan dalam keluarga)
    address fs; //first son
    address pr; //parent
} kerajaan; 
typedef address royal_tree;

// Fungsi untuk menetapkan nilai-nilai awal untuk node baru
address createNode(char name, int hp, int power, int intelligence, int influence) {
    address newNode = (address)malloc(sizeof(kerajaan));
    newNode->nama = name;
    newNode->hp = hp;
    newNode->p_pow = power;
    newNode->p_int = intelligence;
    newNode->p_inf = influence;
    newNode->fs = NULL;
    newNode->nb = NULL;
    newNode->pr = NULL;
    return newNode;
}


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

