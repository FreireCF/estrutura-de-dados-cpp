#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(void){
    int n;
    printf("\nInsira o tamanho do vetor: ");
        scanf("%d",&n);
    int* vetor = (int*) malloc(n * sizeof(int));
    int ordenado, troca;

    printf("\nPreenchendo o vetor com %d números aleatórios",n);
    printf("\n...");

    srand(time(NULL));

    for(int i=0; i<n; i++){
        vetor[i] = rand()%100;
    }
    printf("\n");
    printf("\nVetor preenchido: ");
    printf("[");
    for(int i=0; i<n; i++){
        printf(" %d ",vetor[i]);
    }
    printf("]");

    printf("\n");
    printf("\nOrdenando o vetor");
    printf("\n...");

    do {
        troca=0;
        for(int i=0; i<n-1; i++){
            if(vetor[i] > vetor [i+1]){
                ordenado = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = ordenado;
                troca = 1;    
            } 
    }
} while (troca==1);

    printf("\n");
    printf("\nVetor ordenado: ");
    printf("[");
    
    for(int i=0; i<n; i++){
        printf(" %d ",vetor[i]);
    }
    printf("]");
    free(vetor);
    printf("\n \n");
}