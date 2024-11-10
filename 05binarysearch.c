#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    printf("Masukkan jumlah elemen dalam array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan elemen-elemen array yang sudah diurutkan: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Masukkan elemen yang ingin dicari: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        printf("Elemen %d ditemukan pada indeks %d.\n", target, result);
    } else {
        printf("Elemen %d tidak ditemukan dalam daftar.\n", target);
    }

    return 0;
}

