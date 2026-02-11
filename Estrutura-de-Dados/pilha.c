#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int value;
    struct Node* next;
};

struct Node* create_node(int value){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); //get memory
    node->value = value;
    node->next = NULL;

    return node;
}

struct Stack{
    struct Node* head;

    void (*add) (struct Stack* self, int value);
    void (*rm) (struct Stack* self);
    void (*print) (struct Stack* self);
};

void adicionar(struct Stack* self, int value){
    struct Node* node = create_node(value);
    if (self->head == NULL){
        self->head = node;
    }else{
        node->next = self->head;
        self->head = node;
    }
}

void remover(struct Stack* self){
    if (self->head == NULL){
        printf("Pilha vazia!");
        return;
    }
    struct Node* aux = self->head;
    self->head = aux->next;

    free(aux);

}

void imprimir(struct Stack* self){
    if (self->head == NULL){
        printf("Pilha Vazia!");
        return;
    }

    struct Node* node_now = self->head;
    while(node_now != NULL){
        printf("[%d] -> ", node_now->value);
        node_now = node_now->next;
    }
}

struct Stack* create_stack(){
 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));


    stack->head = NULL;
    stack->add = adicionar;
    stack->rm = remover;
    stack->print = imprimir;
    return stack;
};



int main(){
    
    struct Stack* s = create_stack();
    s->add(s, 10);
    s->print(s);
    s->rm(s);
    s->print(s);
    return 0;
}