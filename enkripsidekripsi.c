#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk melakukan enkripsi dengan Caesar Cipher
void enkripsi(char *plaintext, int pergeseran) {
    pergeseran = pergeseran % 26; // Batasi pergeseran agar dalam rentang 0-25
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char karakter = plaintext[i];
        if (isalpha(karakter)) {
            if (isupper(karakter)) {
                plaintext[i] = (karakter - 'A' + pergeseran) % 26 + 'A';
            } else {
                plaintext[i] = (karakter - 'a' + pergeseran) % 26 + 'a';
            }
        }
    }
}

// Fungsi untuk melakukan deskripsi dengan Caesar Cipher
void deskripsi(char *ciphertext, int pergeseran) {
    pergeseran = pergeseran % 26; // Batasi pergeseran agar dalam rentang 0-25
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char karakter = ciphertext[i];
        if (isalpha(karakter)) {
            if (isupper(karakter)) {
                ciphertext[i] = (karakter - 'A' - pergeseran + 26) % 26 + 'A';
            } else {
                ciphertext[i] = (karakter - 'a' - pergeseran + 26) % 26 + 'a';
            }
        }
    }
}

// Fungsi untuk meminta input pergeseran
int inputPergeseran() {
    int pergeseran;
    char buffer[10];

    while (1) {
        printf("Jumlah Pergeseran: ");
        fgets(buffer, sizeof(buffer), stdin);
        
        // Memeriksa apakah input adalah angka
        if (sscanf(buffer, "%d", &pergeseran) == 1) {
            return pergeseran; // Kembali jika valid
        } else {
            printf("Pergeseran tidak valid. Mohon masukkan angka.\n");
        }
    }
}

// Fungsi untuk meminta input teks
void inputTeks(char *teks, const char *prompt) {
    printf("%s", prompt);
    fgets(teks, 100, stdin);
    teks[strcspn(teks, "\n")] = 0; // Menghapus newline di akhir input

    // Memastikan input hanya berisi huruf
    for (int i = 0; teks[i] != '\0'; i++) {
        if (!isalpha(teks[i])) {
            printf("Input harus berupa huruf saja. Silakan coba lagi.\n");
            inputTeks(teks, prompt);
            break;
        }
    }
}

// Fungsi untuk memeriksa apakah teks mengandung angka
int adaAngka(const char *teks) {
    for (int i = 0; teks[i] != '\0'; i++) {
        if (isdigit(teks[i])) {
            return 1;
        }
    }
    return 0;
}

// Fungsi untuk meminta pilihan
int inputPilihan() {
    int pilihan;
    char buffer[10];

    while (1) {
        printf("Pilih opsi: ");
        fgets(buffer, sizeof(buffer), stdin);
        
        // Memeriksa apakah input adalah angka
        if (sscanf(buffer, "%d", &pilihan) == 1) {
            if (pilihan == 1 || pilihan == 2) {
                return pilihan; // Kembali jika valid
            } else {
                printf("Pilihan tidak valid. Mohon pilih 1 atau 2.\n");
            }
        } else {
            printf("Pilihan tidak valid. Mohon masukkan angka.\n");
        }
    }
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    printf("=====================================\n");
    printf("       Program Enkripsi dan Deskripsi\n");
    printf("             Caesar Cipher           \n");
    printf("=====================================\n\n");

    printf("Pilih opsi:\n");
    printf("1. Enkripsi\n");
    printf("2. Deskripsi\n");
    printf("-------------------------------------\n");
}

// Fungsi untuk menampilkan hasil
void tampilkanHasil(char *teks, int pilihan) {
    if (pilihan == 1) {
        printf("Hasil Enkripsi (Ciphertext): %s\n", teks);
    } else {
        printf("Hasil Deskripsi (Plaintext): %s\n", teks);
    }
}

// main
int main() {
    int pergeseran, pilihan;
    char teks[100];
    char ulangi;

    do {
        tampilkanMenu();
        pilihan = inputPilihan();

        if (pilihan == 1 || pilihan == 2) {
            pergeseran = inputPergeseran();

            if (pilihan == 1) { // Opsi untuk enkripsi
                inputTeks(teks, "Masukkan Plaintext: ");
                enkripsi(teks, pergeseran);
                tampilkanHasil(teks, pilihan);
            } else { // Opsi untuk deskripsi
                inputTeks(teks, "Masukkan Ciphertext: ");
                deskripsi(teks, pergeseran);
                tampilkanHasil(teks, pilihan);
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

