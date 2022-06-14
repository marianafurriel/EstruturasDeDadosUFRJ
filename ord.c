#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 100

typedef struct _tno
{
    struct _tno *adjacencias[TAM];
    int grau;
}tno;

int main(int argc, char const *argv[])
{
    char vertices[TAM];
    char arestas[TAM];
    char linha[TAM];
    char numero[TAM];
    int vert = 0;
    int ares = 0;
    scanf("%s", vertices);
    scanf("%s", arestas);
    vert = atoi(vertices);
    ares = atoi(arestas);
    int adjacencias[vert][vert];
    int *nos = malloc(sizeof(tno) * vert);
    for (int i = 0; i < vert; i++)
    {
        for(int j =0;j<vert;j++){
            
        }
        scanf("%s",numero);
        while(numero!='\n'){

        }
    }
    return 0;
}
