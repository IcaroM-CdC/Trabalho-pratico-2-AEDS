#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "FNC_3_SAT.h"



clause *read_clauses(int num_clauses, int num_literals){

    clause *clauses = (clause*) malloc(num_clauses * sizeof(clause));

    /* 
    
        Para cada iteração de i, uma clausula nova é lida
        e para cada iteração de j, uma das 3 tuplas da cláusula é lida
    
    */

    for (int i = 0; i < num_clauses; i++){

        
        printf("::::::::::::::::: CLAUSULA %d :::::::::::::::::\n", i + 1);

        for (int j = 0; j < CONST_ELEMENTS_CLAUSE; j++){

            printf("Digite o literal (de 0 a %d): ", num_literals - 1);

            scanf("%d", &clauses[i].tuples[j].num_literal);

            printf("Digite o estado (1 = negado | 2 = normal): ");

            scanf("%d", &clauses[i].tuples[j].state);
        }
        
        printf(":::::::::::::::::::::::::::::::::::::::::::::::\n");

    }

    return clauses; /* Retorna o vetor de cláusulas */

}

clause *read_clauses_automatic(int num_clauses, int num_literals, int **matrix){

    clause *clauses = (clause*) malloc(num_clauses * sizeof(clause));

    
    /* 
    
        Aassim como na função análoga para cada iteração de index1, uma clausula nova é lida
        e para cada iteração de index2, uma das 3 tuplas da cláusula é lida
    
    */

    for (int index1 = 0; index1 < num_clauses; index1++){

        for (int index2 = 0; index2 < num_literals; index2++){

            if (matrix[index1][index2] != 0){

                /* 
                    Recebe o estado da cláusula a partir da posição da matriz 
                    e recebe o indice do literal de acordo com o indice de index2
                */

                clauses[index1].tuples[index2].num_literal = index2;
                clauses[index1].tuples[index2].state = matrix[index1][index2];

            }
        }
    }

    return clauses; /* Retorna o vetor de cláusulas */

}


int calculate_trues(clause *clauses, int num_clauses, int num_literals){
    
    
    int print_label = 1;
    long long int LINES = pow(2, num_literals);
    long long int result;

    int line_result[100];

    

    for (long long int index1 = 0; index1 < LINES; index1++){
        for (int index2 = num_literals - 1; index2 >= 0; index2--){

            result = index1 / pow(2, index2);
            line_result[index2] = result % 2;

        }

        int aux = 0;
        
        for (int j = 0; j < num_clauses; j++){

            int clause_value = 0;

            /* Para cada tupla da cláusula o for realiza a comparação */

            for (int k = 0; k < CONST_ELEMENTS_CLAUSE; k++){

                /* Caso estiver negado etra no if, do contrario entra no else */

                if (clauses[j].tuples[k].state == 1){

                    clause_value = clause_value || !line_result[clauses[j].tuples[k].num_literal];
                    
                }
                
                else {

                    clause_value = clause_value || line_result[clauses[j].tuples[k].num_literal];
                    
                }
            }

            if (!clause_value){     /* Caso ocorra um erro */

                break;

            }

            else {

                aux++;

            }
    
        }

        if (aux == num_clauses){

            if (print_label){

                printf("\n\nAs combinacoes que tornam a equacao verdadeira sao: \n\n");

                for (int i = 0; i < num_literals; i++){

                    printf(" %c ", i + 65);

                }

                printf("\n\n");

            }

            print_label = 0;

            /* Formata a saida imprimindo F se o valor for 0 e V caso for 1 */

            for (int p = 0; p < num_literals; p++){

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
    
    int num_clauses;
    int num_variable;
    
    clause *clauses;


    printf("\nNumero de clausulas: ");
    scanf("%d", &num_clauses);

    printf("Numero de variaveis: ");
    scanf("%d", &num_variable);

    
    clauses = read_clauses(num_clauses, num_variable); /* Faz a leitura das cláusulas */

    calculate_trues(clauses, num_clauses, num_variable); /* Calcula os que satisfazem a equação booleana */

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

                random = rand() % (num_literals - 1);   /* Recebe um numero aleatório entre 0 e o numero de literais */

            }

            if (matrix[index1][random] == 0){

                matrix[index1][random] = 1 + rand() % 2;    /* Recebe um numero aleatório entre 1 e 2 */

            }
        }
    }

    clauses = read_clauses_automatic(num_clauses, num_literals, matrix);

    calculate_trues(clauses, num_clauses, num_literals);

    return 1;

}