/*
Escreva um programa que leia dois vetores de números inteiros A e B com N
elementos cada e calcule a soma dos elementos desses vetores de forma intercalada, ou seja, o
primeiro elemento de A mais o primeiro elemento de B, o segundo elemento de A mais o
segundo elemento de B, e assim por diante. O programa deve imprimir a soma intercalada. Por
exemplo, se A = {1, 2, 3} e B = {4, 5, 6}, a soma intercalada é {5, 7, 9}, e o programa deve
imprimir: 
*/


#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, A[40], B[40], C[40], i;

    scanf ("%d", &n);

    for (i = 0; i < n; i++) {
        printf ("Valor de A: \n");
        scanf ("%d", &A[i]);
    }

    for (i = 0; i < n; i++) {
        printf ("Valor de B: \n");
        scanf ("%d", &B[i]);
    }

    for (i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }

    printf ("Valor de C: \n");
    for (i = 0; i < n; i++) {
        printf ("%d", C[i]);
        printf (" ");
    }
    
    printf ("\n");
}
