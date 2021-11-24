# include <stdio.h>
# include <stdlib.h>
# include "GrafoMP.c"
# include "Matriz.c"
# include "Pilha.c"

void Fronteira(TGrafo * g, Stack * front, int Ee)
{
    while(g->E != Ee)
    {
        g = g->prox;
    }
    TVizinho *v = g->prim_viz;
    while(v != NULL)
    {
        push(front, v->Ev);
        v = v->prox;
    }
    return;
}

void A_Estrela(TGrafo * g, int matriz[14][14],Stack * visitados,Stack * front,Stack * cam,int Ee,int Es, int tg,int dr)
{
    //printf("Ee = %d\n",Ee);
    //imprimir_pilha(cam);
    if (Ee == Es)
    {
        push(cam,Ee);
        Stack  p;
        p.tam = 0;
	    p.inicio = NULL;

        Nop * aux = cam->inicio;
        while(aux != NULL)
        {
            push(&p,aux->E);
            aux= aux->proximo;
        }
        imprimir_pilha(&p);
        return;
    }
    push(cam,Ee);
    Fronteira(g,front,Ee);
    float fmenor;
    int Ep;
    int dra = dr;
    int tga = tg;
    int h = (front->tam);
    int y;
    for(int i=0;i<h;i++)
    {
        int Ea = peek(front);
        int drt = dr + matriz[Ee-1][Ea-1];
        float f = (drt/30.00) + (matriz[Ea-1][Es-1]/30.00) + tg;
        //printf("f(%d) =%f\n",Ea,f);
        if (i == 0)
        {
            fmenor = f;
            Ep = Ea;
            y = drt;
        }
        else
        {
            int k = Busca_pilha(visitados,Ea); 
            if(f<=fmenor && k==0)
            {
                fmenor = f;
                Ep =Ea;
                y = drt;
            }
            
        }
        pop(front);
    }
    push(visitados,Ee);
    A_Estrela(g,matriz,visitados,front,cam,Ep,Es,tg+4,y);
    return;
}

int main(){
    
    TGrafo * g = geraGrafo();
    //imprime(g);
    int m[14][14] = {0,11,20,27,40,43,39,28,18,10,18,30,30,32,11,0,9,16,29,32,28,19,11,4,17,23,21,24,20,9,0,7,20,22,19,15,10,11,21,21,13,18,27,16,7,0,13,16,12,13,13,18,26,21,11,17,40,29,20,13,0,3,2,21,25,31,38,27,16,20,43,32,22,16,3,0,4,23,28,33,41,30,17,20,39,28,19,12,2,4,0,22,25,29,38,28,13,17,28,19,15,13,21,23,22,0,9,22,18,7,25,30,18,11,10,13,25,28,25,9,0,13,12,12,23,28,10,4,11,18,31,33,29,22,13,0,20,27,20,23,18,17,21,26,38,41,38,18,12,20,0,15,35,39,30,23,21,21,27,30,28,7,12,27,15,0,31,37,30,21,13,11,16,17,13,25,23,20,35,31,0,5,32,24,18,17,20,20,17,30,28,23,39,37,5,0};
    //imprimirM(m);
    Stack visitados;
    visitados.tam = 0;
	visitados.inicio = NULL;

    Stack front;
    front.tam = 0;
	front.inicio = NULL;

    Stack cam;
    cam.tam = 0;
	cam.inicio = NULL;

    int Ee, Es;
    printf("\nDigite o numero da estacao inicial e da final respectivamente\n");
    scanf("%d%d",&Ee,&Es);
    printf("Estacao de entrada :%d\nEstacao de saida: %d\n",Ee,Es);
    A_Estrela(g,m,&visitados,&front,&cam,Ee,Es,0,0); 
    return 0;
}
