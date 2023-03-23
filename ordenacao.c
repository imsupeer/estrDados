#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

struct aluno {
    char nome[81];
    float nota;
};

int comparar_alunos(const void *a, const void *b) {
    const Aluno *aluno_a = *(const Aluno **)a;
    const Aluno *aluno_b = *(const Aluno **)b;

    if (aluno_a->nota > aluno_b->nota) {
        return -1;
    } else if (aluno_a->nota < aluno_b->nota) {
        return 1;
    } else {
        return strcmp(aluno_a->nome, aluno_b->nome);
    }
}

void ordenar_alunos(Aluno **alunos, int num_alunos) {
    qsort(alunos, num_alunos, sizeof(Aluno *), comparar_alunos);
}

int main() {
    int num_alunos = 5;
    Aluno **alunos = malloc(num_alunos * sizeof(Aluno *));
    if (alunos == NULL) {
        printf("Erro ao alocar, memoria insuficiente!\n");
        exit(EXIT_FAILURE);
    }

    alunos[0] = malloc(sizeof(Aluno));
    strcpy(alunos[0]->nome, "Joseph");
    alunos[0]->nota = 7.5;

    alunos[1] = malloc(sizeof(Aluno));
    strcpy(alunos[1]->nome, "Lucas");
    alunos[1]->nota = 8.0;

    alunos[2] = malloc(sizeof(Aluno));
    strcpy(alunos[2]->nome, "Fabio");
    alunos[2]->nota = 9.5;

    alunos[3] = malloc(sizeof(Aluno));
    strcpy(alunos[3]->nome, "Pedro");
    alunos[3]->nota = 7.5;

    alunos[4] = malloc(sizeof(Aluno));
    strcpy(alunos[4]->nome, "Carlos");
    alunos[4]->nota = 9.0;

    ordenar_alunos(alunos, num_alunos);

    printf("Alunos ordenados:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("%s - %.1f\n", alunos[i]->nome, alunos[i]->nota);
    }

    for (int i = 0; i < num_alunos; i++) {
        free(alunos[i]);
    }
    free(alunos);

    return 0;
}
