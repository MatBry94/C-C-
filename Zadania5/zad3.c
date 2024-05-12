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

// Funkcja do usuwania ostatniego elementu z listy
void remove_last(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, brak elementu do usuniecia\n");
        return;
    }
    if ((*head_ref)->next == NULL) {
        free(*head_ref); // Jeśli lista zawiera tylko jeden element, usuń go
        *head_ref = NULL;
        return;
    }
    struct Node* current = *head_ref;
    while (current->next->next != NULL) {
        current = current->next; // Przechodzenie na przedostatni element listy
    }
    free(current->next); // Zwolnienie pamięci ostatniego elementu
    current->next = NULL; // Ustawienie wskaźnika next ostatniego elementu na NULL
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

    // Wyświetlanie listy przed usunięciem
    printf("Lista przed usunieciem ostatniego elementu: ");
    print_list(head);

    // Usuwanie ostatniego elementu z listy
    remove_last(&head);

    // Wyświetlanie listy po usunięciu
    printf("Lista po usunieciu ostatniego elementu: ");
    print_list(head);

    // Usuwanie listy (dealokacja pamięci)
    delete_list(&head);

    return 0;
}