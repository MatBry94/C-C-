#include <stdio.h>

// Deklaracje funkcji
int dodawanie(int a, int b);
int mnozenie(int a, int b);
int odejmowanie(int a, int b);

int main() {
    int (*wskaznik)(int, int); // Deklaracja wskaźnika do funkcji
    int liczba1, liczba2;
    char operacja;

    // Inicjalizacja wskaźnika do funkcji
    wskaznik = NULL;

    // Wybór operacji
    printf("Wybierz operacje: + (dodawanie), * (mnozenie), - (odejmowanie): ");
    scanf(" %c", &operacja);

    // Wskazywanie odpowiedniej funkcji przez wskaźnik
    switch (operacja) {
        case '+':
            wskaznik = dodawanie;
        break;
        case '*':
            wskaznik = mnozenie;
        break;
        case '-':
            wskaznik = odejmowanie;
        break;
        default:
            printf("Niepoprawna operacja!\n");
        return 1; // Zakończenie programu z kodem błędu
    }

    // Pobranie dwóch liczb od użytkownika
    printf("Podaj dwie liczby: ");
    scanf("%d %d", &liczba1, &liczba2);

    // Wywołanie odpowiedniej funkcji za pomocą wskaźnika i wyświetlenie wyniku
    printf("Wynik: %d\n", wskaznik(liczba1, liczba2));

    return 0;
}

// Definicje funkcji
int dodawanie(int a, int b) {
    return a + b;
}

int mnozenie(int a, int b) {
    return a * b;
}

int odejmowanie(int a, int b) {
    return a - b;
}