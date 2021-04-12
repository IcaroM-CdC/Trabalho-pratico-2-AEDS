#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define CONST_ELEMENTS_CLAUSE 3


// ------ STRUCT DE UM ELEMENTO DA TUPLA
typedef struct element_tuple{
      int num_literal;
      int state;
} element;

// ------ STRUCT DE UMA TUPLA DE ELEMENTOS
typedef struct clause_tuple{
      element tuples[3];
      
} clause;

int **generate_table(int num_variables, int printar);
clause *read_clauses(int num_clauses, int num_variables);
void calculate_trues(clause *clauses, int **matrix, int num_clauses, int num_variables);
void interactive();
void automatic();
#endif