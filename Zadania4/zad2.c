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