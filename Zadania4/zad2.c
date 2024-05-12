#include <stdio.h>

// Funkcja sortująca tablicę metodą sortowania bąbelkowego
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Funkcja wyszukiwania binarnego w posortowanej tablicy
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[11];
    int key;

    // Wprowadzenie 11 wartości do tablicy
    printf("Wprowadz 11 wartosci do tablicy:\n");
    for (int i = 0; i < 11; i++) {
        scanf("%d", &arr[i]);
    }

    // Sortowanie tablicy
    bubbleSort(arr, 11);

    // Wprowadzenie wartości klucza do wyszukiwania
    printf("Podaj wartosc do znalezienia: ");
    scanf("%d", &key);

    // Wywołanie funkcji wyszukiwania binarnego
    int result = binarySearch(arr, 0, 10, key);
    if (result != -1) {
        printf("Element %d zostal znaleziony na indeksie %d.\n", key, result);
    }
    else {
        printf("Element %d nie zostal znaleziony w tablicy.\n", key);
    }

    return 0;
}