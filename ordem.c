#include <stdio.h>

int main() {
    int i, a, b, c;

    printf ("Digite\n1 - Ordem Crescente\n2 - Ordem Decrescente\n3 - Maior entre os outros\n");
    scanf ("%d" , &i);

    printf ("digite a, b e c: \n");
    scanf ("%d %d %d" , &a, &b, &c);

   if (i == 1) {
       if (a > b) {
           if (a > c) {
               if (b > c) {
                   printf ("Ordem crescente: %d %d %d" , c , b , a);
               } else {
                   printf ("Ordem crescente: %d %d %d" , b , c , a);
               }
           }
       }

       if (b > a) {
           if (b > c) {
               if (a > c) {
                   printf ("Ordem crescente: %d %d %d" , c , a , b);
               } else {
                   printf ("Ordem crescente: %d %d %d" , a , c , b);
               }
           }
       }

       if (c > a) {
           if (c > b) {
               if (a > b) {
                   printf ("Ordem crescente: %d %d %d" , b , a , c);
               } else {
                   printf ("Ordem crescente: %d %d %d" , a , b , c);
               }
           }
       }
   }

   if (i == 2) {
       if (a > b) {
           if (a > c) {
               if (b > c) {
                   printf ("Ordem decrescente: %d %d %d" , a , b , c);
               } else {
                   printf ("Ordem decrescente: %d %d %d" , a , c , b);
               }
           }
       }

       if (b > a) {
           if (b > c) {
               if (a > c) {
                   printf ("Ordem decrescente: %d %d %d" , b , a , c);
               } else {
                   printf ("Ordem decrescente: %d %d %d" , b , c , a);
               }
           }
       }

       if (c > a) {
           if (c > b) {
               if (a > b) {
                   printf ("Ordem decrescente: %d %d %d" , c , a , b);
               } else {
                   printf ("Ordem decrescente: %d %d %d" , c , b , a);
               }
           }
       }
   }

   if (i == 3) {
       if (a > b) {
           if (a > c) {
               printf ("Maior entre eles: %d %d %d" , b , a , c);
           }
       }

       if (b > a) {
           if (b > c) {
               printf ("Maior entre eles: %d %d %d" , a , b , c);
           }
       }


       if (c > a) {
           if (c > b) {
               printf ("Maior entre eles: %d %d %d" , a , c , b);
           }
       }

   }


    return 0;
}
