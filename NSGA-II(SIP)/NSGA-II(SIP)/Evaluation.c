/* Routine for evaluating population members  */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "Global.h"
# include "Random.h"

/* Routine to evaluate objective function values for a population */
void evaluate_pop (population *pop, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        evaluate_ind (&(pop->ind[i]));
    }
    return;
}

/* Routine to evaluate objective function values for an individual */
void evaluate_ind (individual *ind)
{
	test_problem (ind->gene, ind->sobj, &ind->fobj);
	currenteval ++;
    return;
}
