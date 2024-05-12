#include <stdio.h>

// Definicja unii
union Dane {
    int liczba_cal;
    float liczba_zmien;
    char znak;
};

int main() {
    // Inicjalizacja unii
    union Dane dane;

    // Wprowadzanie wartości dla typu int
    printf("Podaj wartosc dla typu int: ");
    scanf_s("%d", &dane.liczba_cal);
    printf("Wartosc przechowywana w polu int: %d\n", dane.liczba_cal);

    // Wprowadzanie wartości dla typu float
    printf("Podaj wartosc dla typu float: ");
    scanf_s("%f", &dane.liczba_zmien);
    printf("Wartosc przechowywana w polu float: %.2f\n", dane.liczba_zmien);

    // Wprowadzanie pojedynczego znaku
    printf("Podaj pojedynczy znak: ");
    scanf_s(" %c", &dane.znak); // Wskazówka: spacja przed %c pomija białe znaki
    printf("Znak przechowywany w polu char: %c\n", dane.znak);

    return 0;
}