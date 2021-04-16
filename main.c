#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./FNC_3_SAT/FNC_3_SAT.h"



int menu_principal(){

    int opcao = 0;

    printf("::::::::::::::::::::::: MENU :::::::::::::::::::::::\n");
    printf("::                                                ::\n");
    printf("::             [1] Modo automatico                ::\n");
    printf("::                                                ::\n");
    printf("::             [2] Modo iterativo                 ::\n");
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

    int menu_opcao = menu_principal();

    if (menu_opcao == 1){

        automatic();
    }

    if (menu_opcao == 2){

        interactive();

    }
}

