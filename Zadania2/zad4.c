#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct {
    char imie[50];
    float ocena;
} Student;


void zamien(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}


void sortuj_studentow(Student* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (tablica[j].ocena < tablica[j + 1].ocena) {
                zamien(&tablica[j], &tablica[j + 1]);
            }
        }
    }
}

int main() {
    
    srand(time(NULL));

    
    Student lista_studentow[50];
    for (int i = 0; i < 50; i++) {
        sprintf(lista_studentow[i].imie, "Student %d", i + 1);
        lista_studentow[i].ocena = 2.0 + (rand() / (float)RAND_MAX) * (6.0 - 2.0); 
    }

    
    sortuj_studentow(lista_studentow, 50);

    
    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < 50; i++) {
        printf("Imie: %s, Ocena: %.2f\n", lista_studentow[i].imie, lista_studentow[i].ocena);
    }

    return 0;
}