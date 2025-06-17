#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <stdbool.h>

int recebe(int *A, int *B, int max) {
    int i, j;

    printf("Digite os valores para os vetores A e B, respectivamente:\n");
    for (i = 0; i < max; i++) {
        printf("Digite o valor %d do vetor A: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("\n");
    for (j = 0; j < max; j++) {
        printf("Digite o valor %d do vetor B: ", j + 1);
        scanf("%d", &B[j]);
    }
}

int uniao(int *A, int *B, int max) {
    int i, j, cont = 0;
    bool primeiro = true;

    printf("\nUniao: [");

    // Imprime todos de A, sem repetição
    for (i = 0; i < max; i++) {
        bool duplicado = false;
        for (j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                duplicado = true;
                break;
            }
        }
        if (!duplicado){
            if (!primeiro) printf(", ");
            printf("%d", A[i]);
            primeiro = false;
            cont++;
        }
    }

    // Imprime de B somente os que não estão em A
    for (i = 0; i < max; i++) {
        bool existe = false;
        for (j = 0; j < max; j++) {
            if (B[i] == A[j]) {
                existe = true;
                break;
            }
        }
        // E evita repetir valores já mostrados de B
        if (!existe) {
            // Também evita duplicados internos de B
            bool duplicado = false;
            for (j = 0; j < i; j++) {
                if (B[i] == B[j]) {
                    duplicado = true;
                    break;
                }
            }
            if (!duplicado) {
                if (!primeiro) printf(", ");
                printf("%d ", B[i]);
                primeiro = false;
                cont++;
            }
        }
    }

    printf("]\nTotal de elementos na uniao: %d", cont);
    printf("\n");

    return 0;
}

int interseccao(int *A, int *B, int max) {
    int i, j, cont = 0;
    bool primeiro = true;

    printf("\nInterseccao: [");

    for (i = 0; i < max; i++) {
        // Verifica se A[i] existe em B
        int existe = 0;
        for (j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                existe = 1;
                break;
            }
        }

        // Evita imprimir duplicados de A
        if (existe) {
            int duplicado = 0;
            for (j = 0; j < i; j++) {
                if (A[i] == A[j]) {
                    duplicado = 1;
                    break;
                }
            }

            if (!duplicado) {
                if (!primeiro) printf(", ");
                printf("%d", A[i]);
                primeiro = false;
                cont++;
            }
        }
    }

    printf("]\nTotal de elementos na interseccao: %d\n", cont);

    return 0;
}

int diferenca(int *A, int *B, int max) {
    int i, j, cont = 0;
    bool primeiro = true;

    printf("\nDiferenca (A - B): [");

    for (i = 0; i < max; i++) {
        // Verifica se A[i] existe em B
        bool existe = false;
        for (j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                existe = true;
                break;
            }
        }

        // Se não existe em B, imprime, evitando duplicatas de A
        if (!existe) {
            bool duplicado = false;
            for (j = 0; j < i; j++) {
                if (A[i] == A[j]) {
                    duplicado = true;
                    break;
                }
            }

            if (!duplicado) {
                if (!primeiro) printf(", ");
                printf("%d", A[i]);
                primeiro = false;
                cont++;
            }
        }
    }

    printf("]\nTotal de elementos na diferenca: %d\n", cont);

    return 0;
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
                printf("\nSaindo...\n");
                sleep(3);
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

        if (op != 0) {
            printf("\nOperacao concluida.\n");
            printf("\nPressione Enter para continuar...\n");
            while (getchar() != '\n'); // Limpa o buffer
            getchar(); // Espera Enter
        }

    } while (op != 0);

    return 0;
}

