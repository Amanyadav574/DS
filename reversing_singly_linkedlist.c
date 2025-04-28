#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Reverse the linked list using a stack
struct Node* reverseList(struct Node* head) {
    struct Node* stack[1000];
    int top = -1;
    struct Node* temp = head;

    // Push all nodes onto the stack
    while (temp != NULL) {
        stack[++top] = temp;
        temp = temp->next;
    }

    // Pop nodes and rebuild the list
    if (top >= 0) {
        head = stack[top--];
        temp = head;
        while (top >= 0) {
            temp->next = stack[top--];
            temp = temp->next;
        }
        temp->next = NULL;
    }

    return head;
}

// Print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Given Linked List: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}