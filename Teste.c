#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void f1(int n1, int n2){
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void f2(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

struct Ponto{
    int x;
    int y;
};

int soma(int *x, int *y){
    printf("%d, %d\n", *x, *y);
    int num = *x + *y;
    return num;
}

int main(){
    //inicio do teste 1
    int num1 = 50, num2 = 70;
    f1(num1, num2);
    printf("%d %d", num1, num2);
    num1 = 50;
    num2 = 70;
    f2(&num1, &num2);
    printf("%d %d", num1, num2);
    //fim do teste 1
    printf("\n*\n");
    //inicio do teste 2
    struct Ponto partida = {4, 6};
    struct Ponto final = {11, 6};
    double distancia = sqrt((final.x-partida.x)*(final.x-partida.x)+(final.y-partida.y)*(final.y-partida.y));
    printf("%.2f", distancia);
    //fim do teste 2
    printf("\n*\n");
    //inicio do teste 3
    int *p, *q, *r, x = 10, y = 20;
    p = &x;
    q = &y;
    *p = *p + *q;
    (*q)++;
    r = q;
    *q = *p;
    printf("%d %d %d %d %d", *p, *q, *r, x, y);
    //fim do teste 3
    printf("\n*\n");
    //inicio teste 4
    int g = 4, h = 6;
    int *pnt_g = &g;
    int *pnt_h = &h;
    printf("%d, %d\n", *pnt_g, *pnt_h);
    g = soma(&g, &h);
    printf("Resultado = %d", g);
    //fim do teste 4
    printf("\n*\n");
    return 0;
}