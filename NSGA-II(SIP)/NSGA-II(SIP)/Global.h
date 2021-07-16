/* This file contains the variable and function declarations */

# define INF 1.0e14
# define EPS 1.0e-14
# define E  2.71828182845905
# define PI 3.14159265358979


/*-------global variables------start---------*/
typedef struct lists
{
    int index;
    struct lists *parent;
    struct lists *child;
} list;

typedef struct
{
    int *gene;					// individual's gene 
	double fobj;				// individual's first objective value
    double *sobj;				// individual's secondary objective value 
	double *sobj_norm;			// normalisation of individual's secondary objective value 

	int rank;					// individual's rank;
	double crowd_dist;			// individual's crowding distance
} individual;

typedef struct
{
    individual *ind;
} population;

extern int model; 
extern int nstring_all;
extern int nstring;
extern int NOBJ;
extern int nsobj;
extern int popsize;
extern double pcross_bin;
extern double pmut_bin;
extern int nrun;
extern int currenteval;
extern int neval;
extern int * wholefeature;
/*-------global variables------end---------*/


/*-------global function declarations------start---------*/
void allocate_memory_pop (population *pop, int size);
void allocate_memory_ind (individual *ind);
void deallocate_memory_pop (population *pop, int size);
void deallocate_memory_ind (individual *ind);

void initialize_pop (population *pop);
void initialize_ind (individual *ind);

void insert (list *node, int x);
list* del (list *node);

void evaluate_pop (population *pop, int size);
void evaluate_ind (individual *ind);
void test_problem (int *gene, double *sobj, double *fobj);

void q_sort_dist(population *pop, int *dist, int left, int right);
void quicksort_dist(population *pop, int *dist, int front_size);
void q_sort_front_obj(population *pop, int objcount, int obj_array[], int left, int right);
void quicksort_front_obj(population *pop, int objcount, int obj_array[], int obj_array_size);

void mating_selection (population *old_pop, population *new_pop);
individual* tournament (individual *ind1, individual *ind2);
void assign_rank_and_crowding_distance (population *new_pop);
void environmental_selection (population *mixed_pop, population *new_pop);
void crowding_fill (population *mixed_pop, population *new_pop, int count, int front_size, list *elite);

void assign_crowding_distance_list (population *pop, list *lst, int front_size);
void assign_crowding_distance (population *pop, int *dist, int **obj_array, int front_size);
void assign_crowding_distance_indices (population *pop, int c1, int c2);

void crossover (individual *parent1, individual *parent2, individual *child1, individual *child2);
void uniform_cross (individual *parent1, individual *parent2, individual *child1, individual *child2);

void mutation_pop (population *pop);
void bit_flip (individual *ind);

int check_dominance (individual *a, individual *b);

void merge(population *pop1, population *pop2, population *pop3);
void copy_ind (individual *ind1, individual *ind2);

void report_objective(population *pop, int size, FILE *fpt);
void report_variable (population *pop, int size, FILE *fpt);
void report_objective_property(FILE *fpt);
void report_test(population *pop, int size, FILE *fpt);
/*-------global function declarations------end---------*/