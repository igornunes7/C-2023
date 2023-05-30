/*
 Um determinado material radioativo perde metade de sua massa a cada 50 segundos. 
 Dada a massa inicial, em gramas, fazer um programa em C 
 que calcule o tempo necessário para que essa massa se torne menor que 0.5 grama. 
 O programa em C deve escrever a massa inicial, a massa final e o tempo calculado 
 em horas, minutos e segundos.
*/


#include <stdio.h>

int main () {
    float massa, aux, massa_inicial;
    int cont = 0, horas, min, seg, tempo;
    

    printf ("Digite a massa: \n");
    scanf ("%f" , &massa);

    massa_inicial = massa;

    while (massa >= 0.5) {
        aux = massa/2;
        massa = massa - aux;
        cont++;
    }

    tempo = 50 * cont;

    horas = tempo / 3600;
    min = (tempo % 3600) / 60;
    seg = (tempo % 3600) % 60;

    printf ("Massa inicial: %.3f\n" , massa_inicial);
    printf ("Massa final: %.3f\n" , massa);
    printf ("Horas: %d\nMinutos: %d\nSegundos: %d\n" , horas, min, seg);

}
