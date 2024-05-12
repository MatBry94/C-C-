

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja do tworzenia macierzy o zadanych rozmiarach i wypełniania jej losowymi liczbami
int** stworz_macierz(int wiersze, int kolumny) {
    // Alokacja pamięci dla macierzy
    int** macierz = (int**)malloc(wiersze * sizeof(int*));
    if (macierz == NULL) {
        printf("Blad alokacji pamieci.\n");
        exit(1);
    }

    // Alokacja pamięci dla każdego wiersza
    for (int i = 0; i < wiersze; i++) {
        macierz[i] = (int*)malloc(kolumny * sizeof(int));
        if (macierz[i] == NULL) {
            printf("Blad alokacji pamieci.\n");
            exit(1);
        }
    }

    // Wypełnienie macierzy losowymi liczbami
    srand(time(NULL));
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = rand() % 100; // Zakres liczb od 0 do 99
        }
    }

    return macierz;
}

// Funkcja do wyświetlania zawartości macierzy na ekranie
void wyswietl_macierz(int** macierz, int wiersze, int kolumny) {
    printf("Zawartosc macierzy:\n");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }
}

// Funkcja do zwalniania pamięci zaalokowanej dla macierzy
void zwolnij_macierz(int** macierz, int wiersze) {
    for (int i = 0; i < wiersze; i++) {
        free(macierz[i]);
    }
    free(macierz);
}

int main() {
    int wiersze, kolumny;

    printf("Podaj liczbe wierszy macierzy: ");
    scanf("%d", &wiersze);
    printf("Podaj liczbe kolumn macierzy: ");
    scanf("%d", &kolumny);

    // Tworzenie macierzy i wypełnienie jej losowymi liczbami
    int** macierz = stworz_macierz(wiersze, kolumny);

    // Wyświetlenie zawartości macierzy
    wyswietl_macierz(macierz, wiersze, kolumny);

    // Zwolnienie zaalokowanej pamięci
    zwolnij_macierz(macierz, wiersze);

    return 0;
}
