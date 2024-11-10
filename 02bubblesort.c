#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen arr[j] dan arr[j+1] jika urutannya salah
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    printf("Masukkan banyak angka: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d angka: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array sebelum diurutkan: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array setelah diurutkan: ");
    printArray(arr, n);

    return 0;
}

