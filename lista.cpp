#include <stdio.h>
#include <stdlib.h> 

typedef struct node{ //struct de cada Nó (ou cédula) da nossa lista
    int elemento; //o elemento do nó
    struct node *prox; //ponteiro que aponta para o próximo nó na lista
} Node;

void inserirInicio(Node **lista, int novoElemento){ //inserir um número no início da lista
    Node *novoNo= (Node*) malloc(sizeof(Node)); //criamos e alocamos dinâmicamente um novo nó

    if(novoNo){ //conferir se a alocação funcionou 
        novoNo->elemento = novoElemento; //o elemento do nosso nó, irá receber o int passado com parâmetro
        novoNo->prox = *lista; //o próximo irá apontar para o topo da lista, ou seja, todos as outras cédulas virão após o novoNo.
        *lista = novoNo; //adicionando o novo Nó na lista
    } else {
        printf("\nErro ao alocar memória!"); 
    }
}

void inserirFinal(Node **lista, int novoElemento){ //inserir um número no fim da lista
    Node *aux, *novoNo = (Node*) malloc(sizeof(Node));

    if(novoNo){ 
        novoNo->elemento = novoElemento; 
        novoNo->prox = NULL; //como iremos inserir no final da lista, o próximo do nosso novo nó tem que ser NULL
        if(*lista == NULL){ //na primeira inserção, nossa lista estará vazia, então podemos inserir normalmente
            *lista = novoNo; 
        } else {
            aux = *lista; //variável auxiliar para percorrer a lista sem perder a original
            while(aux->prox!=NULL){ //percorre a lista até o pŕoximo apontar para NULL, ou seja, até o último elemento
                aux = aux->prox; // auxiliar recebe seu próximo elemento
            }
            aux->prox = novoNo; //aṕos encontrarmos o elemento que o seu próximo é null, inserimos nosso novoNo após ele
        }
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void inserirMeio(Node **lista, int novoElemento, int anterior){ //iremos inserir depois do anterior
    Node *aux, *novoNo = (Node*) malloc(sizeof(Node));

    if(novoNo){
        novoNo->elemento = novoElemento;
        //caso a lista esteja vazia, podemos inserir normalmente
        if(*lista==NULL){
            novoNo->prox = NULL;
            *lista = novoNo;
        } else {
            aux = *lista;
            while(aux->elemento!=anterior && aux->prox!=NULL){ //iremos percorrer até encontrar o anterior informado
                aux = aux->prox;
            }
            novoNo->prox = aux->prox; // novo nó vai apontar para o próximo do nó encontrado
            aux->prox = novoNo; // o "anterior" agora aponta para o novo nó    
        }
    } else {
        printf("\nErro ao alocar memória!");
    }
}

Node* buscarElemento(Node **lista, int buscar){ 
    Node *aux = *lista, *endereco = NULL;
    
    while(aux->prox!=NULL && aux->elemento!=buscar){
        aux = aux->prox;
    } 
    if (aux!=NULL && aux->elemento == buscar){
        endereco = aux;
        return endereco;
    }
    return NULL;
}

Node* remover(Node **lista, int numRemove){
    Node *aux, *remover=NULL;

    if(*lista!=NULL){
        if((*lista)->elemento == numRemove){
            remover = *lista;
            *lista = remover->prox;
        } else {
            aux = *lista;
            while(aux->prox->elemento!=numRemove && aux->prox!=NULL){
                aux = aux->prox;
            } 
            if(aux->prox!=NULL){
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }
    }
    return remover;
}

int pedirElemento(){
    int novoElemento;
    printf("\nDigite um número inteiro para inserir na lista: ");
        scanf("%d",&novoElemento);
    return novoElemento;
}

void imprimirLista(Node **lista){
    Node *aux = *lista;
    printf("\nLista atual: ");
    printf("\n[");
    while(aux!=NULL){
        printf(" %d ",aux->elemento);
        aux = aux->prox;
    }
    printf("]\n");
}

int menu(){
    int opc;
    printf("\n----------------MENU----------------");
    printf("\n| [0] - Encerrar programa          |");
    printf("\n| [1] - Inserir no início da lista |");
    printf("\n| [2] - Inserir no meio da lista   |");
    printf("\n| [3] - Inserir no final da lista  |");
    printf("\n| [4] - Ver a lista                |");
    printf("\n| [5] - Buscar elemento            |");
    printf("\n| [6] - Remover elemento           |");
    printf("\n------------------------------------");
    printf("\nDigite sua opção: ");
        scanf("%d",&opc);
    return opc;
}

int main(){
    Node *lista = NULL, *busca;
    int opc = -1, elemento = 0;
    
    while(opc!=0){
        opc = menu();

        switch (opc) {
        case 0:
            printf("\nEncerrando programa");
            printf("\n");
            break;
        case 1:
            elemento = pedirElemento();
            inserirInicio(&lista, elemento);
            break;
        case 2:
            elemento = pedirElemento();
            imprimirLista(&lista);
            int ant;
            printf("\nDeseja inserir depois de qual elemento?");
                scanf("%d",&ant);
            inserirMeio(&lista, elemento, ant);
            break;
        case 3:
            elemento = pedirElemento();
            inserirFinal(&lista, elemento);
            break;
        case 4:
            imprimirLista(&lista);
            break;
        case 5:
            if(lista == NULL){
                printf("\nNão é possível realizar buscas em uma lista vazia!");
            } else {
            printf("\nDigite o valor para busca:");
                scanf("%d",&elemento);
            busca = buscarElemento(&lista, elemento);
            if(busca){
                printf("\nO elemento %d exite na lista!",elemento);
            } else {
                printf("\nO elemento %d não existe na lista!",elemento);
            }
        }
            break;
        case 6:
            printf("\nDigite o valor para busca:");
                scanf("%d",&elemento);
            remover(&lista, elemento);
            break;
        default:
            printf("\nOpção inválida!");
            break;
        }
    }
}
