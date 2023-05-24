//Resoluções de sistemas lineares usando o método Gauss-Jacobi

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void gaussJacobi(int ordem, double matriz[ordem][ordem], double termo_ind[ordem], double sol_inicial[ordem], double erro) {
    int i, j, cont = 0;
    bool aux = true;
    clock_t inicio, fim;

    double x[ordem], // nova solução
    x_ant[ordem], // solução anterior
    dif;

    inicio = clock();
    printf("\nIteracao %d:\n", cont);
    printf("Solucao Inicial:\n");
    for (i = 0; i < ordem; i++) {
        printf("x%d = %.7lf\n", i + 1, sol_inicial[i]);
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
            printf("x%d = %.7lf\n", i + 1, x[i]);
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
        printf("x%d = %.7lf\n", i + 1, x[i]);
    }
    fim = clock();


    double tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %.7lf segundos\n", tempo_gasto);
}

int main() {
    int i, j, ordem;
    printf("Ordem da matriz: ");
    scanf("%d", &ordem);

    double matriz[ordem][ordem], termo_ind[ordem], sol_inicial[ordem], erro;


    //Pedindo os elementos do sistema
    printf("Digite os elementos do sistema:\n");
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("Matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    //Pedindo os termos independentes
    printf("Digite os termos independentes:\n");
    for (i = 0; i < ordem; i++) {
        scanf("%lf", &termo_ind[i]);
    }


    //Pedindo a solução inicial
    printf("Digite a solucao inicial:\n");
    for (i = 0; i < ordem; i++) {
        scanf("%lf", &sol_inicial[i]);
    }


    //Pedindo o erro
    printf("Digite o erro:\n");
    scanf("%lf", &erro);



    //Imprindo o sistema
    printf("\nO sistema digitado foi:\n");
    for(i = 0; i < ordem; i++) {
        for(j = 0; j < ordem; j++) {
            printf("%.7lf ", matriz[i][j]);
        }
        printf("\n");
    }


    //Imprimindo os termos independentes
    printf ("\nTermos independentes:\n");
    for (i = 0; i < ordem; i++) {
        printf ("%.7lf\n" , termo_ind[i]);
    }


    //Imprimindo a solução inicial
    printf ("\nSolucao Inicial:\n");
    for (i = 0; i < ordem; i++) {
        printf ("%.7lf\n" , sol_inicial[i]);
    }


    //Imprimindo o erro
    printf ("\nErro = %.7lf\n" , erro);


    gaussJacobi(ordem, matriz, termo_ind, sol_inicial, erro);


    return 0;
}
