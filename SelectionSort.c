#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CRESCENTE 0
#define DECRESCENTE 1

void selectionSort(int _vetor[], int _tamanho, int _ordem){
    int i, j, elementoMenor, posicaoDoElementoMenor;
    for(j = 0; j < _tamanho; j++){
        elementoMenor = _vetor[j];
        posicaoDoElementoMenor = j;
        for(i = j + 1; i < _tamanho; i++){
            if(_ordem == DECRESCENTE){
                if(elementoMenor < _vetor[i]){
                    elementoMenor = _vetor[i];
                    posicaoDoElementoMenor = i;
                }
            }
            if(_ordem == CRESCENTE){
                if(elementoMenor > _vetor[i]){
                    elementoMenor = _vetor[i];
                    posicaoDoElementoMenor = i;
                }
            }
        }
        if(elementoMenor != _vetor[j]){
            _vetor[posicaoDoElementoMenor] = _vetor[j];
            _vetor[j] = elementoMenor;
        }
    }
}

int main(){
    int vetor[] = {25, 52, -15, 36, -5, 36, -15};
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