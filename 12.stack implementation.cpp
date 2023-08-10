#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop\n");
        return -1; 
    }
    return stack->arr[stack->top--];
}
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];
        
        if (isdigit(symbol)) {
            push(&stack, symbol - '0'); 
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (symbol) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': push(&stack, operand1 / operand2); break;
                default: printf("Invalid operator: %c\n", symbol); return -1;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char postfixExpression[] = "82*5+";
    int result = evaluatePostfix(postfixExpression);

    if (result != -1) {
        printf("Postfix Expression Result: %d\n", result);
    }

    return 0;
}

