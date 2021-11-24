#include <stdio.h>
#include <stdlib.h>

typedef struct Nop {
    int E;
    struct Nop *proximo;
} Nop;

typedef struct {
    Nop *inicio;
    int tam;
} Stack;

Stack * inicializa_pilha()
{
    Stack p;
    p.tam = 0;
	p.inicio = NULL;
    Stack * k = &p;
    return k;
}

void imprimir_pilha(Stack *p) 
{
    Nop *inicio = p->inicio;

    printf("Tamanho da lista: %d\n", p->tam);

    while(inicio != NULL) 
    {
        printf("(%d) ",inicio->E);
        inicio = inicio->proximo;
        if (inicio != NULL)
        {
            printf("-> ");
        }
        
    }
    printf("\n");
}

void push(Stack *p,  int e) // colocar na pilha
{
    Nop *novo = (Nop*)malloc(sizeof(Nop));
    novo->E = e;

    if(p->inicio == NULL) 
    {
        novo->proximo = NULL;
        p->inicio = novo;
    } 
    else 
    {
        novo->proximo = p->inicio;
        p->inicio = novo;
    }
    p->tam++;
}

void pop(Stack *p) // retirar da pilha
{
    //imprimir_pilha(p);
    Nop * noARemover = p->inicio;
    if(p->inicio == NULL)
    {
    	printf("PILHA UNDERFLOW, NÃO E POSSIVEL retirar \n");
    }
    else
    {
    	p->inicio = p->inicio->proximo;
    	free(noARemover);
        p->tam--;

    }
}

int peek(Stack * p)
{
	Nop * inicio = p->inicio;
	if(p->tam == 0)
    {
    	printf("PILHA UNDERFLOW, NÃO E POSSIVEL retirar \n");
    }
    else
    {
    	return inicio->E;
    }
}

int Busca_pilha(Stack * p, int e) // Buscando na pilha
{
    Nop *inicio = p->inicio;

    while(inicio != NULL) 
    {
        if(inicio->E == e)
        {
            return 1;
        }
        inicio = inicio->proximo;
    }
    return 0;
}

/*int main()
{
	Stack p;
	p.tam = 0;
	p.inicio = NULL;
	imprimir(&p);
	pop(&p);
	imprimir(&p);
	return 0;
}
*/