#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do dodawania elementu na określonym indeksie w liście
void insert_at_index(struct Node** head_ref, int index, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Tworzenie nowego elementu
    if (new_node == NULL) {
        printf("Blad alokacji pamieci\n");
        return;
    }
    new_node->data = data; // Ustawienie wartości nowego elementu

    // Wstawienie nowego elementu na początek listy, jeśli indeks wynosi 0
    if (index == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    // Przesunięcie temp na indeks poprzedzający wstawiany
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    // Jeśli indeks przekracza długość listy
    if (temp == NULL) {
        printf("Indeks przekracza rozmiar listy\n");
        return;
    }

    // Wstawienie nowego elementu po elemencie o indeksie poprzednim do wstawianego
    new_node->next = temp->next;
    temp->next = new_node;
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
    insert_at_index(&head, 0, 1);
    insert_at_index(&head, 1, 3); // Wstawianie elementu na indeksie 1
    insert_at_index(&head, 1, 2); // Wstawianie elementu na indeksie 1
    insert_at_index(&head, 3, 4); // Wstawianie elementu na indeksie 3

    // Wyświetlanie listy po dodaniu elementów na określonych indeksach
    printf("Lista po dodaniu elementow na okreslonych indeksach: ");
    print_list(head);

    // Usuwanie listy (dealokacja pamięci)
    delete_list(&head);

    return 0;
}