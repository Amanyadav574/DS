#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *link;
};

// Global top pointer
struct node *top = NULL;

// Push function
void push(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

// Display function
void display() {
    struct node* temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

// Peek function
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Pop function
void pop() {
    if (top == NULL) {
        printf("Underflow! Stack is empty\n");
    } else {
        struct node* temp = top;
        printf("Popped element is %d\n", top->data);
        top = top->link;
        free(temp);
    }
}

// Main function
int main() {
    push(2);
    push(5);
    push(7);
    push(10);

    display();
    peek();
    display();
    pop();
    display();
    peek();
    display();

    return 0;
}