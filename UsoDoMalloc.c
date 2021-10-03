#include<stdio.h>
#include<stdlib.h>

void  preencherVetor(int *_pntVetor, int _n){
    for (int i = 0; i < _n; i++)
    {
        _pntVetor[i] = i;
    }
}

void  imprimirVetor(int *_pntVetor, int _n){
    for (int i = 0; i < _n; i++)
    {
        printf("%i\n", _pntVetor[i]);
    }
}

int main(){
    int n = 0;
    printf("Digite um numero: ");
    scanf("%i", &n);
    int *pntVetor = malloc(n * sizeof(int));
    preencherVetor(pntVetor, n);
    imprimirVetor(pntVetor, n);
    return 0;
}