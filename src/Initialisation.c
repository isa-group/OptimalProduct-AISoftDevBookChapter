/* Data initialisation routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "Global.h"
# include "Random.h"

/* Function to initialize a population randomly */
void initialize_pop (population *pop)
{
    int i;
    for (i=0; i<popsize; i++)
    {
        initialize_ind (&(pop->ind[i]));
    }
    return;
}

/* Function to initialize an individual randomly */
void initialize_ind (individual *ind)
{
	int j;
	for (j = 0; j < nstring; ++j)
	{
		if (randomperc() <= 0.5)
			ind->gene[j] = 0;
		else
			ind->gene[j] = 1;
	}
	return;
} 