#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Mengembalikan indeks elemen yang ditemukan
        }
    }
    return -1; // Elemen tidak ditemukan
}

int main() {
    int n;
    printf("Masukkan jumlah elemen dalam array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan elemen-elemen array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Masukkan elemen yang ingin dicari: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Elemen ditemukan pada indeks: %d\n", result);
    } else {
        printf("Elemen tidak ditemukan\n");
    }

    return 0;
}

