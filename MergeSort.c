#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define CRESCENTE 0
#define DECRESCENTE 1

void mostrarVetor(int _vetor[], int _tamanho){
    printf("[\t");
    for (int i = 0; i < _tamanho; i++)
    {
        printf("%d\t", _vetor[i]);
    }
    printf("]\n");
    
}

void dividirVetor(int _vetor[], int _inicio, int _fim, int _tipo){
    int meio;
    if(_inicio < _fim){
        meio = floor((_inicio + _fim) / 2);
        dividirVetor(_vetor, _inicio, meio, _tipo);
        dividirVetor(_vetor, meio + 1, _fim, _tipo);
        printf("%d %d %d\n", _inicio, meio, _fim);
        juntarVetor(_vetor, _inicio, meio, _fim, _tipo);
    }
}

void juntarVetor(int _vetor[], int _inicio, int _meio, int _fim, int _tipo){
    int tamanho = _fim - _inicio +1;
    int *vetorTemp = malloc(tamanho * sizeof(int));
    int posicaoVetor1 = _inicio;
    int posicaoVetor2 = _meio + 1;
    int i, j, k;
    int fimVetor1 = 0;
    int fimVetor2 = 0;
    
    if(vetorTemp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fimVetor1 && !fimVetor2){
                if(_tipo == CRESCENTE){
                    if(_vetor[posicaoVetor1] < _vetor[posicaoVetor2]){
                        vetorTemp[i] = _vetor[posicaoVetor1++];
                    }
                    else{
                        vetorTemp[i] = _vetor[posicaoVetor2++];
                    }
                }
                if(_tipo == DECRESCENTE){
                    if(_vetor[posicaoVetor1] > _vetor[posicaoVetor2]){
                        vetorTemp[i] = _vetor[posicaoVetor1++];
                    }
                    else{
                        vetorTemp[i] = _vetor[posicaoVetor2++];
                    }
                }
                if(posicaoVetor1 > _meio){
                    fimVetor1 = 1;
                    
                }
                if(posicaoVetor2 > _fim){
                    fimVetor2 = 1;
                    
                }
            }
            else{
                if(!fimVetor1){
                    vetorTemp[i] = _vetor[posicaoVetor1++];
                }
                else{
                    vetorTemp[i] = _vetor[posicaoVetor2++];
                }
            }
        }
        for(j = 0, k = _inicio; j < tamanho; j++, k++){
            _vetor[k] = vetorTemp[j];
        }
    }
}

void ordenar(int _vetor[], int _tamanho, int _tipo){
    int inicio = 0;
    int fim = _tamanho - 1;
    dividirVetor(_vetor, inicio, fim, _tipo);
}

int main(){
    int vetor[] = {54, 21, 4, 11, 25, 42, -15};
    mostrarVetor(vetor, 7);
    ordenar(vetor, 7, DECRESCENTE);
    mostrarVetor(vetor, 7);
    return 0;
}