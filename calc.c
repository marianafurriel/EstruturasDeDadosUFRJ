#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXTAM 1000

typedef struct pilha
{
    char itens[MAXTAM];
    int topo;
} Pilha;

void inicia(Pilha *pilha)
{
    pilha->topo = -1; // pilha tá vazia
}

int vazia(Pilha *pilha)
{
    if (pilha->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cheia(Pilha *pilha)
{
    if (pilha->topo == MAXTAM - 1)
    {
        return 1; // pilha cheia
    }
    else
    {
        return 0;
    }
}

void push(Pilha *pilha, int elemento)
{
    if (cheia(pilha))
    {
        printf("Pilha cheia.\n");
    }
    else
    {
        pilha->topo++;
        pilha->itens[pilha->topo] = elemento;
        printf("adicionou: %d\n", elemento);
    }
}

int pop(Pilha *pilha)
{
    int aux;
    if (vazia(pilha))
    {
        printf("Pilha vazia.\n");
    }
    else
    {
        aux = pilha->itens[pilha->topo];
        pilha->topo--;
        return aux;
    }
}

int precedencia(char op1, char op2) // op1 a ser adicionado e op2 topo da pilha de operadores
{
    if (((op1 == '/') || (op1 == '*')) && ((op2 == '+') || (op2 == '-')))
    {
        return 1; // op a ser adicionado tem precedencia maior
    }
    else if ((((op2 == '/') || (op2 == '*')) && ((op1 == '+') || (op1 == '-'))))
    {
        return 2; // op da pilha tem precedencia maior
    }
    else if (((op1 == '/') || (op1 == '*')) && ((op2 == '/') || (op2 == '*')))
    {
        return 2; // tem precedencia igual mas precisa fazer na ordem que aparece, então o da pilha precisa ser feito primeiro
    }
    else if (((op1 == '+') || (op1 == '-')) && ((op2 == '+') || (op2 == '-')))
    {
        return 2; // tem precendencia igual e não faz diferença quem é feito primeiro, então considera o op a ser adicionado como maior precedencia pra adicionar na pilha e calcular depois
    }
}

int calcula(int num1, int num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '/':
        return num1 / num2;
    case '*':
        return num1 * num2;
    }
}

int main(int argc, char const *argv[])
{
    char expressao[1000];
    scanf("%s", expressao);
    // printf("leu a expressao");
    Pilha *operadores = (Pilha *)malloc(sizeof(Pilha));
    inicia(operadores);
    Pilha *operandos = (Pilha *)malloc(sizeof(Pilha));
    inicia(operandos);
    // printf("iniciou as pilhas");

    // printf("declarou as variaveis");
    int i = 0;

    char auxNum[1000];
    int numero = 0.0;
    int pos = 0;
    int val1 = 0.0;
    int val2 = 0.0;
    int result = 0.0;
    char op;
    int aux = 0;
    while (1)
    {
        if ((expressao[i] == '\0') && (vazia(operadores)))
        {
            break;
        }
        else if ((expressao[i] == '\0') && (operadores->itens[operadores->topo] == '('))
        {
            break;
        }
        else if ((expressao[i] == '\0') && (!vazia(operadores))) // ainda tem operador, mas todos que tem tem precedencia igual
        {
            while (!vazia(operadores))
            {
                val1 = pop(operandos);
                val2 = pop(operandos);
                op = pop(operadores);
                result = calcula(val2, val1, op);
                printf("%d\n", result);
                // printf("oi");
                push(operandos, result);
            }
        }
        else if (!(isdigit(expressao[i])))
        {
            if (((operadores->topo == -1) || (expressao[i] == '(') || operadores->itens[operadores->topo] == '('))
            {
                push(operadores, expressao[i]);
            }
            else if (expressao[i] == ')')
            {
                while (operadores->itens[operadores->topo] != '(')
                {
                    val1 = pop(operandos);
                    val2 = pop(operandos);
                    op = pop(operadores);
                    push(operandos, calcula(val2, val1, op));
                }
                // pop(operadores); // para remover o '('
            }
            else
            {
                while ((precedencia(expressao[i], operadores->itens[operadores->topo]) == 2) && (!vazia(operadores))) // precedencia dos operadores do topo da pilha maior que os operadores a serem adicionados
                {
                    val1 = pop(operandos);
                    val2 = pop(operandos);
                    op = pop(operadores);
                    push(operandos, calcula(val2, val1, op));
                }
                if ((precedencia(expressao[i], operadores->itens[operadores->topo]) == 1) || (vazia(operadores)))
                { // precedencia do que vai ser adicionado na pilha maior ou igual ao que está no topo da pilha
                    push(operadores, expressao[i]);
                }
            }
            i++;
        }
        else
        {
            // printf("antes do while");
            //  aux = isdigit(expressao[i]);
            // printf("aux: %d\n", aux);
            while (isdigit(expressao[i]))
            {
                // printf("dentro do while\n");
                auxNum[pos] = expressao[i];
                i++;
                pos++;
                // aux = isdigit(expressao[i]);
            }
            auxNum[pos] = '\0';
            pos = 0;
            numero = atoi(auxNum);
            printf("numero: %d\n", numero);
            // auxNum[0] = '\0';
            push(operandos, numero);
            // printf("oi");
        }
    }
    printf("%d", pop(operandos));
    return 0;
}