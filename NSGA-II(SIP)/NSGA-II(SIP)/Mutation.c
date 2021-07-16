/* Mutation routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "Global.h"
# include "Random.h"

/* Function to perform mutation in a population */
void mutation_pop (population *pop)
{
    int i;
    for (i=0; i<popsize; i++)
    {
		bit_flip(&(pop->ind[i]));
    }
    return;
}

/* bit-flip mutation of an individual */
void bit_flip (individual *ind)
{
	int i;

	for (i=0; i<nstring; i++)
	{
		if (randomperc() <= pmut_bin)
		{
			if (ind->gene[i] == 0)
				ind->gene[i] = 1;
			else
				ind->gene[i] = 0;
		}
	}
	return;
}
