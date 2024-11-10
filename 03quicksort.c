#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot adalah elemen terakhir
    int i = (low - 1);  // Indeks elemen yang lebih kecil dari pivot

    for (int j = low; j <= high - 1; j++) {
        // Jika elemen saat ini lebih kecil atau sama dengan pivot
        if (arr[j] <= pivot) {
            i++;  // Perbesar indeks elemen yang lebih kecil dari pivot
            swap(&arr[i], &arr[j]);  // Tukar elemen arr[i] dan arr[j]
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Tempatkan pivot pada posisi yang benar
    return (i + 1);  // Kembalikan indeks pivot
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partisi dan ambil posisi pivot
        quickSort(arr, low, pi - 1);  // Rekursif ke bagian kiri
        quickSort(arr, pi + 1, high);  // Rekursif ke bagian kanan
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Masukkan banyak angka: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d angka: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array sebelum diurutkan: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array setelah diurutkan: ");
    printArray(arr, n);

    return 0;
}

