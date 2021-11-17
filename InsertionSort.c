#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CRESCENTE 0
#define DECRESCENTE 1

void insertionSort(int _vetor[], int _tamanho, int _ordem){
    int elementoSelecionado, i, j;
    for(i = 1; i < _tamanho; i++){
        elementoSelecionado = _vetor[i];
        for(j = i; j > 0; j--){
            if(_ordem == CRESCENTE){
                if(_vetor[i] < _vetor[j - 1]){
                    _vetor[i] = _vetor[j - 1];
                    _vetor[j - 1] = elementoSelecionado;
                    i--;
                }
            }
            if(_ordem == DECRESCENTE){
                if(_vetor[i] > _vetor[j - 1]){
                    _vetor[i] = _vetor[j - 1];
                    _vetor[j - 1] = elementoSelecionado;
                    i--;
                }
            }
        }
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
    insertionSort(vetor, 7, DECRESCENTE);
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