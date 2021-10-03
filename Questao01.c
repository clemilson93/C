/*
Questao 1: 
item a: p++ passa para a proxima posicao de memoria de acordo com seu dado.
        (*p)++ incrementa a variavel que esta apontando
        *(p++) representa o valor contido no endereco encrementado
item b: representa o valor contido na posicao 11 da memoria
item c: podemos comparar a igualdade dos valores referenciados e a posicao relativa dos enderecos.
*/

#include<stdio.h>;
#include<stdlib.h>;

int main(){
    int numero = 20;
    int *p = &numero;
    printf("numero = %d\n", numero);
    printf("p = %d\n", p);
    printf("*p = %d\n\n", *p);

    /*for (int i = 0; i < 3; i++)//p++
    {
        printf("p++ = %d\n", p++);
    }*/

    /*for (int i = 0; i < 3; i++)//(*p)++
    {
        printf("(*p)++ = %d\n", (*p)++);
    }*/

    /*for (int i = 0; i < 3; i++)//*(p++)
    {
        printf("*(p++) = %d\n", *(p++));
    }*/

    /*for (int i = 0; i < 3; i++)//*(p + 10)
    {
        printf("*(p + 10) = %d\n", *(p+4));
    }*/

    printf("numero = %d\n", numero);
    
    return 0;
}