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

// Fungsi untuk menetukan level suatu node
int findLevel(address root, address node, int level) {
    // Jika root adalah NULL atau node adalah NULL, return -1
    if (root == NULL || node == NULL)
        return -1;

    // Jika node yang dicari adalah root, levelnya adalah 0
    if (root == node)
        return level;

    // Cari di subtree anak pertama (first son)
    int downLevel = findLevel(root->fs, node, level + 1);
    if (downLevel != -1)
        return downLevel;

    // Jika tidak ditemukan di subtree anak pertama,
    // cari di subtree saudara selanjutnya (next brother)
    return findLevel(root->nb, node, level);
}

int main() {
    // Contoh penggunaan: Membuat pohon kerajaan sederhana
    // Asumsi ada 5 kerajaan dengan A sebagai raja
    royal_tree tree = (royal_tree)malloc(sizeof(kerajaan));
    tree->nama = 'A';
    tree->fs = NULL;
    tree->nb = NULL;
    tree->pr = NULL;

    // Membuat 4 kerajaan dengan B, C, D, E sebagai first son dari A
    tree->fs = (address)malloc(sizeof(kerajaan));
    tree->fs->nama = 'B';
    tree->fs->fs = NULL;
    tree->fs->nb = (address)malloc(sizeof(kerajaan));
    tree->fs->nb->nama = 'C';
    tree->fs->nb->fs = NULL;
    tree->fs->nb->nb = (address)malloc(sizeof(kerajaan));
    tree->fs->nb->nb->nama = 'D';
    tree->fs->nb->nb->fs = NULL;
    tree->fs->nb->nb->nb = (address)malloc(sizeof(kerajaan));
    tree->fs->nb->nb->nb->nama = 'E';
    tree->fs->nb->nb->nb->fs = NULL;
    tree->fs->nb->nb->nb->nb = NULL;

    // Menetapkan parent untuk setiap kerajaan
    address current = tree;
    while (current != NULL) {
        address child = current->fs;
        while (child != NULL) {
            child->pr = current;
            child = child->nb;
        }
        current = current->fs;
    }

    // Menghitung level setiap kerajaan
    printf("Level of A: %d\n", findLevel(tree, tree, 0)); // A
    printf("Level of B: %d\n", findLevel(tree, tree->fs, 0)); // B
    printf("Level of C: %d\n", findLevel(tree, tree->fs->nb, 0)); // C
    printf("Level of D: %d\n", findLevel(tree, tree->fs->nb->nb, 0)); // D
    printf("Level of E: %d\n", findLevel(tree, tree->fs->nb->nb->nb, 0)); // E

    // Dealokasi memori
    free(tree->fs->nb->nb->nb);
    free(tree->fs->nb->nb);
    free(tree->fs->nb);
    free(tree->fs);
    free(tree);

    return 0;
}

