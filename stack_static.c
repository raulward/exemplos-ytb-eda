#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int stack[SIZE];
    int top;
} stack;

stack* createStack();
stack* push(int value, stack* stack);
int isStackEmpty(stack* stack);
int pop(stack* stack);
int top(stack* stack);
int isStackFull(stack* stack);

int main() {

    stack* stack = createStack();
    push(10, stack);
    push(14, stack);

    printf("Valores na pilha: ");

    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->stack[i]);
    }

    printf("\n");

    printf("Desempilhando o elemento: %d\n", pop(stack));

    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->stack[i]);
    }

    return 0;
}

stack* createStack() {
    stack *newStack = (stack*)malloc(sizeof(stack));
    newStack->top = -1;
    return newStack;
}

stack* push(int value, stack* stack) {
    if (isStackFull(stack)) {
        return -1;
    }
    ++stack->top;
    stack->stack[stack->top] = value;
}

int isStackEmpty(stack* stack) {
    return stack->top == -1 ? 1 : 0;
}

int pop(stack* stack) {
    if (isStackEmpty(stack)) return -1;
    int value;
    value = stack->stack[stack->top];
    stack->top -= 1;
    return value;
}

int top(stack* stack) {
    if (isStackEmpty(stack)) return -1;
    return stack->stack[stack->top];
}

int isStackFull(stack* stack){ 
    return stack->top == 99;
}
