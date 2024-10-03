#include <stdlib.h>
#include <stdio.h>

typedef struct nodeitem {
    int info;
    struct nodeitem* next;
} node;


typedef struct {
    node* top;
} dinamicStack;


dinamicStack* createNewStack();
void push(int info, dinamicStack* stack);
int pop(dinamicStack* stack);
int top(dinamicStack* stack);
int isStackEmpty(dinamicStack* stack);

int main() {

    dinamicStack *stack = createNewStack();
    push(10, stack);
    push(29, stack);
    push(21, stack);

    printf("O topo da pilha: %d\n", top(stack));
    printf("Retirando topo\n");
    pop(stack);
    printf("Novo topo: %d\n", top(stack));

    return 0;
}

dinamicStack* createNewStack() {
    dinamicStack *newStack = (dinamicStack*)malloc(sizeof(dinamicStack));
    newStack->top = NULL;
    return newStack;
}

void push(int info, dinamicStack* stack) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->info = info;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(dinamicStack* stack) {
    if (isStackEmpty(stack)) return -1;
    node *temp = stack->top;  
    int value = temp->info;
    stack->top = temp->next;
    free(temp);
    return value;
}

int top(dinamicStack* stack){
    if (isStackEmpty(stack)) return -1;
    int value = stack->top->info;
    return value;
}

int isStackEmpty(dinamicStack* stack) {
    return stack->top == NULL;
}