#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

int main(int argc, char const *argv[])
{
    int vertices, arestas, aux, pos = 0;
    char c;
    int auxNum[TAM];
    char linha[TAM];
    int ordem[TAM];
    scanf("%d", &vertices);
    scanf("%d", &arestas);
    c = getchar();
    int *adj = malloc(sizeof(int) * vertices * vertices);

    for (int i = 0; i < vertices; i++) // preenchendo a matriz de adjacencias toda com 0
    {
        for (int j = 0; j < vertices; j++)
        {
            adj[(i * vertices) + j] = 0;
        }
    }

    for (int i = 0; i < vertices; i++) // preenchendo a tabela de adjacencias
    {
        printf("adjacencias do nó %d\n", i + 1);
        fgets(linha, TAM, stdin);
        for (int j = 0; j < strlen(linha); j++)
        {
            while (isdigit(linha[j]))
            {
                auxNum[pos] = linha[j];
                j++;
                pos++;
            }
            auxNum[pos] = '\0';
            pos = 0;
            adj[(i * vertices) + atoi(auxNum) - 1] = 1;
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("\t%d", adj[(i * vertices) + j]);
        }
        printf("\n");
    }

    return 0;
}