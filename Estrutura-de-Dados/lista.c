#include <stdio.h>
#include <stdlib.h>

struct No
{
    /* data */
    int *value;
    struct No* proximo;
};

struct No* criar_no(int valor){
    struct No* no = (struct No*) malloc(sizeof(struct No));
    no->value = valor;
    no->proximo = NULL;

    return no;
}


struct Lista
{
    /* data */
    struct No* head;
    struct No* ultimo;
    int indexs;
    void (*add)(struct Lista self, int valor);
    void (*rm) (struct Lista self);
};


void adicionar(struct Lista* self, int valor){
    struct No* no = criar_no(valor);
    if(self->head == NULL){
        self->head = no;
        self->ultimo = self->head;
    }else{
        self->ultimo->proximo = no;
        self->ultimo = self->ultimo->proximo;   
    }
    self->indexs++;
}

void remover(struct Lista* self, int indice){
    if (self->head == NULL){
        printf("Lista vazia!");
        return;
    }
    if (indice > self->indexs){
        printf("Indice maior que a quantidade de elementos na lista!\nImpossível remover!");
        return;
    }
    if (indice == 0){
        self->head = self->head->proximo;
    }else{
        while()
    }
}


struct Lista* criar_lista(){
    struct Lista* l = (struct Lista*) malloc(sizeof(struct Lista));
    l->head = NULL;
    l->ultimo = l->head;
    l->add = adicionar;
    l->indexs = -1;

    return l;
}

void main(){
    struct Lista* l = criar_lista();

}


