#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Define front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to insert at front
void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL) { // Empty deque
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
}

// Function to insert at rear
void insertRear(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) { // Empty deque
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to delete from front
void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = front;
    if (front == rear) { // Only one element
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

// Function to delete from rear
void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = rear;
    if (front == rear) { // Only one element
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

// Function to display deque
void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;
    
    while (1) {
        printf("\n--- Double Ended Queue (Deque) Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
