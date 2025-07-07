#include <stdio.h>
#include <stdlib.h>
#include <random>

typedef struct node{
    int valor;
    struct node *dir;
    struct node *esq;
}Node;

Node *criarNode(int valor){
    Node *n = new Node;
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;

    return n;
}

Node *trocarRaiz(Node *velhaRaiz, int num){
    Node *novaRaiz = criarNode(5);
    
    if(velhaRaiz->valor < novaRaiz->valor) {
        novaRaiz->dir = velhaRaiz->dir;
        velhaRaiz->dir = NULL;
        novaRaiz->esq = velhaRaiz;
    }

    return novaRaiz;
}

void inserirNode(Node *n, int num){

    if(num < n->valor){
        if (n->esq == NULL) {
            n->esq = criarNode(num);
        } else {
            inserirNode(n->esq, num);
        }
    }
    
    if(num > n->valor){
        if(n->dir == NULL){
            n->dir = criarNode(num);
        }else{
            inserirNode(n->dir, num);
        }
    }
}

void remover(Node *raiz, int num){
    Node *filho = raiz;
    Node *pai;

    do{
        pai = filho; //salva o elemento anterior
        if(num < filho->valor){
            filho = filho->esq;
        } else if (num > filho->valor){
            filho = filho->dir;
        }
    } while (filho!=NULL && filho->valor != num);

    if(filho!=NULL){
        if(filho->esq == NULL && filho->dir == NULL){ //sem filhos
            if(pai->esq == filho) pai->esq = NULL;
            if(pai->dir == filho) pai->dir = NULL;
        }

        if(filho->esq != NULL && filho->dir == NULL){ //filho na esquerda
            if(pai->esq == filho) pai->esq = filho->esq;
            if(pai->dir == filho) pai->dir = filho->esq; 
        }

        if(filho->esq == NULL && filho->dir != NULL){ //filho na direita
            if(pai->esq == filho) pai->esq = filho->dir;
            if(pai->dir == filho) pai->esq = filho->dir; 
        }

        if(filho->esq != NULL && filho->dir != NULL){ //filho na direita e esquerda
            if(filho->esq->dir == NULL){
                filho->valor = filho->esq->valor; //apenas troca os valores, n precisa atualizar ponteiros
                filho->esq = NULL;
            } else {
                Node *p = filho->esq; //entendi nada daqui pra baixo
                Node *aux = p;

                while(p->dir != NULL){
                    aux = p;
                    p = p->dir;
                }

                aux->dir = NULL;
                filho->valor = p->valor;
            }
        }
    } 
}

void imprimir(Node *n, int tab=0) {
    if (n == NULL) return;

    imprimir(n->dir, tab + 1);
    for (int i = 0; i < tab; i++) {
        printf("\t");
    }
    printf("%d\n", n->valor);
    imprimir(n->esq, tab + 1);
}

int main(){

    Node *raiz = criarNode(3);

    inserirNode(raiz, 7);
    inserirNode(raiz, 1);
    inserirNode(raiz, 2);
    inserirNode(raiz, 0);
    inserirNode(raiz, 8);
    inserirNode(raiz, 6);

    imprimir(raiz);

    // Node *novaRaiz = trocarRaiz(raiz, 5);
    // inserirNode(novaRaiz, 4);
    // imprimir(novaRaiz);
    // remover(novaRaiz, 3);
    // imprimir(novaRaiz);

    remover(raiz, 2);
    printf("\nApós remorção: \n\n");
    imprimir(raiz);


    remover(raiz, 1);
    printf("\nApós remorção: \n\n");
    imprimir(raiz);
}