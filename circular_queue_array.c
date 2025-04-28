#include <stdio.h>
#define N 5

int front = -1, rear = -1;
int queue[N];

// Function to check if the queue is full
int isFull() {
    if ((rear + 1) % N == front)
        return 1; // Queue is full
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1)
        return 1; // Queue is empty
    return 0;
}

// Function to enqueue (add an element)
void enqueue(int x) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (front == -1) // First element to be enqueued
            front = 0;
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("%d enqueued\n", x);
    }
}

// Function to dequeue (remove an element)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("%d dequeued\n", queue[front]);
        if (front == rear) { // Only one element was in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % N;
        }
    }
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // This should show "Queue is full"

    display(); // Display the current queue

    dequeue();
    dequeue();

    display(); // Display the queue after dequeuing

    enqueue(60); // Adding a new element after dequeuing
    display(); // Final display

    return 0;
}