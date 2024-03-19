#include <stdio.h>

// Funkcja do zamiany miejscami dwóch liczb
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja rekurencyjna generująca wszystkie permutacje
void permute(int* array, int start, int end) {
    // Jeśli start i end są równe, to doszliśmy do jednej z permutacji
    if (start == end) {
        // Wyświetlenie aktualnej permutacji
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else {
        // Iteruj przez wszystkie elementy od start do end
        for (int i = start; i <= end; i++) {
            // Zamień miejscami elementy na pozycjach start i i
            swap(&array[start], &array[i]);
            // Rekurencyjnie generuj permutacje dla pozostałej części tablicy
            permute(array, start + 1, end);
            // Przywróć początkowy porządek elementów (backtracking)
            swap(&array[start], &array[i]);
        }
    }
}

int main() {
    int array[] = { 1, 2, 3 };
    int n = sizeof(array) / sizeof(array[0]);

    printf("Przykładowa definicja\n");
    printf("void permute(int *array, int start, int end)\n\n");

    printf("Przykładowy wynik\n");
    permute(array, 0, n - 1);

    return 0;
}