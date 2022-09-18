/*

Escrever um programa que permita ao usuário escolher dentre as figuras geométricas círculo, retângulo e triângulo para calcular a área da figura escolhida. Crie funções para o cálculo de área de cada figura e para um menu de escolha.

*/

#include <stdio.h>

int escolha;
float raio;
float area;
float base;
float altura;

int circulo(float raio){
    #define PI 3.1416;
    
    area = raio * PI;    
    return area;
}
    
float retangulo(float base, float altura){
    area = base * altura;
    return area;
}
    
float triangulo(float base, float altura){
    area = (base * altura)/2;
    return area;
}
    
int main(int argc, char const *argv[])
{
    printf("1 - calcular circulo\n2 - calcular retangulo\n3 - calcular triangulo\n");
    scanf("%i", &escolha);

    if(escolha == 1){
        //círculo
        printf("Qual o raio do circulo? ");
        scanf ("%f", &raio);
        circulo(raio);
    }else if(escolha == 2){
        //retangulo
        printf("Qual o valor da base? ");
        scanf ("%f", &base);
        printf("Qual o valor da altura? ");
        scanf ("%f", &altura);
        retangulo(base, altura);
    }else if(escolha == 3){
        //triangulo
        printf("Qual o valor da base? ");
        scanf("%f", &base);
        printf("Qual o valor da altura? ");
        scanf("%f", &altura);
        triangulo(base, altura);
    }else{
        printf("Erro.");
    }

    printf("O resultado eh: %.2f", area);

    return 0;
}
