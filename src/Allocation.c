/* Memory allocation and deallocation routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "Global.h"
# include "Random.h"

/* Function to allocate memory to a population */
void allocate_memory_pop (population *pop, int size)
{
    int i;
    pop->ind = (individual *)malloc(size*sizeof(individual));
    for (i=0; i<size; i++)
    {
        allocate_memory_ind (&(pop->ind[i]));
    }
    return;
}

/* Function to allocate memory to an individual */
void allocate_memory_ind (individual *ind)
{
	ind->gene = (int *)malloc(nstring*sizeof(int));
	ind->sobj = (double *)malloc(nsobj*sizeof(double));
	ind->sobj_norm = (double *)malloc(nsobj*sizeof(double));
    return;
}


/* Function to deallocate memory to a population */
void deallocate_memory_pop (population *pop, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        deallocate_memory_ind (&(pop->ind[i]));
    }
    free (pop->ind);
    return;
}

/* Function to deallocate memory to an individual */
void deallocate_memory_ind (individual *ind)
{
	free(ind->gene);
    free(ind->sobj);
	free(ind->sobj_norm);
    return;
}

