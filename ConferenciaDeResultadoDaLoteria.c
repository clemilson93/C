#include<stdio.h>
#include<stdlib.h>

typedef struct Cartela
{
    char apostador[20];
    int numerosApostados[50];
}Cartela;

int CalcularAcertos(int numerosApostados[], int numerosSorteados[])
{
    int acertos = 0;
    for (int numAp = 0, numSo = 0; numSo < 20; numAp++)
    {
        if(numAp >= 50)
        {
            numSo++;
            numAp = 0;
        }
        else if(numerosSorteados[numSo] == numerosApostados[numAp])
        {
            acertos++;
            numSo++;
            numAp = 0;
        }
    };
    

    return acertos;
}

int main()
{
    int numerosSorteados[20];
    printf("Digite os numeros sorteados: \n");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &numerosSorteados[i]);
    };

    Cartela cartelas[4] = 
    {
        {"Clemilson 01", {1,2,5,11,13,16,18,19,22,24,25,28,29,30,32,33,35,40,41,44,45,46,47,49,50,52,54,55,58,59,64,65,66,67,70,72,73,75,78,80,83,85,86,87,88,92,93,95,97,98}},
        {"Clemilson 02", {2,3,5,6,8,13,14,15,16,19,21,24,25,27,29,32,33,34,36,39,41,42,44,46,48,52,54,55,56,60,62,64,66,67,69,72,73,74,76,80,81,82,85,87,88,91,92,95,96,98}},
        {"Pai", {1,3,6,8,10,11,13,15,18,20,22,24,25,26,29,32,33,37,39,40,41,43,46,47,50,51,52,53,57,58,63,64,65,66,69,71,72,73,78,79,81,83,85,87,90,91,92,95,96,99}},
        {"Clovis", {2,4,8,13,16,17,19,20,21,22,28,29,33,34,35,37,40,42,44,45,46,48,51,52,55,58,60,64,66,67,68,69,71,72,73,75,76,79,80,82,84,87,89,90,91,93,95,96,99}}
    };

    FILE * fpointer = fopen("CRLRelatorio.txt", "w");
    fprintf(fpointer, "-----::Apostadores::-----\n");
    for(int i = 0; i < 4; i++)
    {
        fprintf(fpointer, "* %s, acertou %d numeros\n", cartelas[i].apostador, CalcularAcertos(cartelas[i].numerosApostados, numerosSorteados));
    }
    fclose(fpointer);

    return 0;
}