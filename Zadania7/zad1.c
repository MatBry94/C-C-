#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 256

// Funkcja konwersji słów na odpowiadające im cyfry
int word_to_digit(const char *str) {
    if (strcmp(str, "one") == 0) return 1;
    if (strcmp(str, "two") == 0) return 2;
    if (strcmp(str, "three") == 0) return 3;
    if (strcmp(str, "four") == 0) return 4;
    if (strcmp(str, "five") == 0) return 5;
    if (strcmp(str, "six") == 0) return 6;
    if (strcmp(str, "seven") == 0) return 7;
    if (strcmp(str, "eight") == 0) return 8;
    if (strcmp(str, "nine") == 0) return 9;
    return -1;
}

// Funkcja do znajdowania pierwszej i ostatniej cyfry w ciągu znaków
void find_digits(const char *str, int *first_digit, int *last_digit) {
    char word[6]; // maksymalna długość słowa reprezentującego cyfrę
    int word_idx = 0;
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (isdigit(str[i])) {
            int digit = str[i] - '0';
            if (*first_digit == -1) {
                *first_digit = digit;
            }
            *last_digit = digit;
        } else if (isalpha(str[i])) {
            word[word_idx++] = tolower(str[i]);
            word[word_idx] = '\0';
            if (word_idx >= 3) {
                int digit = word_to_digit(word);
                if (digit != -1) {
                    if (*first_digit == -1) {
                        *first_digit = digit;
                    }
                    *last_digit = digit;
                    word_idx = 0; // resetowanie indeksu słowa
                }
            }
        } else {
            word_idx = 0; // resetowanie indeksu słowa, jeśli napotkano niealfabetyczny znak
        }
        i++;
    }
}

int main(void) {
    char *filename = "C:\\Users\\mbryla\\CLionProjects\\untitled\\Zadania_C\\c_lista.txt";
    long total_sum = 0;
    char buf[MAX_BUFFER_SIZE];
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        int first_digit = -1, last_digit = -1;
        find_digits(buf, &first_digit, &last_digit);

        if (first_digit != -1 && last_digit != -1) {
            int sum = first_digit * 10 + last_digit;
            total_sum += sum;
            printf("Line: %s", buf);
            printf("First digit: %d, Last digit: %d, Sum: %d\n", first_digit, last_digit, sum);
        }
    }

    printf("Total sum: %ld\n", total_sum);
    fclose(fp);
    return EXIT_SUCCESS;
}