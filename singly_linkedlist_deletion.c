#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL;

// Create linked list
void create() {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
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

// Delete from beginning
void delete_from_start() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Delete from end
void delete_from_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

// Delete from any position
void delete_at_position() {
    struct node *temp, *nextnode;
    int pos, i = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
    } else {
        temp = head;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
        } else {
            nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
        }
    }
}

// Display linked list
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

    delete_from_start();
    display();

    delete_from_end();
    display();

    delete_at_position();
    display();

    return 0;
}