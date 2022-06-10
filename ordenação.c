/***************************************

 * Instruções:
 *
 * -b : bubble sort
 * -m : merge sort
 * -q : quick sort
 *
 * Após o algoritmo selecionado deve ser colocado um inteiro que será o tamanho do vetor de números aleatórios gerado pelo código.
 *
 * Ex: ./nomeDoPrograma -b 10 -> utiliza o bubble sort para ordenar um vetor de 10 posições
 *
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(int *vetor, int inicio, int meio, int fim)
{
    int i = inicio, j = meio, pos = 0;
    int *temp = (int *)malloc((fim - inicio) * sizeof(int));
    while ((i < meio) && (j < fim))
    {
        if (vetor[i] <= vetor[j])
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

void mergeSort(int *vetor, int inicio, int fim)
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

void bubbleSort(int *vetor, int n)
{
    int aux = 0;
    int i = 0;
    int trocou = 1;
    while ((i <= n) && trocou)
    {
        trocou = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                // trocando de posição
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocou = 1;
            }
        }
        i++;
    }
}

int particiona(int *vetor, int inicio, int fim)
{
    srand(time(NULL));
    int pos = (rand() % (fim - inicio)) + inicio; // numero aleatorio entre inicio e fim-1, inclusive

    int pivot = vetor[pos];
    vetor[pos] = vetor[inicio];
    vetor[inicio] = pivot;
    int i = inicio + 1;
    int j = fim - 1;
    while (i < j)
    {
        while ((i < fim) && (vetor[i] <= pivot))
        {
            i++;
        }
        while ((j > inicio) && (vetor[j] >= pivot))
        {
            j--;
        }
        if (i < j)
        {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    vetor[inicio] = vetor[j];
    vetor[j] = pivot;
    return j;
}

void quickSort(int *vetor, int inicio, int fim)
{
    if (fim - inicio > 1)
    {
        int posPivot = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, posPivot);
        quickSort(vetor, posPivot + 1, fim);
    }
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[2]);
    int *vetor = malloc(n * sizeof(int));
    // preenchendo o vetor com valores aleatorios
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        vetor[i] = rand() % 1000001; // preenchendo com numeros inteiros entre 0 e 1000000
    }

    // bubble sort
    if (!strcmp(argv[1], "-b"))
    {
        bubbleSort(vetor, n);
    }

    // mergesort
    if (!strcmp(argv[1], "-m"))
    {
        mergeSort(vetor, 0, n);
    }

    if (!strcmp(argv[1], "-q"))
    {
        quickSort(vetor, 0, n);
    }

    // imprimindo o vetor ja ordenado
    for (int i = 0; i < n; i++)
    {
        printf("\nvetor[%02d] = %d", i, vetor[i]);
    }
    printf("\n");
    return 0;
}