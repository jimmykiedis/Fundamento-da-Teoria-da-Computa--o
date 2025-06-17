#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <stdbool.h>

void recebe(int *A, int *B, int max) {
    int i, j;

    // vamos preencher os vetores A e B com valores, respectivamente, de max elementos cada
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

void uniao(int *A, int *B, int max) {
    int i, j, cont = 0;     //queremos mostrar a quantidade de elementos na união no fim da operação
    bool primeiro = true;   //preferi tratar as flags com stdbool para melhor legibilidade

    printf("\nUniao: [");

    //imprimiremos todos de A, sem repetição
    for (i = 0; i < max; i++) {
        bool duplicado = false;
        for (j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                duplicado = true;
                break;
            }
        }
        if (!duplicado){
            if (!primeiro) printf(", "); //vamos colocar a virgula antes de imprimir somente se não for o primeiro elemento
            printf("%d", A[i]);
            primeiro = false;
            cont++;
        }
    }

    //imprimiremos de B somente os que não estão em A
    for (i = 0; i < max; i++) {
        bool existe = false;
        for (j = 0; j < max; j++) {
            if (B[i] == A[j]) {
                existe = true;
                break;
            }
        }
        //evitando repetir valores já mostrados de B
        if (!existe) {
            //também evitando duplicados internos de B
            bool duplicado = false;
            for (j = 0; j < i; j++) {
                if (B[i] == B[j]) {
                    duplicado = true;
                    break;
                }
            }
            if (!duplicado) {
                if (!primeiro) printf(", ");
                printf("%d", B[i]);
                primeiro = false;
                cont++;
            }
        }
    }

    printf("]\nTotal de elementos na uniao: %d", cont);
    printf("\n");
}

void interseccao(int *A, int *B, int max) {
    int i, j, cont = 0;
    bool primeiro = true;

    printf("\nInterseccao: [");

    for (i = 0; i < max; i++) {
        //verificaremos se A[i] existe em B, se existir, imprimiremos
        bool existe = false;
        for (j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                existe = true;
                break;
            }
        }

        //evitaremos imprimir duplicados de A
        if (existe) {
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

    printf("]\nTotal de elementos na interseccao: %d\n", cont);
}

void diferenca(int *A, int *B, int max) {
    int i, j, cont = 0;
    bool primeiro = true;

    printf("\nDiferenca (A - B): [");

    for (i = 0; i < max; i++) {
        //verificaremos se A[i] existe em B
        bool existe = false;
        for (j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                existe = true;
                break;
            }
        }

        //se não existir em B, imprime, evitando duplicatas de A
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
}

int main() {
    int max = 5;            //definindo o tamanho máximo dos vetores em um unico lugar para facilitar a manutenção
    int A[max], B[max], op; //vetores A e B para armazenar os valores, e op para a opção do usuário

    recebe(A, B, max);      //vamos separar por função cada operação para melhor organização do código

    do {
        printf("\nEscolha uma das operacoes:\n");
        printf("    1. Uniao\n");
        printf("    2. Interseccao\n");
        printf("    3. Diferenca\n");
        printf("    0. Sair\n");
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

