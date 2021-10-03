#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, val;
    int vet[2];
    vet[0] = 12;
    vet[1] = 35;
    int *pntVet = &vet[0];
    srand(time(NULL));
    do{
        printf("Digite:\n1 - trocar valor do vet[0]\n2 - gerar numero aleatorio para vet[0]\n0 - sair\n");
        scanf("%d", &n);
        switch (n){
            case 1:
                printf("Digite novo valor para vet[0]: ");
                scanf("%d", &val);
                vet[0] = val;
                printf("Ponteiro: %d", *pntVet);
            break;

            case 2:
                for(int i = 0; i < 10; i++){
                    printf("%d - ", rand()%10);
                }
            break;
            
            default:
                printf("ERRO!");
            break;
        }
        printf("\n");
    }while(n > 0);
    return 0;
}