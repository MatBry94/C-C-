#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definicje dla ruchów
#define KAMIEN 0
#define PAPIER 1
#define NOZYCE 2
#define RUNDY 10 // Maksymalna liczba rund

// Struktura do przechowywania danych rundy
typedef struct {
    int playerMove;
    int computerMove;
    int result; // 0 - remis, 1 - wygrana gracza, 2 - wygrana komputera
} Round;

// Funkcja do wyświetlania wyników
void showScores(Round rounds[], int numberOfRounds) {
    printf("Wyniki poszczególnych rund:\n");
    for (int i = 0; i < numberOfRounds; i++) {
        printf("Runda %d: Gracz - %d, Komputer - %d, Wynik: ", i + 1, rounds[i].playerMove, rounds[i].computerMove);
        if (rounds[i].result == 0) {
            printf("Remis\n");
        }
        else if (rounds[i].result == 1) {
            printf("Wygrana gracza\n");
        }
        else {
            printf("Wygrana komputera\n");
        }
    }
}

// Funkcja do przeprowadzenia pojedynczej rundy
void playRound(Round* round) {
    printf("Wybierz: 0 - kamień, 1 - papier, 2 - nożyce: ");
    scanf("%d", &round->playerMove);

    // Losowanie ruchu komputera
    round->computerMove = rand() % 3;

    // Określenie wyniku
    if (round->playerMove == round->computerMove) {
        round->result = 0; // Remis
    }
    else if ((round->playerMove == KAMIEN && round->computerMove == NOZYCE) ||
        (round->playerMove == PAPIER && round->computerMove == KAMIEN) ||
        (round->playerMove == NOZYCE && round->computerMove == PAPIER)) {
        round->result = 1; // Wygrana gracza
    }
    else {
        round->result = 2; // Wygrana komputera
    }
}

int main() {
    Round rounds[RUNDY];
    int roundCount = 0;
    char command[10];

    srand(time(NULL)); // Inicjalizacja generatora liczb losowych

    while (1) {
        printf("Wpisz 'play' aby zagrać, 'scores' aby wyświetlić wyniki, 'exit' aby wyjść: ");
        scanf("%s", command);

        if (strcmp(command, "play") == 0) {
            if (roundCount < RUNDY) {
                playRound(&rounds[roundCount]);
                roundCount++;
            }
            else {
                printf("Osiągnięto maksymalną liczbę rund.\n");
            }
        }
        else if (strcmp(command, "scores") == 0) {
            showScores(rounds, roundCount);
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Nieznana komenda.\n");
        }
    }

    return 0;
}