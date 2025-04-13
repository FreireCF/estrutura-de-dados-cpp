#include <math.h>
#include <stdio.h>
#include <time.h>
#include <random>

void inicia_vetor(int *vetor, int n) {
  srand(clock()); //seed (clock: tempo atual) para gerar os números aleatórios
    for (int i = 0; i < n; i++) {
      vetor[i] = (abs(rand()) % 100);
  }
}

void imprimir(int *vetor, int n) {
  printf("[");
    for (int i = 0; i < n; i++) {
      printf(" %d ", vetor[i]);
  }
  printf("]\n");
  printf("\n");
}

void troca(int *vetor, int i, int j) {
  int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void bubbleSort(int *vetor, int n){
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-1-i; j++){
      if(vetor[j]>vetor[j+1]){
        troca(vetor, j, j+1);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int n = 0;
  printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
  int vetor[n];

  inicia_vetor(vetor, n);
  printf("\nVetor gerado: ");
  imprimir(vetor, n);

  bubbleSort(vetor, n);

  printf("\nVetor ordenado: ");
  imprimir(vetor, n);
}