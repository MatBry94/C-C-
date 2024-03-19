#include <stdio.h>

// Funkcja obliczająca silnię
unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1; // Silnia z 0 lub 1 jest równa 1
    }
    else {
        return n * factorial(n - 1); // Silnia z n = n * (n-1)!
    }
}

int main() {
    unsigned int liczba;

    printf("Podaj liczbe calkowita: ");
    scanf("%u", &liczba);

    printf("Silnia z %u wynosi %llu\n", liczba, factorial(liczba));

    return 0;
}