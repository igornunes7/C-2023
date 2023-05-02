//Crie um programa que retorne o tipo de triângulo, dados os comprimentos dos lados

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int a,b,c;

    scanf ("%d",&a);
    scanf ("%d",&b);
    scanf ("%d",&c);

    if (abs(b - c) < a && a < b + c) {
        if (abs(a - c) < b && b < a + c) {
            if (abs (a - b) < c && c < a + b) {
                if (a == b && a == c && b == c) {
                    printf ("equilatero");
                } else if (a == b || a == c || b == c) {
                    printf ("isosceles");
                } else {
                    printf ("scaleno");
                }
            } else {
               printf ("nao e triangulo"); 
            }
        } else {
            printf ("nao e triangulo");
        }
    } else {
        printf ("nao e triangulo");
    }
}
