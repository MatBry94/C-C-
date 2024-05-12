#include <stdio.h>

int main() {
    int tablica[10];  // Deklaracja tablicy dziesięciu liczb całkowitych
    int *wskaznik;    // Deklaracja wskaźnika na typ int

    // Inicjalizacja tablicy wartościami od 0 do 9
    for (int i = 0; i < 10; i++) {
        tablica[i] = i;
    }

    // Używanie wskaźnika do wyświetlenia zawartości tablicy
    wskaznik = tablica;  // Inicjalizacja wskaźnika na początek tablicy

    printf("Zawartosc tablicy:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *wskaznik);  // Wyświetlenie wartości, na którą wskazuje wskaźnik
        wskaznik++;  // Inkrementacja wskaźnika, aby wskazywał na kolejny element tablicy
    }
    printf("\n");

    return 0;
}