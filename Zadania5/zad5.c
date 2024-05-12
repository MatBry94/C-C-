#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do dodawania elementu na koniec listy
void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Tworzenie nowego elementu
    if (new_node == NULL) {
        printf("Blad alokacji pamieci\n");
        return;
    }
    new_node->data = data; // Ustawienie wartości nowego elementu
    new_node->next = NULL; // Nowy element będzie ostatnim na liście

    if (*head_ref == NULL) {
        *head_ref = new_node; // Jeśli lista jest pusta, nowy element staje się nagłówkiem listy
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL) {
            current = current->next; // Przechodzenie na koniec listy
        }
        current->next = new_node; // Powiązanie nowego elementu z ostatnim elementem listy
    }
}

// Funkcja do usuwania pierwszego elementu z listy o określonej wartości
void remove_by_value(struct Node** head_ref, int value) {
    struct Node* temp = *head_ref, *prev = NULL;

    // Jeśli pierwszy element ma wartość, którą chcemy usunąć
    if (temp != NULL && temp->data == value) {
        *head_ref = temp->next; // Przesunięcie nagłówka na następny element
        free(temp); // Zwolnienie pamięci pierwszego elementu
        return;
    }

    // Szukanie elementu o określonej wartości
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Jeśli element o określonej wartości nie został znaleziony
    if (temp == NULL) {
        printf("Element o wartosci %d nie zostal znaleziony\n", value);
        return;
    }

    // Usuwanie elementu o określonej wartości
    prev->next = temp->next;
    free(temp);
}

// Funkcja do wyświetlania zawartości listy
void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Funkcja do usuwania wszystkich elementów z listy
void delete_list(struct Node** head_ref) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head_ref = NULL;
}

int main() {
    // Inicjalizacja nagłówka listy
    struct Node* head = NULL;

    // Dodawanie elementów na koniec listy
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 2);

    // Wyświetlanie listy przed usunięciem
    printf("Lista przed usunieciem elementu o wartosci 2: ");
    print_list(head);

    // Usuwanie pierwszego elementu z listy o określonej wartości
    remove_by_value(&head, 2);

    // Wyświetlanie listy po usunięciu
    printf("Lista po usunieciu elementu o wartosci 2: ");
    print_list(head);

    // Usuwanie listy (dealokacja pamięci)
    delete_list(&head);

    return 0;
}