#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CRESCENTE 0
#define DECRESCENTE 1

void mostrarVetor(int vetor[], int tamanho){
    printf("Vetor: [\t");
    for(int i = 0; i < tamanho; i++){
        printf("%d\t", vetor[i]);
        }
    printf("]\n");
}

void bubbleSort(int _vetor[], int _tamanho, int _ordem){
    int troca, i, temp;
    do{
        troca = 0;
        for(i = 0; i < (_tamanho - 1); i++){
            if(_ordem == CRESCENTE){
                if(_vetor[i] > _vetor[i + 1]){
                    temp = _vetor[i];
                    _vetor[i] = _vetor[i + 1];
                    _vetor[i + 1] = temp;
                    troca++;
                }
            }
            if(_ordem == DECRESCENTE){
                if(_vetor[i] < _vetor[i + 1]){
                    temp = _vetor[i];
                    _vetor[i] = _vetor[i + 1];
                    _vetor[i + 1] = temp;
                    troca++;
                }
            }
        }
    }while(troca > 0);
}

int main(){
    int vetor[] = {25, 52, 2, 19, -5, 36, -15};
    float tempoDeExecucao;
    time_t tempoInicial, tempoFinal;
    mostrarVetor(vetor, 7);
    tempoInicial = time(NULL);
    bubbleSort(vetor, 7, CRESCENTE);
    tempoFinal = time(NULL);
    mostrarVetor(vetor, 7);
    free(vetor);
    tempoDeExecucao = difftime(tempoFinal, tempoInicial);
    printf("Tempo de execucao: %f\n", tempoDeExecucao);
    return 0;
}