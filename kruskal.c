#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

typedef struct aresta
{
    int a, b, peso;
} Aresta;

void merge(Aresta *vetor, int inicio, int meio, int fim)
{
    int i = inicio, j = meio, pos = 0;
    Aresta *temp = (Aresta *)malloc((fim - inicio) * sizeof(int));
    while ((i < meio) && (j < fim))
    {
        if (vetor[i].peso <= vetor[j].peso)
        {
            temp[pos] = vetor[i];
            i++;
        }
        else
        {
            temp[pos] = vetor[j];
            j++;
        }
        pos++;
    }
    while (i < meio)
    {
        temp[pos] = vetor[i];
        i++;
        pos++;
    }
    while (j < fim)
    {
        temp[pos] = vetor[j];
        j++;
        pos++;
    }
    for (i = 0; i < pos; i++)
    {
        vetor[inicio + i] = temp[i];
    }
}

void mergeSort(Aresta *vetor, int inicio, int fim)
{
    if (inicio >= fim - 1)
    {
        return;
    }
    int meio = (inicio + fim) / 2;
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio, fim);
    merge(vetor, inicio, meio, fim);
}

int find(int *conj, int x)
{
    if (x != conj[x])
    {
        conj[x] = find(conj, conj[x]);
    }
    return conj[x];
}
void uniao(int a, int b, int *rank, int *conj)
{
    a = find(conj, a);
    b = find(conj, b);
    if (a != b)
    {
        if (rank[a] < rank[b])
        {
            conj[a];
        }
        else
        {
            conj[b] = a;
            if (rank[a] == rank[b])
            {
                rank[a]++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int verticesqtd, arestasqtd;
    scanf("%d", &verticesqtd);
    scanf("%d", &arestasqtd);
    int conj[] = malloc(sizeof(int) * verticesqtd);
    int rank[] = malloc(sizeof(int) * verticesqtd);
    Aresta arestas[] = (Aresta *)malloc(sizeof(Aresta) * arestasqtd);
    for (int i = 0; i < verticesqtd; i++)
    {
        conj[i] = i;
        rank[i] = 0;
        scanf("%d", &(arestas[i].a));
        scanf("%d", &(arestas[i].b));
        scanf("%d", &(arestas[i].peso));
    }
    mergeSort(arestas, 0, arestasqtd - 1); // ordenando as arestas

    return 0;
}