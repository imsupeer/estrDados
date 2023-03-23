#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

struct aluno {
    char nome[81];
    float nota;
};

int cmpNome(const void *a, const void *b) {
    Aluno **pa = (Aluno **)a;
    Aluno **pb = (Aluno **)b;
    return strcmp((*pa)->nome, (*pb)->nome);
}

int cmpAluno(const void *a, const void *b) {
    char *nome = (char *)a;
    Aluno **pb = (Aluno **)b;
    return strcmp(nome, (*pb)->nome);
}

int main() {
    Aluno *alunos[5];
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

    qsort(alunos, 5, sizeof(Aluno *), cmpNome);

    char nomeBusca[81];
    printf("Informe o nome do aluno: ");
    scanf("%s", nomeBusca);
    Aluno **ptr = (Aluno **)bsearch(nomeBusca, alunos, 5, sizeof(Aluno *), cmpAluno);

    if (ptr != NULL) {
        printf("Aluno encontrado: %s (nota: %.1f)\n", (*ptr)->nome, (*ptr)->nota);
    } else {
        printf("Aluno não encontrado.\n");
    }

    return 0;
}
