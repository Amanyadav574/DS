#include <stdio.h>
#include <ctype.h>

#define MAX 100

float stack[MAX];
int top = -1;

// Push value onto stack
void push(float val) {
    if (top == MAX - 1)
        printf("\nStack Overflow\n");
    else
        stack[++top] = val;
}

// Pop value from stack
float pop() {
    if (top == -1) {
        printf("\nStack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Evaluate postfix expression
float evaluatePostfix(char exp[]) {
    int i = 0;
    float op1, op2, result;

    while (exp[i] != '\0' && exp[i] != '\n') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); // Convert char digit to number
        } 
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%') {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = (int)op1 % (int)op2; break;
            }

            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[100];
    float value;

    printf("Enter a postfix expression: ");
    fgets(exp, sizeof(exp), stdin);  // Safe input

    value = evaluatePostfix(exp);
    printf("Value of postfix expression = %.2f\n", value);

    return 0;
}