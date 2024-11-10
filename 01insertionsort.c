// INSERTION SORT

#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Geser elemen-elemen yang lebih besar dari `key` ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Masukkan banyak angka yang ingin diurutkan: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d angka: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array sebelum diurutkan: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Array setelah diurutkan: ");
    printArray(arr, n);

    return 0;
}

