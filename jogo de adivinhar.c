/*
FAÇA UM PROGRAMA QUE GERE UM NÚMERO ALEATÓRIO
ENTRE 0 E 50 E O USUÁRIO DEVE ACERTÁ-LO
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ()
{   
    srand(time(NULL));  
    int num = rand()%50;
    int cont = 0, x, i;


    printf ("GERANDO UM NUMERO ALEATORIO ENTRE 0 E 50\n");
    for(i=0; i<5; i++){
        printf ("-------\n");
        sleep(2000);
    }

    do {
        printf ("\nTENTE ADIVINHAR O NUMERO: ");
        scanf ("%d" , &x);
        if (x == num) {
            printf ("Voce acertou o numero!\n");
            printf ("Numero de tentativas: %d\n" , cont+1);
        } else {
            if (x > num) {
                printf ("Quasee! Tente um numero um pouco mais pra baixo");
                cont++;
            }
            if (x < num) {
                printf ("Quasee! Tente um numero um pouco mais pra cima");
                cont++;
            }
        }
    } while (x != num);
}
