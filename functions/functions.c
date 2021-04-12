#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"


// ------ FUNCAO QUE GERA AS COMBINACOES TABELA VERDADE
int **generate_table(int num_variables, int printar){

// ------------------ ALOCAÇÃO DA MATRIZ -----------------------
    int **matrix;

    int COLUMNS = num_variables;
    int LINES = pow(2, num_variables) + 1;

    matrix = (int**) malloc(COLUMNS * sizeof(int*));

    for (int i = 0; i < LINES; i++){
        matrix[i] = (int*) malloc(LINES * sizeof(int));
    }

// -------------------------------------------------------------

    for (int index = 0; index < num_variables; index++){

        // Preenchendo a primeira linha de cada coluna com o valor da literal da tabela verdade
        matrix[index][0] = index + 1;
    }

    /* 
        A matriz é percorrida no sentido coluna linha
    */

    int aux_var_number = num_variables;
    int divisor = 2;

    for (int index = 0; index < COLUMNS; index++){ // COLUNAS
        int fill_with_zero = 1;
        int counter = 1;

        // Inicia a partir da LINHA 1, pois a primeira contem os indices
        for (int index2 = 1; index2 < LINES; index2++){ // LINHAS

            if (counter <= pow(2, aux_var_number - 1)){
                if (fill_with_zero == 1){
                    matrix[index][index2] = 0;
                }
                if (fill_with_zero == 0){
                    matrix[index][index2] = 1;
                }
                if (counter == pow(2, aux_var_number - 1)){
                    counter = 0;
                    if (fill_with_zero == 1){
                        fill_with_zero = 0;
                    }
                    else if (fill_with_zero == 0){
                        fill_with_zero = 1;
                    }
                }
            }
            counter++;
        }
        aux_var_number--;
    } 
      // PARA PRINTAR = 1, ESCREVE AS OPÇOES
    if (printar == 1) {
        for (int index2 = 0; index2 < LINES; index2++){ // COLUNAS
            for (int index = 0; index < COLUMNS; index++){ // LINHAS
                printf("  %d  |", matrix[index][index2]);
            }

            printf("\n");
        }
    }
    return matrix;
}

// ------ FUNCAO QUE LE AS CLAUSULAS
clause *read_clauses(int num_clauses, int num_variables){
      clause *clauses = (clause *) malloc(num_clauses * sizeof(clause));

      // LÊ CADA CLAUSULA
      for (int i=0; i<num_clauses; i++){
        // LE CADA ELEMENTO DA CLAUSULA
        printf("\n*--INICIO DA CLAUSULA %d--*\n", i+1);

        for (int j=0; j<CONST_ELEMENTS_CLAUSE; j++){
            printf("Digite a variavel (de 0 a %d): ", num_variables - 1);
            scanf("%d", &clauses[i].tuples[j].num_literal);
            printf("Digite o estado (1 = negativo | 2 = positivo): ");
            scanf("%d", &clauses[i].tuples[j].state);
        }
        printf("*--FIM DA CLAUSULA %d--*\n", i+1);
      }
      return clauses; //RETORNA VETOR DE CLAUSULAS
}

// ------ FUNCAO QUE CALCULA OS CONJUNTOS QUE TORNAM A EQUACAO VERDADEIRA, E PRINTA
void calculate_trues(clause *clauses, int **matrix, int num_clauses, int num_variables){
    int print_label = 1;

    for (int i=1; i<pow(2,num_variables)+1; i++){ //PARA CADA LINHA
        //VER SE TODAS AS CLAUSULAS SAO VERDADEIRAS
        int aux = 0;
        for(int j=0; j<num_clauses; j++){
            int clause_value = 0;

            for(int k=0; k<CONST_ELEMENTS_CLAUSE; k++){
                if (clauses[j].tuples[k].state == 1){
                    clause_value = clause_value || !matrix[clauses[j].tuples[k].num_literal][i];
                    
                }else{
                    clause_value = clause_value || matrix[clauses[j].tuples[k].num_literal][i];
                    
                }
            }
            if (!clause_value)
                break;
            else
                aux++;
    
        }
        if (aux == num_clauses){
            if (print_label){
                printf("\n\nAs combinacoes que tornam a equacao verdadeira sao: \n\n");
                for(int i=0; i<num_variables; i++){
                    printf(" %c ", i+65);
                }
                printf("\n");
            }
            print_label = 0;
            for (int p=0; p<num_variables; p++){
                printf(" %d ", matrix[p][i]);
            }
            printf("\n"); 
        }
    }

    if (print_label){
        printf("\nNenhuma combinacao satisfaz a expressao escolhida\n");
    }
}

void interactive(){
    //------------------------DEF DADOS--------------------------
    
    int num_clauses;
    int num_variable;
    
    clause *clauses;

    //------------------------LER DADOS--------------------------
    printf("\nNumero de clausulas: ");
    scanf("%d", &num_clauses);
    printf("Numero de variaveis: ");
    scanf("%d", &num_variable);

    //------------------------MONTA TABELA
    int **matrix = generate_table(num_variable, 0);
    
    //---------------------LER CLAUSULAS-------------------------
    clauses = read_clauses(num_clauses, num_variable);

    //---------------------CALCULA AS QUE TORNAM VERDADEIRAS E PRINTA
    calculate_trues(clauses, matrix, num_clauses, num_variable);
}

void automatic(){
    ;
}