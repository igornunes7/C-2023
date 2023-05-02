//Faça um programa que calcule a distância
//entre dois pontos


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    float x1,y1,z1,x2,y2,z2,d, aux1,aux2,aux3, aux4 = 0;

    scanf ("%f %f %f", &x1, &y1, &z1);
    scanf ("%f %f %f", &x2, &y2, &z2);

    aux1 = pow (x2 - x1 , 2);
    aux2 = pow (y2 - y1 , 2);
    aux3 = pow (z2 - z1 , 2);
    aux4 = aux1 + aux2 + aux3;

    d = sqrt(aux4);

    printf ("%.10f" , d);

}
