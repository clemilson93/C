#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CRESCENTE 0
#define DECRESCENTE 1

void selectionSort(int _vetor[], int _tamanho, int _ordem){
    int i, j, menor, posicaoDoMenor;
    for(j = 0; j < _tamanho; j++){
        menor = _vetor[j];
        posicaoDoMenor = j;
        for(i = j + 1; i < _tamanho; i++){
            if(_ordem == DECRESCENTE){
                if(menor < _vetor[i]){
                    menor = _vetor[i];
                    posicaoDoMenor = i;
                }
            }
            if(_ordem == CRESCENTE){
                if(menor > _vetor[i]){
                    menor = _vetor[i];
                    posicaoDoMenor = i;
                }
            }
        }
        _vetor[posicaoDoMenor] = _vetor[j];
        _vetor[j] = menor;
    }
}

int main(){
    int vetor[] = {25, 52, 2, 19, -5, 36, -15};
    int i;
    float tempoDeExecucao;
    time_t tempoInicial, tempoFinal;
    printf("Vetor nao ordenado:\n");
    for(i = 0; i < 7; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
    tempoInicial = time(NULL);
    selectionSort(vetor, 7, CRESCENTE);
    tempoFinal = time(NULL);
    printf("Vetor ordenado:\n");
    for(i = 0; i < 7; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
    free(vetor);
    tempoDeExecucao = difftime(tempoFinal, tempoInicial);
    printf("Tempo de execucao: %f\n", tempoDeExecucao);
    return 0;
}