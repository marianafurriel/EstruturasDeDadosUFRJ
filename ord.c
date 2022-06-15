#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

int main(int argc, char const *argv[])
{
    int vertices, arestas, aux = 0, pos = 0;
    char c;
    int soma = 0;
    int auxNum[TAM];
    char linha[TAM];
    int ordem[TAM];
    int ord = 0;
    scanf("%d", &vertices);
    scanf("%d", &arestas);
    c = getchar();
    int adj[vertices][vertices]; // = malloc(sizeof(int) * vertices * vertices);
    int graus[vertices];
    int add[vertices];
    for (int i = 0; i < vertices; i++) // preenchendo a matriz de adjacencias toda com 0
    {
        for (int j = 0; j < vertices; j++)
        {
            adj[i][j] = 0;
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
            adj[i][atoi(auxNum) - 1] = 1;
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        graus[i] = 0;
        add[i] = 0;
    }

    for (int i = 0; i < vertices; i++)
    {

        for (int j = 0; j < vertices; j++)
        {
            graus[i] = graus[i] + adj[j][i];
        }
    }

    while (aux < vertices)
    {

        for (int i = 0; i < vertices; i++)
        {

            if ((graus[i] == 0) && (add[i] == 0))
            {
                ordem[ord] = i + 1;
                ord++;
                add[i] = 1;
            }
            for (int j = 0; j < vertices; j++)
            {
                if (adj[j][i] == 1)
                {
                    graus[i]--;
                }
            }
        }
        aux++;
    }
    printf("%d\n", ordem[0]);
    printf("%d\n", ordem[1]);
    printf("%d\n", ordem[2]);
    printf("%d\n", ordem[4]);
    // for (int i = 0; i < strlen(ordem); i++)
    // {
    //     printf("%d ", ordem[i]);
    // }
    printf("\n");
    /////////////////////////////////////////////////////////////////////////
    // for (int i = 0; i < vertices; i++)
    // {                                      // colunas
    //     for (int j = 0; j < vertices; j++) // linhas
    //     {
    //         if (adj[j][i] == 1)
    //         {
    //             soma++;
    //         }
    //     }
    //     if (soma == 0)
    //     {
    //         ordem[ord] = i;
    //         for (int j = 0; j < vertices; j++)
    //         {

    //         }

    //     }
    // }
    /////////////////////////////////////
    // for (int i = 0; i < vertices; i++)
    // {
    //     for (int j = 0; j < vertices; j++)
    //     {
    //         printf("\t%d", adj[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}