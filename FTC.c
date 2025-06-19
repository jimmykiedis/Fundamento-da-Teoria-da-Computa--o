#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define MAX 20

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//tive que separa a função recebe em 2, pq tava ficando muito cheio de gambiarra
void recebeConjuntos(int *A, int *B, int elementosA, int elementosB) {
    printf("Digite os valores para os vetores A e B, respectivamente:\n");

    for (int i = 0; i < elementosA; i++) {
        printf("Digite o valor %d do vetor A: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("\n");

    for (int i = 0; i < elementosB; i++) {
        printf("Digite o valor %d do vetor B: ", i + 1);
        scanf("%d", &B[i]);
    }
}

void recebePares(int *A, int *B, int pares) {
    printf("Digite os %d pares (A e B):\n", pares);

    for (int i = 0; i < pares; i++) {
        printf("Par %d - A: ", i + 1);
        scanf("%d", &A[i]);

        printf("Par %d - B: ", i + 1);
        scanf("%d", &B[i]);
    }
}

void ereflexivo(int *A, int *B, int pares) {
    bool reflexivo = true;

    for (int i = 0; i < pares; i++) {
        if (A[i] != B[i]) {
            reflexivo = false;
            break;
        }
    }

    if (reflexivo) {
        printf("\nA relacao e reflexiva.\n");
    } else {
        printf("\nA relacao nao e reflexiva.\n");
    }
}

void esimetrico(int *A, int *B, int pares) {
    bool simetrico = true;

    for (int i = 0; i < pares; i++) {
        bool encontrado = false;
        for (int j = 0; j < pares; j++) {
            if (A[i] == B[j] && B[i] == A[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            simetrico = false;
            break;
        }
    }

    if (simetrico) {
        printf("\nA relacao e simetrica.\n");
    } else {
        printf("\nA relacao nao e simetrica.\n");
    }
}

void etransitivo(int *A, int *B, int pares) {
    bool transitiva = true;

    for (int i = 0; i < pares; i++) {
        for (int j = 0; j < pares; j++) {
            if (A[i] == B[j]) {
                bool encontrado = false;
                for (int k = 0; k < pares; k++) {
                    if (B[i] == A[k] && A[j] == B[k]) {
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    transitiva = false;
                    break;
                }
            }
        }
    }
}

void uniao(int *A, int *B, int max) {
    int cont = 0;
    bool primeiro = true;

    printf("\nUniao: [");

    for (int i = 0; i < max; i++) {
        bool duplicado = false;
        for (int j = 0; j < i; j++) {
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

    for (int i = 0; i < max; i++) {
        bool existe = false;
        for (int j = 0; j < max; j++) {
            if (B[i] == A[j]) {
                existe = true;
                break;
            }
        }
        if (!existe) {
            bool duplicado = false;
            for (int j = 0; j < i; j++) {
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

    printf("]\nTotal de elementos na uniao: %d\n", cont);
}

void interseccao(int *A, int *B, int max) {
    int cont = 0;
    bool primeiro = true;

    printf("\nInterseccao: [");

    for (int i = 0; i < max; i++) {
        bool existe = false;
        for (int j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                existe = true;
                break;
            }
        }
        if (existe) {
            bool duplicado = false;
            for (int j = 0; j < i; j++) {
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
    int cont = 0;
    bool primeiro = true;

    printf("\nDiferenca (A - B): [");

    for (int i = 0; i < max; i++) {
        bool existe = false;
        for (int j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                existe = true;
                break;
            }
        }
        if (!existe) {
            bool duplicado = false;
            for (int j = 0; j < i; j++) {
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

void conjuntacao(int *A, int *B) {
    int elementosA, elementosB, op;

    limparTela();

    printf("Bem-vindo ao programa de Conjuntacao!\n"); 
    printf("Este programa permite realizar operacoes de uniao, interseccao e diferenca entre dois conjuntos.\n");
    printf("Os conjuntos serao representados por dois vetores de inteiros, cada um com tamanho maximo de %d elementos.\n", MAX);
    printf("Vamos comecar!\n");

    printf("Quantos elementos deseja inserir no conjunto A (maximo %d)? ", MAX);
    scanf("%d", &elementosA);
    printf("Quantos elementos deseja inserir no conjunto B (maximo %d)? ", MAX);
    scanf("%d", &elementosB);

    recebeConjuntos(A, B, elementosA, elementosB);

    do {
        printf("\nEscolha uma das operacoes:\n");
        printf("    1. Uniao\n");
        printf("    2. Interseccao\n");
        printf("    3. Diferenca\n");
        printf("    0. Voltar ao menu principal\n");
        printf("Opcao: ");

        scanf("%d", &op);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);


        switch (op) {
            case 1:
                uniao(A, B, MAX);
                break;
            case 2:
                interseccao(A, B, MAX);
                break;
            case 3:
                diferenca(A, B, MAX);
                break;
            case 0:
                limparTela();
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

        if (op != 0) {
            printf("\nOperacao concluida.\n");
            printf("\nPressione Enter para continuar...\n");
            while (getchar() != '\n');
        }

    } while (op != 0);
}

void propriedadesRelacionais(int *A, int *B) {
    int pares;

    limparTela();

    printf("Bem-vindo ao programa de propriedades Relacionais!\n"); 
    printf("Este programa permite verificar se seu produto cartesiano é Reflexivo, Simétrico e Transitivo\n");
    printf("Os pares do produto cartesiano serao representados por dois vetores de inteiros, você decide o tamanho (no maximo de %d elementos).\n", MAX);
    printf("Vamos comecar!\n");

    printf("Quantos pares ordenados deseja inserir (maximo %d)? ", MAX);
    scanf("%d", &pares);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    recebePares(A, B, pares);

}

int main() {
    limparTela();

    int A[MAX], B[MAX], op;

    printf("==*== Bem-vindo ao trabalho 2 de Fundamentos de Tecnologia da Computacao! ==*==\n");

    do {
        printf("\nO que deseja fazer primeiro?\n");
        printf("1. Conjuntacao\n");
        printf("2. Propriedades Relacionais\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &op);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);


        switch (op) {
            case 1:
                conjuntacao(A, B);
                break;
            case 2:
                propriedadesRelacionais(A, B);
                break;
            case 0:
                limparTela();
                printf("\nSaindo...\n");
                #ifdef _WIN32
                    Sleep(3000);
                #else
                    sleep(3);
                #endif
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

        if (op != 0) {
            printf("\nPressione Enter para continuar...\n");
            while (getchar() != '\n');
        }

    } while (op != 0);

    return 0;
}
