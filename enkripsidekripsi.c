#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk melakukan enkripsi dengan Caesar Cipher
void enkripsi(char *plaintext, int pergeseran) {
    pergeseran = pergeseran % 26; // Batasi pergeseran agar dalam rentang 0-25
    for (int i = 0; plaintext[i] != '\0'; i++) { // untuk mengecek karakter satu per satu
        char karakter = plaintext[i]; 
        if (isalpha(karakter)) { // Memeriksa apakah karakter adalah huruf
            if (isupper(karakter)) { // memeriksa apakah karakter huruf kapital
                plaintext[i] = (karakter - 'A' + pergeseran) % 26 + 'A'; // Pergeseran untuk huruf kapital
            } else { // jika huruf kecil
                plaintext[i] = (karakter - 'a' + pergeseran) % 26 + 'a'; // Pergeseran untuk huruf kecil
            }
        }
    }
}

// Fungsi untuk melakukan deskripsi dengan Caesar Cipher
void deskripsi(char *ciphertext, int pergeseran) { 
    pergeseran = pergeseran % 26; // Batasi pergeseran agar dalam rentang 0-25
    for (int i = 0; ciphertext[i] != '\0'; i++) { // 
        char karakter = ciphertext[i];
        if (isalpha(karakter)) { // Memeriksa apakah karakter adalah huruf
            if (isupper(karakter)) {
                ciphertext[i] = (karakter - 'A' - pergeseran + 26) % 26 + 'A'; // Pergeseran ke belakang untuk huruf kapital
            } else {
                ciphertext[i] = (karakter - 'a' - pergeseran + 26) % 26 + 'a'; // Pergeseran ke belakang untuk huruf kecil
            }
        }
    }
}

// header
void cetakHeader() {
    printf("\n");
    printf("=====================================\n");
    printf("       Program Enkripsi dan Deskripsi\n");
    printf("             Caesar Cipher           \n");
    printf("=====================================\n\n");
}

// menu
void cetakMenu() {
    printf("Pilih opsi:\n");
    printf("1. Enkripsi\n");
    printf("2. Deskripsi\n");
    printf("-------------------------------------\n");
}

int main() {
    int pergeseran, pilihan;
    char teks[100];
    char ulangi;

    do {
        cetakHeader(); 
        cetakMenu();   

        
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1 || pilihan == 2) {
            printf("Jumlah Pergeseran: ");
            scanf("%d", &pergeseran);
            getchar(); // Membersihkan newline setelah input angka

            if (pilihan == 1) { // Opsi untuk enkripsi
                printf("Masukkan Plaintext: ");
                fgets(teks, sizeof(teks), stdin); // Input teks yang akan dienkripsi
                teks[strcspn(teks, "\n")] = 0; // Menghapus newline di akhir input

                int adaAngka = 0;
                for (int i = 0; teks[i] != '\0'; i++) {
                    if (isdigit(teks[i])) {
                        adaAngka = 1;
                        break;
                    }
                }

                if (adaAngka) {
                    printf("Plaintext harus berupa huruf, tidak boleh ada angka.\n");
                } else {
                    enkripsi(teks, pergeseran); // Memanggil fungsi enkripsi
                    printf("\nHasil Enkripsi (Ciphertext): %s\n", teks);
                }
            } else if (pilihan == 2) { // Opsi untuk deskripsi
                printf("Masukkan Ciphertext: ");
                fgets(teks, sizeof(teks), stdin); // Input teks yang akan dideskripsi
                teks[strcspn(teks, "\n")] = 0;

                int adaAngka = 0;
                for (int i = 0; teks[i] != '\0'; i++) {
                    if (isdigit(teks[i])) {
                        adaAngka = 1;
                        break;
                    }
                }

                if (adaAngka) {
                    printf("Ciphertext harus berupa huruf, tidak boleh ada angka.\n");
                } else {
                    deskripsi(teks, pergeseran); // Memanggil fungsi deskripsi
                    printf("\nHasil Deskripsi (Plaintext): %s\n", teks);
                }
            }
        } else {
            printf("Pilihan tidak valid. Mohon pilih 1 atau 2.\n");
        }

        printf("-------------------------------------\n");
        printf("Apakah Anda ingin mengulangi program? (y/n): ");
        scanf(" %c", &ulangi); 
        getchar(); // Menghapus newline agar tidak terbaca di iterasi berikutnya
        printf("\n");

    } while (ulangi == 'y' || ulangi == 'Y'); 

    printf("=====================================\n");
    printf("           Program selesai.          \n");
    printf("=====================================\n");
    printf("\n");

    return 0;
}