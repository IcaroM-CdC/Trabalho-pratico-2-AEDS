#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./FNC_3_SAT/FNC_3_SAT.h"

int main(void){

    int selecao;
    printf("Como voce deseja usar o projeto?\n0-Interativo\n1-Automatico\n");
    scanf("%d", &selecao);
    if (!selecao){
        interactive();
    }
    else{
        automatic();
    }


}

