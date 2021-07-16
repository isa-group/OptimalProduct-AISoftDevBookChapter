/* Crossover routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "Global.h"
# include "Random.h"

/* Function to cross two individuals */
void crossover (individual *parent1, individual *parent2, individual *child1, individual *child2)
{
	uniform_cross (parent1, parent2, child1, child2);
    return;
}

/* Routine for uniform crossover */
void uniform_cross (individual *parent1, individual *parent2, individual *child1, individual *child2)
{	
    int i;

	if (randomperc() <= pcross_bin)
	{
		for (i=0; i<nstring; i++)
		{
			if (randomperc() < 0.5)
			{
				child1->gene[i] = parent1->gene[i];
				child2->gene[i] = parent2->gene[i];
			}
			else
			{
				child1->gene[i] = parent2->gene[i];
				child2->gene[i] = parent1->gene[i];
			}
		}
	}
	else
	{
		for (i=0; i<nstring; i++)
		{
			child1->gene[i] = parent1->gene[i];
			child2->gene[i] = parent2->gene[i];
		}
	}
	return;
}
