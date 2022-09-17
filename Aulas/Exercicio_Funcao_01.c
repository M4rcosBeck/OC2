/*

Faça um código em C com duas funções: uma que diga se um ano é bissexto ou não e outra que calcule quantos anos bissextos ocorreram desde o ano 1 até o ano 2010. Crie uma função de menu que permita ao usuário escolher qual função utilizar.

*/

int bissexto(ano){
    if(ano % 4 == 0 || ano % 400 == 0){
        if(ano % 100 != 0){
                printf("Esse ano eh bissexto!");
        }else{
            printf("Nao eh bissexto!");
        }
    }else{
        printf("Nao eh bissexto!");
    }
}

void quantidade(){
    const vigente = 2010;
    const gregoriano_inicio = 1582;

    float resultado;
    resultado = (vigente - gregoriano_inicio)/4;

    printf("A quantidade de anos bissextos ate hoje eh de %.0f.", resultado);
}

int main(int argc, char const *argv[])
{
    int menu = 0;
    int ano = 0;

    printf("1- Saber se o ano e bissexto.\n2- Quantidade de anos bissextos.\n3- Encerrar programa.\n");
    scanf("%i", &menu);

    if(menu == 1){
        printf("Digite o ano: ");
        scanf("%i", &ano);    
        bissexto(ano);
    }else if(menu == 2){
        quantidade();
    }else if(menu == 3){
        return 0;
    }else{
        printf("Erro desconhecido.");
    }

    return 0;
}
