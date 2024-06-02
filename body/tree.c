#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../header/dhira.h"
#include "../header/dhea.h"
#include "../header/gia.h"

address create_node()
{
    address node;

    node = (address)malloc(sizeof(kingdom));
    if (node == NULL)
    {
        printf("Gagal Alokasi\n");
        exit(1);
    }

    node->pr = NULL;
    node->fs = NULL;
    node->nb = NULL;

    return node;
}

void fill_node(address node, int level, const char *name, boolean gender)
{
    node->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    if (node->name == NULL)
    {
        printf("Gagal Alokasi\n");
        exit(1);
    }

    strcpy(node->name, name);

    switch (level)
    {
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
    case 2:                           // King's Child
        node->age = rand() % 41 + 10; // 10-50 (corrected from 40-50)
        node->gender = gender;
        node->hp = 100;
        node->ptp = 0;
        if (isTesting == 1)
        {
            node->p_pow = 50; // 30-70
            node->p_int = 50; // 30-70
            node->p_inf = 50; // 30-70
        }
        else
        {
            node->p_pow = rand() % 41 + 30; // 30-70
            node->p_int = rand() % 41 + 30; // 30-70
            node->p_inf = rand() % 41 + 30; // 30-70
        }

        break;
    case 3: // King's Child Spouse
        if (node->pr->gender == 1)
        {
            node->gender = 0;
        }
        else
        {
            node->gender = 1;
        }
        node->age = rand() % 31 + 20; // 20-50 (corrected from 30-50)
        node->hp = 100;
        node->p_pow = rand() % 21 + 20; // 20-40
        node->p_int = rand() % 21 + 20; // 20-40
        node->p_inf = rand() % 41 + 20; // 20-60
        break;
    case 4:                      // King's Grandchild
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

void add_child(address parent, address child)
{
    if (parent->fs == NULL)
    {
        parent->fs = child;
    }
    else
    {
        address sibling = parent->fs;
        while (sibling->nb != NULL)
        {
            sibling = sibling->nb;
        }
        sibling->nb = child;
    }
    child->pr = parent;
}

address search_node(address root, const char *name)
{
    if (root == NULL)
        return NULL;

    if (strcmp(root->name, name) == 0)
        return root;

    address result = search_node(root->fs, name); // Search in first son
    if (result == NULL)
        result = search_node(root->nb, name); // Search in next brother

    return result;
}

void show_royal_tree(address root, int level)
{
    if (root == NULL)
        return;
    for (int i = 0; i < level; i++)
    {
        if (i == level - 1)
        {
            if (level == 1 && root->nb != NULL)
            {
                printf(TITLE_COLOR "|+ + Queen ");
            }
            else if (level == 1 && root->nb == NULL)
            {
                printf(TITLE_COLOR "|+ + Mistress ");
            }
            else if (level == 2 && root->gender == 0)
            {
                printf(MENU_COLOR "|--Prince ");
            }
            else if (level == 2 && root->gender == 1)
            {
                printf(MENU_COLOR "|--Princess ");
            }
            else if (level == 3 && root->gender == 0)
            {
                printf(TITLE_COLOR "|+ + Prince ");
            }
            else if (level == 3 && root->gender == 1)
            {
                printf(TITLE_COLOR "|+ + Princess ");
            }
            else if (level > 3 && root->gender == 0)
            {
                printf(HIGHLIGHT_COLOR "|---Prince ");
            }
            else if (level > 3 && root->gender == 1)
            {
                printf(HIGHLIGHT_COLOR "|---Princess ");
            }
        }
        else
        {
            printf("   ");
        }
    }
    if (level == 0)
    {
        printf(YELLOW_COLOR "King %s\n", root->name);
    }
    else
    {
        printf("%s\n", root->name);
    }

    // Print children recursively
    if (root->fs != NULL)
    {
        show_royal_tree(root->fs, level + 1);
    }

    // Print siblings recursively
    if (root->nb != NULL)
    {
        show_royal_tree(root->nb, level);
    }
}

void build_tree()
{
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

int max_point(address node1, address node2)
{
    int maxCount1 = 0;
    int maxCount2 = 0;

    if (node1->p_pow > node2->p_pow)
        maxCount1++;
    else if (node1->p_pow < node2->p_pow)
        maxCount2++;

    if (node1->p_int > node2->p_int)
        maxCount1++;
    else if (node1->p_int < node2->p_int)
        maxCount2++;

    if (node1->p_inf > node2->p_inf)
        maxCount1++;
    else if (node1->p_inf < node2->p_inf)
        maxCount2++;

    if (maxCount1 > maxCount2)
        return 1;
    else if (maxCount2 > maxCount1)
        return 2;
    else
        return 0; // Jika seri
}

void choose_character(const char *name, char gender)
{
    address chara = NULL; // Inisialisasi chara
    printf("%s", name);
    if (gender == 'L')
    {
        chara = search_node(king, "Zayne");
        if (chara != NULL)
        {
            printf("\nnama pemain asalnya: %s\n", chara->name);
        }
    }
    else
    {
        chara = search_node(king, "Elizabeth");
        if (chara != NULL)
        {
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
    }
    else
    {
        printf("Karakter tidak ditemukan!");
    }
    player = chara;
}

void display_main_character(address node)
{
    printf(BORDER_COLOR "======================================\n" RESET_COLOR);
    printf("Nama: %-16s | Intelligence: %-3d\n", node->name, node->p_int);
    printf("Umur: %-16d | Power: %-3d\n", node->age, node->p_pow);
    if (node->gender == 1)
    {
        printf("Gender: %-14s | Influence: %-3d\n", "Woman", node->p_inf);
    }
    else
    {
        printf("Gender: %-14s | Influence: %-3d\n", "Man", node->p_inf);
    }
    printf("HP: %-18d\n", node->hp);
    printf(BORDER_COLOR "======================================\n" RESET_COLOR);
}

// Fungsi untuk menghitung jumlah elemen di level 2
int countLevel2(royal_tree root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    address firstSon = root->fs;
    while (firstSon != NULL)
    {
        address secondLevelChild = firstSon->fs;
        while (secondLevelChild != NULL)
        {
            count++;
            secondLevelChild = secondLevelChild->nb;
        }
        firstSon = firstSon->nb;
    }
    return count;
}

// Fungsi untuk mengalokasikan alamat node dari level 2 ke sebuah array
void getLevel2Addresses(royal_tree root, address **array, int *size)
{
    if (root == NULL)
    {
        *array = NULL;
        *size = 0;
        return;
    }

    *size = countLevel2(root);
    *array = (address *)malloc(*size * sizeof(address));

    int index = 0;
    address firstSon = root->fs;
    while (firstSon != NULL)
    {
        address secondLevelChild = firstSon->fs;
        while (secondLevelChild != NULL)
        {
            (*array)[index] = secondLevelChild;
            index++;
            secondLevelChild = secondLevelChild->nb;
        }
        firstSon = firstSon->nb;
    }
}

void printLine(int length) {
    for (int i = 0; i < length; i++) {
        printf("-");
    }
    printf("\n");
}

// Fungsi untuk mencetak para kandidat
void printLevel2Nodes(royal_tree root)
{
    address *array = NULL;
    int size = 0;
    getLevel2Addresses(root, &array, &size);

    // Mencetak header tabel
    printLine(42);
    printf("| %-10s | %-3s | %-5s | %-5s | %-5s |\n", "Name", "Age", "P_Pow", "P_Int", "P_Inf");
    printLine(42);

    // Mencetak baris data
    for (int i = 0; i < size; i++) {
        if (array[i]->ptp == 0) {            
            printf("| %-10s | %-3d | %-5d | %-5d | %-5d |\n", array[i]->name, array[i]->age, array[i]->p_pow, array[i]->p_int, array[i]->p_inf);
        }
    }

    // Mencetak footer tabel
    printLine(42);

    // Membersihkan memori yang dialokasikan
    free(array);
}

void printCrowningMessage(address heir) {
    printf(BORDER_COLOR "===============================================================\n" RESET_COLOR);
    printf("Selecting the heir...\n\n" RESET_COLOR);
    if (heir->gender == 0) {
        printf(YELLOW_COLOR"\n\tSELAMAT KEPADA PANGERAN %s TELAH DIANGKAT MENJADI PUTRA MAHKOTA\n", heir->name);
    } else {
        printf(YELLOW_COLOR"\n\tSELAMAT KEPADA PUTRI %s TELAH DIANGKAT MENJADI PUTRI MAHKOTA\n", heir->name);
    }
    printf(BORDER_COLOR "===============================================================\n" RESET_COLOR);
    sleep(3);
}


// Fungsi untuk menghitung nilai rata-rata poin sebuah node
float calculateAverage(address node)
{
    if (node == NULL)
        return 0;
    return (node->p_pow + node->p_int + node->p_inf) / 3.0;
}

// Fungsi untuk memilih putra/putri mahkota
void crowning(address king)
{
    address *nodes = NULL;
    int size = 0;

    getLevel2Addresses(king, &nodes, &size);

    if (size == 0)
    {
        printf("No heirs found at level 2\n");
        return;
    }

    address heir = nodes[0];
    float max_avg = calculateAverage(nodes[0]);
    int heir_index = 0;
    int pat = size;

    for (int i = 1; i < size; i++)
    {
        if (heir->ptp == 1)
        {
            float avg = calculateAverage(nodes[i]);
            if (avg > max_avg)
            {
                max_avg = avg;
                heir = nodes[i];
                heir_index = i;
            }
            else if (avg == max_avg)
            {
                if (nodes[i]->age > heir->age)
                {
                    heir = nodes[i];
                    heir_index = i;
                }
                else if (nodes[i]->age == heir->age && i < heir_index)
                {
                    heir = nodes[i];
                    heir_index = i;
                }
            }
        }
    }

    if (heir == player){
        printCrowningMessage(heir);
        system("cls");
        printf(BORDER_COLOR "===============================================================\n\n" RESET_COLOR);
        printf(YELLOW_COLOR"\n\tSelamat Kepada %s Telah Memenangkan Game ini\n\n", player->name);
        printf("\tTerimakasih Sudah Bermain Game Kami\n\n\n" RESET_COLOR);
        printf(BORDER_COLOR "===============================================================\n" RESET_COLOR);
        sleep(3);
        exit(0);
    } else if (pat == 2 && heir != player){
        printCrowningMessage(heir);
        system("cls");
        printf(BORDER_COLOR "===============================================================\n\n" RESET_COLOR);
        printf(YELLOW_COLOR"\n\tMohon Maaf %s Anda Kalah dalam Permainan ini\n\n", player->name);
        printf("\tTerimakasih Sudah Bermain Game Kami\n\n\n" RESET_COLOR);
        printf(BORDER_COLOR "===============================================================\n" RESET_COLOR);
        sleep(3);
        exit(0);
    } 
    printCrowningMessage(heir);
    heir->ptp = 1;
    pat--;

    // Membersihkan memori yang dialokasikan
    free(nodes);
}

void update_stats(address winner, address loser, int win_points, int lose_points)
{
    winner->p_inf += win_points;
    winner->p_int += win_points;
    winner->p_pow += win_points;
    loser->p_inf -= lose_points;
    loser->p_int -= lose_points;
    loser->p_pow -= lose_points;
}