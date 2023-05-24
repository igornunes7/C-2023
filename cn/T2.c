//Resolução de sistema linear pelo método de Gauss-Jacobi

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void gaussJacobi(int ordem, float matriz[ordem][ordem], float termo_ind[ordem], float sol_inicial[ordem], float erro) {
    int i, j, cont = 0;
    bool aux = true;
    clock_t inicio, fim;

    float x[ordem], // nova soluções
    x_ant[ordem], // solução anterior
    dif;

    inicio = clock();
    printf("\nIteracao %d:\n", cont);
    printf("Solucao Inicial:\n");
    for (i = 0; i < ordem; i++) {
        printf("x%d = %f\n", i + 1, sol_inicial[i]);
    }

    while (aux) {
        for (i = 0; i < ordem; i++) {
            x_ant[i] = sol_inicial[i];
            x[i] = termo_ind[i];

            for (j = 0; j < ordem; j++) {
                if (j != i) {
                    x[i] -= matriz[i][j] * x_ant[j];
                }
            }

            x[i] /= matriz[i][i];
        }

        cont++;

        printf("\nIteracao %d:\n", cont);
        printf("Solucao:\n");
        for (i = 0; i < ordem; i++) {
            printf("x%d = %f\n", i + 1, x[i]);
        }

        dif = 0.0;
        for (i = 0; i < ordem; i++) {
            dif += fabs(x[i] - x_ant[i]);
            sol_inicial[i] = x[i];
        }

        if (dif < erro) {
            break;
        }
    }

    printf("\nSolucao final:\n");
    for (i = 0; i < ordem; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }
    fim = clock();


    float tempo_gasto = ((float) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %.7lf segundos\n", tempo_gasto);
}

int main() {
    int i, j, ordem;
    printf("Ordem da matriz: ");
    scanf("%d", &ordem);

    float matriz[ordem][ordem], termo_ind[ordem], sol_inicial[ordem], erro;


    //Pedindo os elementos do sistema
    printf("Digite os elementos do sistema:\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("Matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    //Pedindo os termos independentes
    printf("Digite os termos independentes:\n");
    for (i = 0; i < ordem; i++) {
        scanf("%f", &termo_ind[i]);
    }


    //Pedindo a solução inicial
    printf("Digite a solucao inicial:\n");
    for (i = 0; i < ordem; i++) {
        scanf("%f", &sol_inicial[i]);
    }


    //Pedindo o erro
    printf("Digite o erro:\n");
    scanf("%f", &erro);



    //Imprindo o sistema
    printf("\nO sistema digitado foi:\n");
    for(i = 0; i < ordem; i++) {
        for(j = 0; j < ordem; j++) {
            printf("%0.7f ", matriz[i][j]);
        }
        printf("\n");
    }


    //Imprimindo os termos independentes
    printf ("\nTermos independentes:\n");
    for (i = 0; i < ordem; i++) {
        printf ("%0.7f\n" , termo_ind[i]);
    }


    //Imprimindo a solução inicial
    printf ("\nSolucao Inicial:\n");
    for (i = 0; i < ordem; i++) {
        printf ("%0.7f\n" , sol_inicial[i]);
    }


    //Imprimindo o erro
    printf ("\nErro = %0.7f\n" , erro);


    gaussJacobi(ordem, matriz, termo_ind, sol_inicial, erro);


    return 0;
}
