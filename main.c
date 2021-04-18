#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "./FNC_3_SAT/FNC_3_SAT.h"



int menu_principal(){

    int opcao = 0;

    printf("::::::::::::::::::::::: MENU :::::::::::::::::::::::\n");
    printf("::                                                ::\n");
    printf("::             [1] Modo automatico                ::\n");
    printf("::                                                ::\n");
    printf("::             [2] Modo interativo                ::\n");
    printf("::                                                ::\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

    scanf("%d", &opcao);

    if (opcao == 1){
        return 1;
    }

    if (opcao == 2){
        return 2;
    }

    else {

        printf("OPÇÃO INVÁLIDA, ENCERRANDO O PROGRAMA\n");
        return 0;

    }
}

int main(void){

    clock_t begin;
    clock_t end;

    int menu_opcao = menu_principal();

    if (menu_opcao == 1){

        int num_literals;

        printf("Insira o numero de literais: ");
        scanf("%d", &num_literals);

        begin = time(NULL);
        automatic(num_literals);

        end = time(NULL);
    }

    if (menu_opcao == 2){

        begin = time(NULL);

        interactive();

        end = time(NULL);
    }


    double time_spent = difftime(end, begin);

    printf("Tempo gasto na execução %.2lf segundos\n", time_spent);
}

