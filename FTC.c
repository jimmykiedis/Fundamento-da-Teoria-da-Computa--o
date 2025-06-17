#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

int recebe(int *A, int *B, int max) {
    int i, j;

    for (i = 0; i < max; i++) {
        printf("Digite o valor %d do vetor A: ", i + 1);
        scanf("%d", &A[i]);
    }

    for (j = 0; j < max; j++) {
        printf("Digite o valor %d do vetor B: ", j + 1);
        scanf("%d", &B[j]);
    }
}

int uniao(int *A, int *B, int max) {
    int i, j;

    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                printf("O valor %d do vetor A esta presente no vetor B.\n", A[i]);
            }
        }
    }
}

int interseccao(int *A, int *B, int max) {
    int i, j;

    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                printf("O valor %d do vetor A esta presente no vetor B.\n", A[i]);
            }
        }
    }
}

int diferenca(int *A, int *B, int max) {
    int i, j;

    for (i = 0; i < max; i++) {
        int found = 0;
        for (j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("O valor %d do vetor A nao esta presente no vetor B.\n", A[i]);
        }
    }
}

int main() {
    int A[5], B[5], max = 5, op;

    recebe(A, B, max);

    do {
        printf("\nEscolha uma das operacoes:\n");
        printf("1. Uniao\n");
        printf("2. Interseccao\n");
        printf("3. Diferenca\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                uniao(A, B, max);
                break;
            case 2:
                interseccao(A, B, max);
                break;
            case 3:
                diferenca(A, B, max);
                break;
            case 0:
                printf("Saindo...\n");
                sleep(3);
                break;
            default:
                printf("Opcao invalida!\n");
        }

        if (op != 0) {
            printf("Operacao concluida.\n");
            printf("Pressione Enter para continuar...\n");
            while (getchar() != '\n'); // Limpa o buffer
            getchar(); // Espera Enter
        }

    } while (op != 0);

    return 0;
}

