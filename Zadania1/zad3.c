#include <stdio.h>

// Funkcja do obliczania silni
long long silnia(int n) {
    if (n <= 1)
        return 1;
    else
        return n * silnia(n - 1);
}

// Funkcja do obliczania silni dla każdego elementu tablicy
void obliczSilnie(int array[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        printf("Silnia liczby %d wynosi: %lld\n", array[i], silnia(array[i]));
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int rozmiar = sizeof(array) / sizeof(array[0]); // Obliczamy rozmiar tablicy

    obliczSilnie(array, rozmiar);

    return 0;
}