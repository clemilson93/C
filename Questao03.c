/*
Questao 3:
*/

#include<stdio.h>;
#include<stdlib.h>;

void trocarValores(char *_a, char *_b){
    *_a = *_b;
    printf("pass");
}

int main(){
    char a[] = "abc1025";
    char b[] = "mnb3625";
    char *pt_a = &a;
    char *pt_b = &b;
    printf("Valor inicial de a = %s e b = %s\n", a, b);
    printf("Valor inicial de *p_a = %s e *p_b = %s\n", pt_a, pt_b);
    trocarValores(pt_a, pt_b);
    printf("Valor final de a = %s e b = %s\n", a, b);
    printf("Valor final de *p_a = %s e *p_b = %s\n", pt_a, pt_b);
    return 0;
}