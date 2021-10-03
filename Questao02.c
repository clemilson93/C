/*
Questao 2: 
item a:
*/

#include<stdio.h>;
#include<stdlib.h>;

void zerarVariaveis(int *_a, int *_b){
    *_a = 0;
    *_b = 0;
}

int main(){
    int a = 2;
    int b = 6;
    printf("Valor inicial de a = %d e b = %d\n", a, b);
    int *p_a = &a;
    int *p_b = &b;
    printf("Valor inicial de *p_a = %d e *p_b = %d\n", *p_a, *p_b);
    zerarVariaveis(p_a, p_b);
    printf("Valor final de a = %d e b = %d\n", a, b);
    printf("Valor final de *p_a = %d e *p_b = %d\n", *p_a, *p_b);
    return 0;
}