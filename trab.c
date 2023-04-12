#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_MAX_EXP 100

typedef struct stack {
    char* items[TAM_MAX_EXP];
    int top;
} Stack;

typedef struct queue {
    char* items[TAM_MAX_EXP];
    int front, back;
} Queue;

void push(Stack* stack, char* item) {
    if (stack->top == TAM_MAX_EXP - 1) {
        printf("Erro: Overflow!!!\n");
        exit(1);
    }
    stack->top++;
    stack->items[stack->top] = item;
}

char* pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Erro: Underflow!!!\n");
        exit(1);
    }
    char* item = stack->items[stack->top];
    stack->top--;
    return item;
}

char* top(Stack* stack) {
    if (stack->top == -1) {
        return NULL;
    }
    return stack->items[stack->top];
}

void enqueue(Queue* queue, char* item) {
    if ((queue->back + 1) % TAM_MAX_EXP == queue->front) {
        printf("Erro: Overflow!!!\n");
        exit(1);
    }
    queue->back = (queue->back + 1) % TAM_MAX_EXP;
    queue->items[queue->back] = item;
}

char* dequeue(Queue* queue) {
    if (queue->front == queue->back) {
        printf("Erro: Underflow!!!\n");
        exit(1);
    }
    queue->front = (queue->front + 1) % TAM_MAX_EXP;
    return queue->items[queue->front];
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int evaluate(char* expr) {
    Stack stack;
    stack.top = -1;
    int i = 0;
    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            char* operand = malloc(sizeof(char) * TAM_MAX_EXP);
            int j = 0;
            while (isdigit(expr[i])) {
                operand[j] = expr[i];
                i++;
                j++;
            }
            operand[j] = '\0';
            push(&stack, operand);
            free(operand);
        } else if (is_operator(expr[i])) {
            char* op1 = pop(&stack);
            char* op2 = pop(&stack);
            int result;
            switch (expr[i]) {
                case '+':
                    result = atoi(op2) + atoi(op1);
                    break;
                case '-':
                    result = atoi(op2) - atoi(op1);
                    break;
                case '*':
                    result = atoi(op2) * atoi(op1);
                    break;
                case '/':
                    result = atoi(op2) / atoi(op1);
                    break;
            }
            char* res_str = malloc(sizeof(char) * TAM_MAX_EXP);
            sprintf(res_str, "%d", result);
            push(&stack, res_str);
            free(op1);
            free(op2);
            free(res_str);
        }
    }
    return 0;
}
