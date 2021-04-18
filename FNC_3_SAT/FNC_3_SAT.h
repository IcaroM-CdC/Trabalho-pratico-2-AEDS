#ifndef FNC_3_SAT
#define FNC_3_SAT

#define CONST_ELEMENTS_CLAUSE 3

typedef struct element_tuple element;
typedef struct clause_tuple clause;

struct element_tuple {

      int num_literal;
      int state;

};

struct clause_tuple{

      element tuples[3];
      
};

clause *read_clauses(int num_clauses, int num_variables);
clause *read_clauses_automatic(int num_clauses, int num_literals, int **matrix);


int calculate_trues(clause *clauses, int num_clauses, int num_variables);
int interactive();
int automatic(int num_literals);


#endif