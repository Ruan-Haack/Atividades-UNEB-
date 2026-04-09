#include <stdio.h>


int main () {
    int contpassou = 0;
    float media = 0;
    float notas[] = {6.5, 5.4, 7, 6.5, 4, 8, 7.8, 9.6, 7.4, 10};

    for (int i = 0; i < 10; i++) {
        
        media += notas[i];

        if (notas[i] >= 7) { //media 7
            contpassou += 1;
        } 
    }
        media = media/10;
        
        printf("A média das notas eh: %.2f \n", media);
        printf("A qtd de notas que passaram na media eh: %d \n", contpassou);
        
    return 0;
}


