#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define CRESCENTE 0
#define DECRESCENTE 1

void mergeSort(int _vetor[], int _tamanho, int _ordem){
    if(_tamanho > 1){
        int tamanhoVetor1 = floor(_tamanho / 2);
        int tamanhoVetor2 = _tamanho - tamanhoVetor1;
        int *vetor1 = malloc(tamanhoVetor1 * sizeof(int));
        int *vetor2 = malloc(tamanhoVetor2 * sizeof(int));
        int i, j, k;
        
        for(i = 0; i < tamanhoVetor1; i++){
            vetor1[i] = _vetor[i];
        }
        for(i = tamanhoVetor1, j = 0; i < _tamanho; i++, j++){
            vetor2[j] = _vetor[i];
        }
        mergeSort(vetor1, tamanhoVetor1, _ordem);
        mergeSort(vetor2, tamanhoVetor2, _ordem);
        for(i = 0, j = 0, k = 0; k < _tamanho; k++){
            if(_ordem == CRESCENTE){
                if(vetor1[i] < vetor2[j]){
                    _vetor[k] = vetor1[i];
                    i++;
                }
                else{
                    _vetor[k] = vetor2[j];
                    j++;
                }
            }
            if(_ordem == DECRESCENTE){
                if(vetor1[i] > vetor2[j]){
                    _vetor[k] = vetor1[i];
                    i++;
                }
                else{
                    _vetor[k] = vetor2[j];
                    j++;
                }
            }
            if(i == tamanhoVetor1){
                for(; k < _tamanho;){
                    k++;
                    _vetor[k] = vetor2[j];
                    j++;
                }
            }
            if(j == tamanhoVetor2){
                for(; k < _tamanho;){
                    k++;
                    _vetor[k] = vetor1[i];
                    i++;
                }
            }
        }
    }
}

int main()
{
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
    mergeSort(vetor, 7, CRESCENTE);
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