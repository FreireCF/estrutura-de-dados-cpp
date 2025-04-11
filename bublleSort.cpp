#include <stdio.h> 
#include <math.h>

int main(void){
    int n;
    printf("\nInsira o tamanho do vetor: ");
        scanf("%d",&n);
    int vetor[n];

    printf("\nPreenchendo o vetor com %d números aleatórios",n);
    printf("\n...");

    for(int i=0; i<n; i++){
        vetor[i] = rand()%10;
    }

    printf("\nVetor preenchido: ");
    printf("[");
    for(int i=0; i<n; i++){
        printf(" %d ",vetor[i]);
    }
    printf("]");

    printf("\nOrdenando o vetor");
    printf("\n...");

    for(int i=0; i<n; i++){
        if(vetor[i] > vetor [i+1]){
            
        }
    }

    printf("\n \n");
}