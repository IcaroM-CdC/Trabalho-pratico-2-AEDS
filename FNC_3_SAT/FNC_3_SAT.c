#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "FNC_3_SAT.h"



clause *read_clauses(int num_clauses, int num_variables){

    clause *clauses = (clause*) malloc(num_clauses * sizeof(clause));

    // LÊ CADA CLAUSULA
    for (int i = 0; i < num_clauses; i++){

        // LE CADA ELEMENTO DA CLAUSULA
        printf("::::::::::::::::: CLAUSULA %d :::::::::::::::::\n", i + 1);

        for (int j = 0; j < CONST_ELEMENTS_CLAUSE; j++){

            printf("Digite o literal (de 0 a %d): ", num_variables - 1);

            scanf("%d", &clauses[i].tuples[j].num_literal);

            printf("Digite o estado (1 = negado | 2 = normal): ");

            scanf("%d", &clauses[i].tuples[j].state);
        }
        
        printf(":::::::::::::::::::::::::::::::::::::::::::::::\n");

    }

    return clauses; //RETORNA VETOR DE CLAUSULAS

}

clause *read_clauses_automatic(int num_clauses, int num_literals, int **matrix){

    clause *clauses = (clause*) malloc(num_clauses * sizeof(clause));

    // LÊ CADA CLAUSULA
    for (int index1 = 0; index1 < num_clauses; index1++){

        // LE CADA ELEMENTO DA CLAUSULA
        for (int index2 = 0; index2 < num_literals; index2++){

            //printf("%d" ,matrix[index1][index2]);

            if (matrix[index1][index2] != 0){

                clauses[index1].tuples[index2].num_literal = index2;
                clauses[index1].tuples[index2].state = matrix[index1][index2];

            }
        }
    }

    return clauses; //RETORNA VETOR DE CLAUSULAS

}


int calculate_trues(clause *clauses, int num_clauses, int num_variables){
    
    puts("PASSOU\n");

    int print_label = 1;
    long long int LINES = pow(2, num_variables);
    long long int result;

    //int *line_result = (int*) malloc(sizeof(int) * num_variables);
    int line_result[100];

    puts("PASSOU\n");

    for (long long int index1 = 0; index1 < LINES; index1++){
        for (int index2 = num_variables - 1; index2 >= 0; index2--){

            result = index1 / pow(2, index2);
            line_result[index2] = result % 2;

        }

        int aux = 0;
        
        for (int j = 0; j < num_clauses; j++){

            int clause_value = 0;

            for (int k = 0; k < CONST_ELEMENTS_CLAUSE; k++){

                if (clauses[j].tuples[k].state == 1){

                    clause_value = clause_value || !line_result[clauses[j].tuples[k].num_literal];
                    
                }
                
                else {

                    clause_value = clause_value || line_result[clauses[j].tuples[k].num_literal];
                    
                }
            }

            if (!clause_value){

                break;

            }

            else {

                aux++;

            }
    
        }

        if (aux == num_clauses){

            if (print_label){

                printf("\n\nAs combinacoes que tornam a equacao verdadeira sao: \n\n");

                for (int i = 0; i < num_variables; i++){

                    printf(" %c ", i + 65);

                }

                printf("\n\n");

            }

            print_label = 0;

            for (int p = 0; p < num_variables; p++){

                if (line_result[p] == 1){

                    printf(" V ");


                }

                else {

                    printf(" F ");

                }

            }

            printf("\n"); 
        }
    }

    if (print_label){

        printf("\nNenhuma combinacao satisfaz a expressao escolhida\n");

    }

    return 1;

}

int interactive(){
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
    //int **matrix = generate_table(num_variable, 0);
    
    //---------------------LER CLAUSULAS-------------------------
    clauses = read_clauses(num_clauses, num_variable);

    //---------------------CALCULA AS QUE TORNAM VERDADEIRAS E PRINTA
    calculate_trues(clauses, num_clauses, num_variable);

    return 1;

}

int automatic(int num_literals){
    
    int num_clauses;
    int **matrix;
    int **truth_table;

    clause *clauses;


    num_clauses = (num_literals / 3) * 2;

    // ------------------ ALOCAÇÃO DA MATRIZ -----------------------

    matrix = (int**) malloc(sizeof(int*) * num_clauses);

    for (int index = 0; index < num_clauses; index++){

        matrix[index] = (int*) malloc(sizeof(int) * num_literals);

    }

    // ------------------------------------------------------------
    
    for (int index1 = 0; index1 < num_clauses; index1++){
        for (int index2 = 0; index2 < num_literals; index2++){

            matrix[index1][index2] = 0;

        }
    }
    

    /* 
        srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
        com o valor da função time(NULL). Este por sua vez, é calculado
        como sendo o total de segundos passados desde 1 de janeiro de 1970
        até a data atual.
        Desta forma, a cada execução o valor da "semente" será diferente.
    */
  
    srand(time(NULL));

    int random;    

    for (int index1 = 0; index1 < num_clauses; index1++){
        
        for (int index2 = 0; index2 < 3; index2++){

            random = rand() % (num_literals - 1);

            while (matrix[index1][random] != 0){

                random = rand() % (num_literals - 1);

            }

            if (matrix[index1][random] == 0){

                matrix[index1][random] = 1 + rand() % 2;

            }
        }
    }

    clauses = read_clauses_automatic(num_clauses, num_literals, matrix);

    calculate_trues(clauses, num_clauses, num_literals);

    return 1;

}