#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

// Estruturas de dados
typedef struct stack {
    char* items[MAX_EXPR_SIZE];
    int top;
} Stack;

typedef struct queue {
    char* items[MAX_EXPR_SIZE];
    int front, rear;
} Queue;

// Funções da pilha
void push(Stack* stack, char* item);
char* pop(Stack* stack);
char* top(Stack* stack);

// Funções da fila
void enqueue(Queue* queue, char* item);
char* dequeue(Queue* queue);

// Funções auxiliares
int is_operator(char c);
int precedence(char c);
int evaluate(char* expr);

// Funções principais
void infix_to_postfix(char* infix, char* postfix);
void evaluate_postfix(char* postfix);

int main() {
    char infix[MAX_EXPR_SIZE];
    printf("Digite a expressão: ");
    fgets(infix, MAX_EXPR_SIZE, stdin);
    char postfix[MAX_EXPR_SIZE];
    infix_to_postfix(infix, postfix);
    printf("Expressão em NPR: %s\n", postfix);
    evaluate_postfix(postfix);
    return 0;
}

void push(Stack* stack, char* item) {
    // implementação
}

char* pop(Stack* stack) {
    // implementação
}

char* top(Stack* stack) {
    // implementação
}

void enqueue(Queue* queue, char* item) {
    // implementação
}

char* dequeue(Queue* queue) {
    // implementação
}

int is_operator(char c) {
    // implementação
}

int precedence(char c) {
    // implementação
}

int evaluate(char* expr) {
    // implementação
}

void infix_to_postfix(char* infix, char* postfix) {
    // implementação
}

void evaluate_postfix(char* postfix) {
    // implementação
}
