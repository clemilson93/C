#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define CRESCENTE 0
#define DECRESCENTE 1

struct pessoa{
    char nome[30];
    int matricula;
    float nota;
};

struct ordenacao{
    int metodo;
    int ordem;
    char campo[10];
};

void intMostrarVetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(i%40 == 0){
            printf("\n");
        }
        printf("[%d]", vetor[i]);
    }
    printf("\n");
}

void structMostrarVetor(struct pessoa _vetor[], int _tamanho){
    printf("---Pessoas---\n");
    for(int i = 0; i < _tamanho; i++){
        printf("%s\t%d\t%.1f\n", _vetor[i].nome, _vetor[i].matricula, _vetor[i].nota);
    }
    printf("-------------\n");
}

void intBubbleSort(int _vetor[], int _tamanho, int _ordem){
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

void intInsertionSort(int _vetor[], int _tamanho, int _ordem){
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

void intSelectionSort(int _vetor[], int _tamanho, int _ordem){
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
void intMergeSort(int _vetor[], int _tamanho, int _ordem){
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
        intMergeSort(vetor1, tamanhoVetor1, _ordem);
        intMergeSort(vetor2, tamanhoVetor2, _ordem);
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
                    if(k < _tamanho){
                        _vetor[k] = vetor2[j];
                        j++;
                    }
                }
            }
            if(j == tamanhoVetor2){
                for(; k < _tamanho;){
                    k++;
                    if(k < _tamanho){
                        _vetor[k] = vetor1[i];
                        i++;
                    }
                }
            }
        }
    }
}

void structBubbleSort(struct pessoa _vetor[], int _tamanho, int _ordem, char _campo[]){
    int troca, i;
    struct pessoa pessoaTemporaria;
    
    if(strcmp(_campo, "nome") == 0){
        do{
            troca = 0;
            for(i = 0; i < (_tamanho - 1); i++){
                if(_ordem == CRESCENTE){
                    if(_vetor[i].nome[0] > _vetor[i + 1].nome[0]){
                        pessoaTemporaria = _vetor[i];
                        _vetor[i] = _vetor[i + 1];
                        _vetor[i + 1] = pessoaTemporaria;
                        troca++;
                    }
                }
                if(_ordem == DECRESCENTE){
                    if(_vetor[i].nome[0] < _vetor[i + 1].nome[0]){
                        pessoaTemporaria = _vetor[i];
                        _vetor[i] = _vetor[i + 1];
                        _vetor[i + 1] = pessoaTemporaria;
                        troca++;
                    }
                }
            }
        }while(troca > 0);
    }

    if(strcmp(_campo, "matricula") == 0){
        do{
            troca = 0;
            for(i = 0; i < (_tamanho - 1); i++){
                if(_ordem == CRESCENTE){
                    if(_vetor[i].matricula > _vetor[i + 1].matricula){
                        pessoaTemporaria = _vetor[i];
                        _vetor[i] = _vetor[i + 1];
                        _vetor[i + 1] = pessoaTemporaria;
                        troca++;
                    }
                }
                if(_ordem == DECRESCENTE){
                    if(_vetor[i].matricula < _vetor[i + 1].matricula){
                        pessoaTemporaria = _vetor[i];
                        _vetor[i] = _vetor[i + 1];
                        _vetor[i + 1] = pessoaTemporaria;
                        troca++;
                    }
                }
            }
        }while(troca > 0);
    }

    if(strcmp(_campo, "nota") == 0){
        do{
            troca = 0;
            for(i = 0; i < (_tamanho - 1); i++){
                if(_ordem == CRESCENTE){
                    if(_vetor[i].nota > _vetor[i + 1].nota){
                        pessoaTemporaria = _vetor[i];
                        _vetor[i] = _vetor[i + 1];
                        _vetor[i + 1] = pessoaTemporaria;
                        troca++;
                    }
                }
                if(_ordem == DECRESCENTE){
                    if(_vetor[i].nome[0] < _vetor[i + 1].nome[0]){
                        pessoaTemporaria = _vetor[i];
                        _vetor[i] = _vetor[i + 1];
                        _vetor[i + 1] = pessoaTemporaria;
                        troca++;
                    }
                }
            }
        }while(troca > 0);
    }   
}

void structSelectionSort(struct pessoa _vetor[], int _tamanho, int _ordem, char _campo[]){
    struct pessoa elementoMenor;
    int i, j, posicaoDoElementoMenor;
    if(strcmp(_campo, "nome") == 0){
        for(j = 0; j < _tamanho; j++){
            elementoMenor = _vetor[j];
            posicaoDoElementoMenor = j;
            for(i = j + 1; i < _tamanho; i++){
                if(_ordem == DECRESCENTE){
                    if(elementoMenor.nome[0] < _vetor[i].nome[0]){
                        elementoMenor = _vetor[i];
                        posicaoDoElementoMenor = i;
                    }
                }
                if(_ordem == CRESCENTE){
                    if(elementoMenor.nome[0] > _vetor[i].nome[0]){
                        elementoMenor = _vetor[i];
                        posicaoDoElementoMenor = i;
                    }
                }
            }
            if(elementoMenor.nome[0] != _vetor[j].nome[0]){
                _vetor[posicaoDoElementoMenor] = _vetor[j];
                _vetor[j] = elementoMenor;
            }
        }
    }
    if(strcmp(_campo, "matricula") == 0){
        for(j = 0; j < _tamanho; j++){
            elementoMenor = _vetor[j];
            posicaoDoElementoMenor = j;
            for(i = j + 1; i < _tamanho; i++){
                if(_ordem == DECRESCENTE){
                    if(elementoMenor.matricula < _vetor[i].matricula){
                        elementoMenor = _vetor[i];
                        posicaoDoElementoMenor = i;
                    }
                }
                if(_ordem == CRESCENTE){
                    if(elementoMenor.matricula > _vetor[i].matricula){
                        elementoMenor = _vetor[i];
                        posicaoDoElementoMenor = i;
                    }
                }
            }
            if(elementoMenor.matricula != _vetor[j].matricula){
                _vetor[posicaoDoElementoMenor] = _vetor[j];
                _vetor[j] = elementoMenor;
            }
        }
    }
    if(strcmp(_campo, "nota") == 0){
        for(j = 0; j < _tamanho; j++){
            elementoMenor = _vetor[j];
            posicaoDoElementoMenor = j;
            for(i = j + 1; i < _tamanho; i++){
                if(_ordem == DECRESCENTE){
                    if(elementoMenor.nota < _vetor[i].nota){
                        elementoMenor = _vetor[i];
                        posicaoDoElementoMenor = i;
                    }
                }
                if(_ordem == CRESCENTE){
                    if(elementoMenor.nota > _vetor[i].nota){
                        elementoMenor = _vetor[i];
                        posicaoDoElementoMenor = i;
                    }
                }
            }
            if(elementoMenor.nota != _vetor[j].nota){
                _vetor[posicaoDoElementoMenor] = _vetor[j];
                _vetor[j] = elementoMenor;
            }
        }
    }
}

void structInsertionSort(struct pessoa _vetor[], int _tamanho, int _ordem, char _campo[]){
    int i, j;
    struct pessoa elementoSelecionado;
    if(strcmp(_campo, "nome") == 0){
        for(i = 1; i < _tamanho; i++){
            elementoSelecionado = _vetor[i];
            for(j = i-1; j >= 0; j--){
                if(_ordem == CRESCENTE){
                    if(elementoSelecionado.nome[0] < _vetor[j].nome[0]){
                        _vetor[j+1] = _vetor[j];
                        _vetor[j] = elementoSelecionado;
                    }
                }
                if(_ordem == DECRESCENTE){
                    if(elementoSelecionado.nome[0] > _vetor[j].nome[0]){
                        _vetor[j+1] = _vetor[j];
                        _vetor[j] = elementoSelecionado;
                    }
                }
            }
        }
    }
    if(strcmp(_campo, "matricula") == 0){
        for(i = 1; i < _tamanho; i++){
            elementoSelecionado = _vetor[i];
            for(j = i-1; j >= 0; j--){
                if(_ordem == CRESCENTE){
                    if(elementoSelecionado.matricula < _vetor[j].matricula){
                        _vetor[j+1] = _vetor[j];
                        _vetor[j] = elementoSelecionado;
                    }
                }
                if(_ordem == DECRESCENTE){
                    if(elementoSelecionado.matricula > _vetor[j].matricula){
                        _vetor[j+1] = _vetor[j];
                        _vetor[j] = elementoSelecionado;
                    }
                }
            }
        }
    }
    if(strcmp(_campo, "nota") == 0){
        for(i = 1; i < _tamanho; i++){
            elementoSelecionado = _vetor[i];
            for(j = i-1; j >= 0; j--){
                if(_ordem == CRESCENTE){
                    if(elementoSelecionado.nota < _vetor[j].nota){
                        _vetor[j+1] = _vetor[j];
                        _vetor[j] = elementoSelecionado;
                    }
                }
                if(_ordem == DECRESCENTE){
                    if(elementoSelecionado.nota > _vetor[j].nota){
                        _vetor[j+1] = _vetor[j];
                        _vetor[j] = elementoSelecionado;
                    }
                }
            }
        }
    }
}

int main(){
    struct pessoa pessoas[] = {
            {"Clemilson", 27, 7.3},
            {"Elena", 21, 6.5},
            {"Francisco", 18, 4.3},
            {"Joao", 30, 7.5},
            {"Maria", 25, 9.4},
            {"Fernando", 29, 7.1},
            {"Mario", 19, 6.8},
            {"Guilherme", 23, 7.5},
            {"Luana", 22, 10.0},
            {"Isabela", 31, 8.9}
        };
    int opcao, *vetor, tamanho, i, retorno = -1;
    struct ordenacao parametros;
    while (retorno < 0){
        printf("Digite a opcao desejada:\n1 - Criar vetor manualmente\n2 - Criar vetor automaticamente\n3 - Ordenar estruturas\n0 - sair\n-> ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
            printf("---Criar vetor manualmente---\nDigite a quantidade de elementos do vetor:\n->");
            scanf("%d", &tamanho);
            vetor = malloc(tamanho * sizeof(int));
            printf("Digite os valores para os elementos do vetor.\n");
            for(i = 0; i < tamanho; i++){
                printf("Elemento %d:->", i);
                scanf("%d", &vetor[i]);
            }
            intMostrarVetor(vetor, tamanho);
            retorno = 0;
            break;
            
            case 2:
            printf("---Criar vetor automaticamente---\nDigite a quantidade de elementos do vetor:\n->");
            scanf("%d", &tamanho);
            vetor = malloc(tamanho * sizeof(int));
            srand(time(NULL));
            for(i = 0; i < tamanho; i++){
                vetor[i] = rand()%100;
            }
            //intMostrarVetor(vetor, tamanho);
            while (retorno < 0){
                printf("Digite agora a opcao do metodo de ordenacao desejada:\n1 - Bubble sort\n2 - Insertion sort\n3 - Selection sort\n-> ");
                scanf("%d", &opcao);
                switch (opcao){
                    case 1:
                    parametros.metodo = 1;
                    printf("---Bubble sort---\n");
                    retorno = 0;
                    break;
                    
                    case 2:
                    parametros.metodo = 2;
                    printf("---Insertion sort---\n");
                    retorno = 0;
                    break;

                    case 3:
                    parametros.metodo = 3;
                    printf("---Selection sort---\n");
                    retorno = 0;
                    break;

                    default:
                    printf("Opcao invalida!\n");
                    break;
                }
            }
            retorno = -1;

            while (retorno < 0){
                printf("Digite agora a opcao da ordem desejada:\n1 - Crescente\n2 - Decrescente\n-> ");
                scanf("%d", &opcao);
                switch (opcao){
                    case 1:
                    parametros.ordem = CRESCENTE;
                    printf("---Crescente---\n");
                    retorno = 0;
                    break;
                    
                    case 2:
                    parametros.ordem = DECRESCENTE;
                    printf("---Decrescente---\n");
                    retorno = 0;
                    break;

                    default:
                    printf("Opcao invalida!\n");
                    break;
                }
            }
            float tempoDeExecucao;
            time_t tempoInicial, tempoFinal;
            
            /*switch (parametros.metodo){
                case 1:
                    tempoInicial = time(NULL);
                    intBubbleSort(vetor, tamanho, parametros.ordem);
                    tempoFinal = time(NULL);
                break;
                case 2:
                    tempoInicial = time(NULL);
                    intInsertionSort(vetor, tamanho, parametros.ordem);
                    tempoFinal = time(NULL);
                break;
                case 3:
                    tempoInicial = time(NULL);
                    intSelectionSort(vetor, tamanho, parametros.ordem);
                    tempoFinal = time(NULL);
                break;
            }*/
            //intMostrarVetor(vetor, tamanho);
            //tempoDeExecucao = difftime(tempoFinal, tempoInicial);
            printf("\n");
            printf("Tempo de execucao do metodo escolhido: %f\n", tempoDeExecucao);
            srand(time(NULL));
            /*for(i = 0; i < tamanho; i++){
                vetor[i] = rand()%100;
            }*/
            //intMostrarVetor(vetor, tamanho);
            printf("Executando agora metodo MERGE SORT...\n");
            tempoInicial = time(NULL);
            intMergeSort(vetor, tamanho, parametros.ordem);
            //intBubbleSort(vetor, tamanho, parametros.ordem);
            tempoFinal = time(NULL);
            //intMostrarVetor(vetor, tamanho);
            tempoDeExecucao = difftime(tempoFinal, tempoInicial);
            printf("\n");
            printf("Tempo de execucao do metodo MERGE SORT: %f\n", tempoDeExecucao);
            retorno = 0;
            break;

            case 3:
            printf("Ordenar estruturas\n");
            structMostrarVetor(pessoas, 10);
            while (retorno < 0){
                while (retorno < 0){
                    printf("Digite agora a opcao do metodo de ordenacao desejada:\n1 - Bubble sort\n2 - Insertion sort\n3 - Selection sort\n-> ");
                    scanf("%d", &opcao);
                    switch (opcao){
                        case 1:
                        parametros.metodo = 1;
                        printf("---Bubble sort---\n");
                        retorno = 0;
                        break;
                        
                        case 2:
                        parametros.metodo = 2;
                        printf("---Insertion sort---\n");
                        retorno = 0;
                        break;

                        case 3:
                        parametros.metodo = 3;
                        printf("---Selection sort---\n");
                        retorno = 0;
                        break;

                        default:
                        printf("Opcao invalida!\n");
                        break;
                    }
                }
                retorno = -1;
                while (retorno < 0){
                    printf("Digite agora a opcao da ordem desejada:\n1 - Crescente\n2 - Decrescente\n-> ");
                    scanf("%d", &opcao);
                    switch (opcao){
                        case 1:
                        parametros.ordem = CRESCENTE;
                        printf("---Crescente---\n");
                        retorno = 0;
                        break;
                        
                        case 2:
                        parametros.ordem = DECRESCENTE;
                        printf("---Decrescente---\n");
                        retorno = 0;
                        break;

                        default:
                        printf("Opcao invalida!\n");
                        break;
                    }
                }
                retorno = -1;
                while (retorno < 0){
                    printf("Digite agora a opcao do campo desejado para ordenar:\n1 - Nome\n2 - Matricula\n3 - Nota\n-> ");
                    scanf("%d", &opcao);
                    switch (opcao){
                        case 1:
                        parametros.campo[0] = 'n';
                        parametros.campo[1] = 'o';
                        parametros.campo[2] = 'm';
                        parametros.campo[3] = 'e';
                        parametros.campo[4] = '\0';
                        printf("---Nome---\n");
                        retorno = 0;
                        break;
                        
                        case 2:
                        parametros.campo[0] = 'm';
                        parametros.campo[1] = 'a';
                        parametros.campo[2] = 't';
                        parametros.campo[3] = 'r';
                        parametros.campo[4] = 'i';
                        parametros.campo[5] = 'c';
                        parametros.campo[6] = 'u';
                        parametros.campo[7] = 'l';
                        parametros.campo[8] = 'a';
                        parametros.campo[9] = '\0';
                        printf("---Matricula---\n");
                        retorno = 0;
                        break;

                        case 3:
                        parametros.campo[0] = 'n';
                        parametros.campo[1] = 'o';
                        parametros.campo[2] = 't';
                        parametros.campo[3] = 'a';
                        parametros.campo[4] = '\0';
                        printf("---Nota---\n");
                        retorno = 0;
                        break;

                        default:
                        printf("Opcao invalida!\n");
                        break;
                    }
                }
                printf("%d %s %d\n",parametros.metodo, parametros.campo, parametros.ordem);
                switch (parametros.metodo){
                case 1:
                    structBubbleSort(pessoas, 10, parametros.ordem, parametros.campo);
                break;
                case 2:
                    structInsertionSort(pessoas, 10, parametros.ordem, parametros.campo);
                break;
                case 3:
                    structSelectionSort(pessoas, 10, parametros.ordem, parametros.campo);
                break;
                
                default:
                    break;
                }
            }
            structMostrarVetor(pessoas, 10);
            retorno = 0;
            break;

            case 0:
            retorno = 0;
            break;

            default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    retorno = -1;
    /*float tempoDeExecucao;
    time_t tempoInicial, tempoFinal;
    tempoDeExecucao = difftime(tempoFinal, tempoInicial);
    printf("\n");
    printf("Tempo de execucao: %f\n", tempoDeExecucao);*/
    return 0;
}