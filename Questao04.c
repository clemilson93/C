/*
Questao 4:
*/

#include<stdio.h>
#include<stdlib.h>

void construiSequencia(int _numeroInicial, int _numeroDoTermodesejado){
    int proximoNumero = 0;
    int numeroAnterior = 0;
    int numeroAtual = _numeroInicial;
    printf("%d, ", numeroAtual);
    for(int i = 0; i < _numeroDoTermodesejado - 1; i++){
        proximoNumero = numeroAtual + numeroAnterior;
        numeroAnterior = numeroAtual;
        numeroAtual = proximoNumero;
        printf("%d, ", numeroAtual);
    }
    printf("\nNumero do termo %d e igual a %d", _numeroDoTermodesejado, numeroAtual);
}

int main(){
    int numeroInicial = 0;
    int numeroDoTermodesejado = 0;
    printf("Digite um numero para iniciar a sequencia de Fibonacci: ");
    scanf("%d", &numeroInicial);
    printf("Digite um numero do termo desejado da sequencia: ");
    scanf("%d", &numeroDoTermodesejado);
    construiSequencia(numeroInicial, numeroDoTermodesejado);

    return 0;
}