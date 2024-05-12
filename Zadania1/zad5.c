#include <stdio.h>

// Funkcja obliczająca sumę wielokrotności 3 lub 5
int sumaWielokrotnosci(int limit) {
    int suma = 0;
    // Zwróć 0, jeśli limit jest ujemny
    if (limit < 0) {
        return 0;
    }
    // Przejdź przez wszystkie liczby poniżej limitu
    for (int i = 1; i < limit; i++) {
        // Sprawdź, czy liczba jest wielokrotnością 3 lub 5
        if (i % 3 == 0 || i % 5 == 0) {
            suma += i;
        }
    }
    return suma;
}
int main() {
    int limit;
    printf("Podaj limit: ");
    scanf_s("%d", &limit);

    int wynik = sumaWielokrotnosci(limit);
    printf("Suma wielokrotności 3 lub 5 poniżej %d wynosi: %d\n", limit, wynik);

    return 0;
}