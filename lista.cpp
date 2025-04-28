#include <stdio.h>
#include <stdlib.h> 

/*Criando uma lista encadeada */

typedef struct Ponto {
    float x, y;  
    struct Ponto *prox; //ponteiro que aponta para o próximo item da lista
} Ponto; //tipo do dado

/* int main(){
    Ponto *p0 = (Ponto*) malloc(sizeof(Ponto));
    p0 ->x = 1;
    p0->y = 5;

    Ponto *p1 = (Ponto*) malloc(sizeof(Ponto));
    p1->x = 3;
    p1->y = 9;

    Ponto *p2 = (Ponto*) malloc(sizeof(Ponto));
    p2->x = 3;
    p2->y = 9;

    p0->prox = p1; //o ponteiro prox do p0 aponta para p1, ou seja, o próximo ponto do p0 é o p1
    p1->prox = p2; 
    p2->prox = NULL;
    Dessa forma, teríamos que criar vários pontos e alocações. O que se torna inviável fazer assim. 
} */

// Para resolver este problema, criaremos uma função com um único ponteiro que recebe o primeiro item, e então, todos os outros apontarão para o próximo

Ponto *primeiroItem=NULL; //ponteiro para apontar o primeiro elemento da lista e ser seguido pelos demais itens. Só é necessário guardar o primeiro e através dele, acessaremos os seguintes.

void adicionarElemento (float x, float y){ //coordenadas de um plano cartesiano
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->prox = primeiroItem; //  p aponta para o primeiro item da lista
    primeiroItem = p; //primeiroItem recebe o valor de p (primeriro item da lista)
}

void imprimirLista(){
  Ponto *aux = primeiroItem; //recebe o primeiro item da lista, sem meexer no primeitoItem para que não seja perdido
    while(aux!=NULL){ //se a lista estiver vazia, não inicializa
      printf("\n(x: %.2f, y: %.2f)", aux->x, aux->y);
      aux = aux->prox; //irá receber o seu próximo elemento na lista, até encontrar um NULL e encerrar
    }
    printf("\n");
}

int main(){
    adicionarElemento(1, 5); 
    adicionarElemento(0, 10);
    adicionarElemento(3, 9); //adiciona no início da lista
    imprimirLista();

}
