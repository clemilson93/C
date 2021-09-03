#include<stdio.h>
#include<stdlib.h>

typedef struct Aluno
{
    char nome[20];
    int idade;
    float notas[3];

}Aluno;

float CalcularMedia(float notas[])
{
    return (notas[0] + notas[1] + notas[2])/3;
}

int main()
{
    Aluno alunos[10] = 
    {
        "Clemilson", 27, {8.5, 7.3, 9.4},
        "Elena", 21, {6.5, 7.1, 7.5},
        "Francisco", 18, {4.3, 6.5, 7.8},
        "Joao", 30, {7.5, 7.3, 6.8},
        "Maria", 25, {9.4, 8.9, 9.1},
        "Fernando", 29, {7.1, 6.4, 5.4},
        "Mario", 19, {6.8, 5.2, 8.1},
        "Guilherme", 23, {7.5, 5.1, 7.9},
        "Luana", 22, {10.0, 8.9, 6.5},
        "Isabela", 31, {8.9, 9.5, 9.1}
    };
    
    FILE * fpointer = fopen("AARelatorio.txt", "w");
    fprintf(fpointer, "-----::Alunos::-----\n");
    for(int i = 0; i < 10; i++)
    {
        fprintf(fpointer, "* %s, %d anos de idade, notas: %.1f, %.1f, %.1f e media: %.1f\n", alunos[i].nome, alunos[i].idade, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], CalcularMedia(alunos[i].notas));
    }
    fclose(fpointer);
    return 0;

}