#include <stdio.h>
#define N 5

int top = -1; // global declaration

int stack[N];

void push()
{
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if (top == N - 1)
    {
        printf("Overflow condition\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow condition\n");
    }
    else
    {
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Element at top is %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void main()
{
    int ch;
    do
    {
        printf("Enter choice: 1.push 2.pop 3.peek 4.display 0.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            if (ch != 0)
                printf("Invalid choice\n");
            break;
        }
    } while (ch != 0);
}