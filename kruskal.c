#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 100

typedef struct aresta
{
    int a, b, peso;
} Aresta;

void merge(Aresta *vetor, int inicio, int meio, int fim)
{
    //printf("entrou no merge\n");
    int i = inicio, j = meio, pos = 0;
    Aresta *temp = (Aresta *)malloc((fim - inicio) * sizeof(Aresta));
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
    //printf("entrou no mergesort\n");
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
    //printf("find\n");
    for (int i = 0; i < 4; i++)
    {
        //printf("%d\n", conj[i]);
    }
    return conj[x];
}
int uniao(int a, int b, int *rank, int *conj)
{
    //printf("entrou no union\n");
    a = find(conj, a);
    b = find(conj, b);

    if (a != b)
    {//printf("union:a!=b\n");
        if (rank[a] < rank[b])
        {//printf("union:rank a<rank b\n");
            conj[a] = b;
        }
        else
        {
            conj[b] = a;
            if (rank[a] == rank[b])
            {
                rank[a]++;
            }
        }
        return 1; // fez a uniao
    }
    return 0; // ja estao no mesmo conjunto
}

int main(int argc, char const *argv[])
{
    char linha[TAM];
    int verticesqtd, arestasqtd, aux, somaPesos = 0;
    scanf("%d", &verticesqtd);
    scanf("%d", &arestasqtd);
    int *conj = (int *)malloc(sizeof(int) * verticesqtd);
    int *rank = (int *)malloc(sizeof(int) * verticesqtd);
    Aresta *arestas = (Aresta *)malloc(sizeof(Aresta) * arestasqtd);
    for (int i = 0; i < arestasqtd; i++)
    {
        if (verticesqtd <= i)
        {
            conj[i] = i;
            rank[i] = 0;
        }
        scanf("%d%d%d", &(arestas[i].a), &(arestas[i].b), &(arestas[i].peso));
    }
    for (int i = 0; i < 6; i++)
    {
        //printf("aresta %d:\na:%d\nb:%d\npeso:%d\n", i, arestas[i].a, arestas[i].b, arestas[i].peso);
    }
    //printf("leu tudo\n");
    mergeSort(arestas, 0, arestasqtd); // ordenando as arestas
    //printf("fez o mergesort\n");

    for (int i = 0; i < arestasqtd; i++)
    {
        // //printf("%d\n", arestas[i].peso);
        aux = uniao(arestas[i].a, arestas[i].b, rank, conj);
        //printf("aux: %d\n", aux);
        if (aux)
        {
            //printf("entrou na soma de pesos\n");
            somaPesos += arestas[i].peso;
        }
    }
    printf("%d\n", somaPesos);
    return 0;
}