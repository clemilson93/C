#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CRESCENTE 0
#define DECRESCENTE 1

void insertionSort(int _vetor[], int _tamanho, int _ordem){
    int elementoSelecionado, i, j;
    for(i = 1; i < _tamanho; i++){
        elementoSelecionado = _vetor[i];
        for(j = i-1; j >= 0; j--){
            if(_ordem == CRESCENTE){
                if(elementoSelecionado < _vetor[j]){
                    _vetor[j+1] = _vetor[j];
                    _vetor[j] = elementoSelecionado;
                }
            }
            if(_ordem == DECRESCENTE){
                if(elementoSelecionado > _vetor[j]){
                    _vetor[j+1] = _vetor[j];
                    _vetor[j] = elementoSelecionado;
                }
            }
        }
    }
}

int main(){
    int vetor[] = {11, 9, 7, 5, 3, 1};
    int i, tamanhoDoVetor = 6;
    float tempoDeExecucao;
    time_t tempoInicial, tempoFinal;
    printf("Vetor nao ordenado:\n");
    for(i = 0; i < tamanhoDoVetor; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
    tempoInicial = time(NULL);
    insertionSort(vetor, tamanhoDoVetor, CRESCENTE);
    tempoFinal = time(NULL);
    printf("Vetor ordenado:\n");
    for(i = 0; i < tamanhoDoVetor; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
    free(vetor);
    tempoDeExecucao = difftime(tempoFinal, tempoInicial);
    printf("Tempo de execucao: %f\n", tempoDeExecucao);
    return 0;
}