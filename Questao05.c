/*
Questao 5:
*/

#include<stdio.h>
#include<stdlib.h>

int **construiMatriz(int _numeroDeLinhas, int _numeroDeColunas, int _preenchimento){
    int **_matriz = malloc(_numeroDeLinhas * sizeof(int*));
    for (int i = 0; i < _numeroDeLinhas; i++)
    {
        _matriz[i] = malloc(_numeroDeColunas * sizeof(int));
    }
    
    if(_preenchimento == 1){
        for (int i = 0; i < _numeroDeLinhas; i++)
        {
            printf("Linha %d. Digite valores para as colunas:\n", i);
            for (int j = 0; j < _numeroDeColunas; j++)
            {
                printf("Coluna %d -> ", j);
                int numeroDigitado;
                scanf("%d", &numeroDigitado);
                _matriz[i][j] = numeroDigitado;
            }
        }
    }

    printf("Matriz criada:\n");
    for (int i = 0; i < _numeroDeLinhas; i++)
    {
        for (int j = 0; j < _numeroDeColunas; j++)
        {
            printf("%d-", _matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return _matriz;
}

void multiplicarMatrizes(int **_matriz1, int **_matriz2, int _matriz1NumeroDeLinhas, int _matriz1NumeroDeColunas, int _matriz2NumeroDeLinhas, int _matriz2NumeroDeColunas){
    int **matrizResultante = construiMatriz(_matriz1NumeroDeLinhas, _matriz2NumeroDeColunas, 0);
    
    for (int l = 0; l < _matriz1NumeroDeLinhas; l++){
        for (int j = 0; j < _matriz2NumeroDeColunas; j++){
            int termo = 0;
            for (int i = 0; i < _matriz1NumeroDeColunas; i++){
                termo += _matriz1[l][i] * _matriz2[i][j];
            }
            matrizResultante[l][j] = termo;
        }
    }

    printf("Matriz resultante de multiplicacao:\n");
    for (int i = 0; i < _matriz1NumeroDeLinhas; i++)
    {
        for (int j = 0; j < _matriz2NumeroDeColunas; j++)
        {
            printf("%d-", matrizResultante[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int mt1_numLinhas, mt1_numColunas;
    int mt2_numLinhas, mt2_numColunas;
    printf("Criar matriz 1:\nDigite o numero de linhas: ");
    scanf("%d", &mt1_numLinhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &mt1_numColunas);

    printf("Criar matriz 2:\nDigite o numero de linhas: ");
    scanf("%d", &mt2_numLinhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &mt2_numColunas);

    if(mt1_numColunas == mt2_numLinhas){
        printf("Criar matriz 1:\n");
        int **matriz1 = construiMatriz(mt1_numLinhas, mt1_numColunas, 1);
        printf("Criar matriz 2:\n");
        int **matriz2 = construiMatriz(mt2_numLinhas, mt2_numColunas, 1);
        multiplicarMatrizes(matriz1, matriz2, mt1_numLinhas, mt1_numColunas, mt2_numLinhas, mt2_numColunas);
    }
    else{
        printf("ERRO! Numero de colunas da primeira matriz e diferente do numero de linhas da segunda matriz.\n");
    }

    return 0;
}