#include <stdio.h>


int wspolczynniki(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return wspolczynniki(n - 1, k - 1) + wspolczynniki(n - 1, k);
}


void trojkatPascala(int wysokosc) {
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", wspolczynniki(i, j));
        }
        printf("\n");
    }
}

int main() {
    int wysokosc;

    printf("Podaj wysokosc trojkata Pascala: ");
    scanf_s("%d", &wysokosc);

    trojkatPascala(wysokosc);

    return 0;
}