/*
Crie um programa que leia um numero qualquer entre 0 e 200.
Diga quantos números estão presentes no intervalo de [0, 100] e [101 , 200]
Diga a média dos números nesses mesmos intervalos
*/

#include <stdio.h>

int main() {
    int N;
    float aux1, aux2, cont1, cont2, media1, media2;

    aux1 = 0;
    aux2 = 0;
    cont1 = 0;
    cont2 = 0;

    do {
        printf ("Digite um numero: \n");
        scanf ("%d" , &N);

        if ((N >= 0) && (N <= 100)) {
            aux1 += N;
            cont1 += 1;
        }

        if ((N >= 101) && (N <= 200)) {
            aux2 += N;
            cont2 += 1;
        }

    } while (N >= 0);

    media1 = aux1/cont1;
    media2 = aux2/cont2;

    printf ("Media primeiro intervalo: %.1f\n" , media1);
    printf ("Media segundo intervalo: %.1f\n" , media2);

    printf ("Numeros presentes no primeiro intervalo: %.1f\n" , cont1);
    printf ("Numeros presentes no segundo intervalo: %.1f\n" , cont2);

    return 0;
}
