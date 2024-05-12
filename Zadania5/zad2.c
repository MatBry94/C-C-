#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do dodawania elementu na początek listy
void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Tworzenie nowego elementu
    if (new_node == NULL) {
        printf("Blad alokacji pamieci\n");
        return;
    }
    new_node->data = data; // Ustawienie wartości nowego elementu
    new_node->next = *head_ref; // Powiązanie nowego elementu z aktualnym nagłówkiem
    *head_ref = new_node; // Ustawienie nowego elementu jako nagłówek listy
}

// Funkcja do usuwania pierwszego elementu z listy
void pop(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, brak elementu do usuniecia\n");
        return;
    }
    struct Node* temp = *head_ref; // Zapamiętanie pierwszego elementu
    *head_ref = (*head_ref)->next; // Przestawienie nagłówka na następny element
    free(temp); // Zwolnienie pamięci pierwszego elementu
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

    // Dodawanie elementów na początek listy
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    // Wyświetlanie listy przed usunięciem
    printf("Lista przed usunieciem pierwszego elementu: ");
    print_list(head);

    // Usuwanie pierwszego elementu z listy
    pop(&head);

    // Wyświetlanie listy po usunięciu
    printf("Lista po usunieciu pierwszego elementu: ");
    print_list(head);

    // Usuwanie listy (dealokacja pamięci)
    delete_list(&head);

    return 0;
}