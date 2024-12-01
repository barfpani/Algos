#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for linked list in case of collisions
typedef struct Node {
    char *key;
    struct Node *next;
} Node;

// Hash table
Node *hash_table[TABLE_SIZE];

// Hash function
unsigned int hash_function(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key);
        key++;
    }
    return hash % TABLE_SIZE;
}

// Insert a key into the hash table
void insert(const char *key) {
    unsigned int index = hash_function(key);

    // Create a new node
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->next = NULL;

    // Insert at the head of the linked list for that index
    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        Node *current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Search for a key in the hash table
int search(const char *key) {
    unsigned int index = hash_function(key);
    Node *current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node *current = hash_table[i];
        while (current != NULL) {
            printf("%s -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Free memory allocated for the hash table
void free_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hash_table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
}

int main() {
    // Initialize hash table to NULL
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }

    // Insert keys into the hash table
    insert("Sanchit");
    insert("Rachit");
    insert("Saad");
    insert("Adya");
    insert("Divyam");

    // Display the hash table
    display();

    // Search for keys
    printf("\nSearching for 'Alice': %s\n", search("Alice") ? "Found" : "Not Found");
    printf("Searching for 'Zoe': %s\n", search("Zoe") ? "Found" : "Not Found");

    // Free memory
    free_table();

    return 0;
}
