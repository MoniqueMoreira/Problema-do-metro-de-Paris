# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct vizinho 
{
    int Ev;
    struct vizinho * prox;
}TVizinho;

typedef struct grafo
{
    int E;
    TVizinho * prim_viz;
    struct grafo * prox;
}TGrafo;

TGrafo * inicializa (){
    return NULL;
}

void imprime(TGrafo *g)
{
    printf("----------------------------GRAFO----------------------------\n");
    while(g != NULL)
    {
        printf("Vertice (%d)\n", g->E);
        printf("Vizinhos: ");
        TVizinho *v = g->prim_viz;
        while(v != NULL)
        {
            printf("(%d) ", v->Ev);
            v = v->prox;
        }
    printf("\n\n");
    g = g->prox;
    }
}

TGrafo * busca_vertice(TGrafo * g, int e)
{
    while ((g != NULL) && (g->E != e ))
    {
        g = g->prox;
    }
    return g;
}


TGrafo *insere_vertice(TGrafo *g, int e)
{
    TGrafo * p = busca_vertice(g, e);
    if(p == NULL)
    {
        p = (TGrafo*) malloc(sizeof(TGrafo));
        p->E = e;
        p->prox = g;
        p->prim_viz = NULL;
        g=p;
    }
    return g;
}

TVizinho* busca_aresta(TGrafo *g, int v1,int v2)
{
    TGrafo *pv1 = busca_vertice(g,v1);
    TGrafo *pv2 = busca_vertice(g,v2);
    TVizinho *resp = NULL;
    //checa se ambos os vértices existem
    if((pv1 != NULL) && (pv2 != NULL)) 
    {
        //percorre a lista de vizinhos de v1 procurando por v2
        resp = pv1->prim_viz;
        while ((resp != NULL) && (resp->Ev != v2)) 
        {
            resp = resp->prox;
        }
    }
    return resp;
}

void insere_um_sentido(TGrafo *g, int v1,int v2)
{
    TGrafo *p = busca_vertice(g, v1);
    TVizinho *nova = (TVizinho *) malloc(sizeof(TVizinho));
    nova->Ev = v2;
    nova->prox = p->prim_viz;
    p->prim_viz = nova;
}

void insere_aresta(TGrafo *g, int v1, int v2)
{

    TVizinho *v = busca_aresta(g, v1, v2);
    if(v == NULL)
    {
            insere_um_sentido(g,v1, v2);
            insere_um_sentido(g,v2, v1); 
    }
}

TGrafo * geraGrafo()
{
    TGrafo * g = inicializa();
    g = insere_vertice(g,1);
    g = insere_vertice(g,2);
    g = insere_vertice(g,3);
    g = insere_vertice(g,4);
    g = insere_vertice(g,5);
    g = insere_vertice(g,6);
    g = insere_vertice(g,7);
    g = insere_vertice(g,8);
    g = insere_vertice(g,9);
    g = insere_vertice(g,10);
    g = insere_vertice(g,11);
    g = insere_vertice(g,12);
    g = insere_vertice(g,13);
    g = insere_vertice(g,14);
    insere_aresta(g,1,2);

    insere_aresta(g,2,10);
    insere_aresta(g,2,9);
    insere_aresta(g,2,3);

    insere_aresta(g,3,9);
    insere_aresta(g,3,4);
    insere_aresta(g,3,13);

    insere_aresta(g,4,8);
    insere_aresta(g,4,5);
    insere_aresta(g,4,13);

    insere_aresta(g,5,6);
    insere_aresta(g,5,7);
    insere_aresta(g,5,8);

    insere_aresta(g,8,12);

    insere_aresta(g,9,11);
    insere_aresta(g,9,8);
    
    insere_aresta(g,13,14);

    return g;

}
/*
int main()
{
    TGrafo * g;
    g= geraGrafo();
    return 0;
}
*/