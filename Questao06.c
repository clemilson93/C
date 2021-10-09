/*
Questao 6:
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Produto
{
    char nome[20];
    int codigo;
    double preco;
}Produto;


int main(){
    Produto estoque[10] = 
    {
        "pe de muleque", 13205, 0.20,
        "cocada baiana", 15202, 0.50
    };

    Produto *pnt_estoque = &estoque;
    printf("*---------------*\n");
    printf("|---estoque-----|\n");
    printf("*---------------*\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Posicao %d no estoque:\n%d - %s custando %.2f a unidade.\n", i, (pnt_estoque+i)->codigo, (pnt_estoque+i)->nome, (pnt_estoque+i)->preco);
    }

    *(pnt_estoque + 4) = *pnt_estoque;
    pnt_estoque += 4;
    strcpy(pnt_estoque->nome, "risole");
    pnt_estoque->codigo = 13609;
    pnt_estoque->preco = 2.90;
    pnt_estoque -= 3;

    *(pnt_estoque + 4) = *pnt_estoque;
    pnt_estoque += 4;
    strcpy(pnt_estoque->nome, "bolo");
    pnt_estoque->codigo = 13611;
    pnt_estoque->preco = 10.30;
    pnt_estoque -= 5;

    printf("*---------------*\n");
    printf("|---estoque-----|\n");
    printf("*---------------*\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Posicao %d no estoque:\n%d - %s custando %.2f a unidade.\n", i, (pnt_estoque+i)->codigo, (pnt_estoque+i)->nome, (pnt_estoque+i)->preco);
    }
    return 0;
}