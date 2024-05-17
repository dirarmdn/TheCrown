#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

// Fungsi untuk menyisipkan node sebagai anak pertama dari node tertentu
void insertFirstChild(address parent, address child) {
    if (parent == NULL || child == NULL)
        return;
    child->pr = parent;
    child->nb = parent->fs;
    parent->fs = child;
}

// Fungsi untuk menyisipkan node sebagai saudara berikutnya dari node tertentu
void insertNextBrother(address node, address brother) {
    if (node == NULL || brother == NULL)
        return;
    brother->pr = node->pr;
    brother->nb = node->nb;
    node->nb = brother;
}

// Fungsi untuk mencetak pohon secara rekursif
void printTree(address root, int level) {
    if (root != NULL) {
        // Cetak node saat ini
        printf("Level %d: %c (HP: %d, Power: %d, Intelligence: %d, Influence: %d)\n",
               level, root->nama, root->hp, root->p_pow, root->p_int, root->p_inf);
        
        // Cetak subtree anak pertama
        printTree(root->fs, level + 1);
        
        // Cetak subtree saudara selanjutnya
        printTree(root->nb, level);
    }
}

// Fungsi untuk mencari nama musuh di pohon
bool searchEnemy(address root, char enemyName) {
    if (root == NULL)
        return false;

    // Cek apakah nama musuh ditemukan di node saat ini
    if (root->nama == enemyName)
        return true;

    // Cari di subtree anak pertama (first son)
    if (searchEnemy(root->fs, enemyName))
        return true;

    // Cari di subtree saudara selanjutnya (next brother)
    return searchEnemy(root->nb, enemyName);
}

int main() {
    // Membuat pohon kerajaan dengan beberapa node di level 3
    royal_tree tree = createNode('A', 100, 10, 20, 30);
    
    // Level 1
    address nodeB = createNode('B', 90, 15, 25, 35);
    address nodeC = createNode('C', 80, 20, 30, 40);
    insertFirstChild(tree, nodeB);
    insertNextBrother(nodeB, nodeC);

    // Level 2
    address nodeD = createNode('D', 85, 18, 28, 38);
    address nodeE = createNode('E', 95, 12, 22, 32);
    insertFirstChild(nodeB, nodeD);
    insertNextBrother(nodeD, nodeE);

    // Level 3
    address nodeF = createNode('F', 75, 22, 32, 42);
    address nodeG = createNode('G', 105, 8, 18, 28);
    address nodeH = createNode('H', 88, 17, 27, 37);
    insertFirstChild(nodeD, nodeF);
    insertNextBrother(nodeF, nodeG);
    insertNextBrother(nodeG, nodeH);

    bool continueFighting = true;

    while (continueFighting) {
        // Menampilkan tampilan stage arena
        printf("======= STAGE ARENA =======\n");

        // Menampilkan pohon kerajaan
        printf("Tree structure:\n");
        printTree(tree, 0);

        // Menampilkan spesifikasi node yang dipegang saat ini
        printf("\nSpesifikasi node yang dipegang saat ini:\n");
        printf("Nama: %c\n", nodeF->nama);
        printf("HP: %d\n", nodeF->hp);
        printf("Power: %d\n", nodeF->p_pow);
        printf("Intelligence: %d\n", nodeF->p_int);
        printf("Influence: %d\n", nodeF->p_inf);

		// Pilihan menu mulai bertarung atau kembali ke menu utama
        printf("Pilih:\n1. Mulai bertarung\n2. Kembali ke menu utama\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
        	// Memasukkan nama musuh
        	printf("\nMasukkan nama musuh: ");
        	char enemyName;
        	scanf(" %c", &enemyName);

        	// Mencari nama musuh di pohon
        	if (searchEnemy(tree, enemyName)) {
           		printf("Musuh ditemukan!\n");
        	} else {
            	printf("Musuh tidak ditemukan.\n");
        }
            // Memulai bertarung
            // ...
    	} else if (choice == 2) {
            // Kembali ke menu utama
            continueFighting = false;
        } else {
        	printf("Pilihan tidak valid.\n");    
    	}
    }


    // Dealokasi memori
    free(tree);
    free(nodeB);
    free(nodeC);
    free(nodeD);
    free(nodeE);
    free(nodeF);
    free(nodeG);
    free(nodeH);

    return 0;
}

