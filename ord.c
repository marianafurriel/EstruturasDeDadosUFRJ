#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

int main(int argc, char const *argv[])
{
    int vertices, arestas, aux = 0, pos = 0;
    char c;
    int auxNum[TAM];
    char linha[TAM];
    int ordem[TAM];
    int ord = 0;
    scanf("%d", &vertices);
    scanf("%d", &arestas);
    c = getchar();

    int adj[vertices][vertices];
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

            if ((graus[i] == 0) && (add[i] == 0)) // se o grau for 0 e ainda nao tiver sido adicionada na ordem
            {
                ordem[ord] = i + 1;
                ord++;
                add[i] = 1;
                for (int j = 0; j < vertices; j++) // após adicionar na ordem vai diminuir em 1 o grau daqueles que dependem dele
                {
                    if (adj[i][j] == 1)
                    {
                        graus[j]--;
                    }
                }
            }
        }
        aux++;
    }
    for (int i = 0; i < vertices; i++) // imprime a ordem
    {
        printf("%d ", ordem[i]);
    }
    return 0;
}