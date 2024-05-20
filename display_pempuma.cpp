int main() {
    int choice;
    do {
        printf("\n=====================================\n");
        printf("       PEMILIHAN PUTRA/PUTRI MAHKOTA\n");
        printf("=====================================\n");
        printf("\nTampilkan Pohon Kerajaan\n");
        show_royal_tree(king, 0);
        
        printf("\nTampilkan Spesifikasi Karakter Utama\n");
        display_main_character(king);
        
        printf("\n Pilihan : \n");
        printf("1. Lakukan Pemilihan Putra atau Putri Mahkota\n");
        printf("2. Keluar kembali ke mmenu utama\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                crowning(king);
                break;
            case 2:
                printf("Terima kasih!\n"); //ini harusnya balik ke menu utamanya 
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (choice != 2);
    return 0;
}
