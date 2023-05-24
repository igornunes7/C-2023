//Inversão de matrizes pelo método de Jordan

#include <stdio.h>
#include <time.h>

void mostrar_matriz(int ordem, float matriz[][ordem]) {
    int i, j;
    printf("\nA matriz digitada foi:\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int ordem, i, j, k;

    printf("Ordem da matriz: ");
    scanf("%d", &ordem);

    float matriz[ordem][ordem], identidade[ordem][ordem], resultado[ordem][ordem * 2], aux, m, div;
    double tempo;

    // Pedindo a matriz
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("Matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    clock_t inicio = clock();
    // Imprimindo a matriz
    printf("\nA matriz digitada foi:\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("%0.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    // Fazendo a matriz identidade e mostrando minha matriz original + identidade
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            if (i == j) {
                identidade[i][j] = 1.0;
            } else {
                identidade[i][j] = 0;
            }
        }
    }

    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            resultado[i][j] = matriz[i][j];
        }
    }

    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem * 2; j++) {
        }
    }

    for (i = 0; i < ordem; i++) {
        for (j = ordem; j < ordem * 2; j++) {
            resultado[i][j] = identidade[i][j - ordem];
        }
    }

    printf("\nResultante\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem * 2; j++) {
            printf("%0.2f ", resultado[i][j]);
        }
        printf("\n");
    }

    // Verificando se o pivô é 0 e realizando a troca
    for (i = 0; i < ordem; i++) {
        if (resultado[i][i] == 0) {
            for (k = i + 1; k < ordem; k++) {
                if (resultado[k][i] != 0) {
                    for (j = 0; j < ordem * 2; j++) {
                        aux = resultado[k][j];
                        resultado[k][j] = resultado[i][j];
                        resultado[i][j] = aux;
                    }
                    break;
                }
            }
        }
    }

    // Imprimindo matriz pós troca
    printf("\nApos troca\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem * 2; j++) {
            printf("%0.2f ", resultado[i][j]);
        }
        printf("\n");
    }

    // Realizando as operações nas linhas
    for (j = 0; j < ordem; j++) {
        for (i = 0; i < ordem; i++) {
            if (i != j) {
                m = -resultado[i][j] / resultado[j][j];
                for (k = 0; k < ordem * 2; k++) {
                    resultado[i][k] += m * resultado[j][k];
                }
            }
        }
    }

    // Tornando a diagonal principal igual a 1 caso precise
    for (i = 0; i < ordem; i++) {
        div = resultado[i][i];
        for (j = 0; j < ordem * 2; j++) {
            resultado[i][j] /= div;
        }
    }

    // Imprimindo matriz pós operações
    printf("\nApos operacoes nas linhas\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem * 2; j++) {
            printf("%0.2f ", resultado[i][j]);
        }
        printf("\n");
    }


    clock_t fim = clock();
    //Mostrando apenas a inversa
    printf ("\nMatriz Inversa:\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("%0.2f ", resultado[i][j + ordem]);
        }
        printf("\n");
    }

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo: %lf segundos\n", tempo);

    return 0;
}
