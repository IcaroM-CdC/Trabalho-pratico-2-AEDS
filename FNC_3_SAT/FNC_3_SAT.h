#ifndef FNC_3_SAT
#define FNC_3_SAT

#define CONST_ELEMENTS_CLAUSE 3

typedef struct element_tuple element;
typedef struct clause_tuple clause;

// ------ STRUCT DE UM ELEMENTO DA TUPLA
struct element_tuple {

      int num_literal;
      int state;

};

// ------ STRUCT DE UMA TUPLA DE ELEMENTOS

struct clause_tuple{

      element tuples[3];
      
};

int **generate_table(int num_variables, int printar);
int calculate_trues(clause *clauses, int **matrix, int num_clauses, int num_variables);
int interactive();
int automatic();

clause *read_clauses(int num_clauses, int num_variables);


#endif