#include <stdio.h>

int main() {
    // grades[0] to oceny z matematyki, grades[1] to oceny z fizyki
    int grades[2][5] = {
            {5, 4, 3, 5, 2}, // Oceny z matematyki
            {3, 3, 4, 5, 5}  // Oceny z fizyki
    };

    double sum = 0; // Suma wszystkich ocen

    // Obliczanie sumy ocen
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            sum += grades[i][j];
        }
    }

    
    double average = sum / 10; 

    
    printf("Średnia ocen z matematyki i fizyki dla grupy pięciu uczniów wynosi: %.2f\n", average);

    return 0;
}