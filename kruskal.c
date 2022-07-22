#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

typedef struct aresta
{
    int saida, chegada;
} Aresta;

typedef struct vertice
{
    Vertice *pai;
    int rank = 0;
} Vertice;

Vertice *find(Vertice *no)
{
    int *ant = no->pai;
    while ((no->pai != no))
    {
        if (no->pai == (no->pai)->pai)
        {
            no->pai = (no->pai)->pai;
        }
    }
    return no;
}
void uniao(Vertice *no1, Vertice *no2)
{
    no1 = find(no1);
    no2 = find(no2);
    if (no1->rank > no2->rank)
    {
        no2->pai = no1;
    }
    else if (no1->rank > no2->rank)
    {
        no1->pai = no2;
    }
    else
    {
        no1->pai = no2;
        no1->rank++;
    }
}
int main(int argc, char const *argv[])
{
    int verticesqtd, vertice1, vertice2, arestasqtd, aresta;
    scanf("%d", &verticesqtd);
    scanf("%d", &arestasqtd);
    int vetor v for (int i = 0; i < arestasqtd; i++)
    {
        scanf("%d", &vertice1);
        scanf("%d", &vertice2);
        scanf("%d", &arestas);
    }
    return 0;
}