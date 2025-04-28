#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create linked list
void create() {
    struct node *newnode, *temp;
    int choice = 1;
    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (0 for No, 1 for Yes)? ");
        scanf("%d", &choice);
    }
}

// Function to insert at beginning
void insert_at_beginning() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

// Function to insert at end
void insert_at_end() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert at end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to insert at any position
void insert_at_position() {
    struct node *newnode, *temp;
    int pos, i = 1, count = 0;
    
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    printf("Enter the position to insert (1 to %d): ", count + 1);
    scanf("%d", &pos);
    
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }
    
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Function to display linked list
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    create();
    display();

    insert_at_beginning();
    display();

    insert_at_end();
    display();

    insert_at_position();
    display();

    return 0;
}