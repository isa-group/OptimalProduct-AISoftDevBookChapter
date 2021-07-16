/* Routines for putting population data into files */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "Global.h"
# include "Random.h"


/* Output of objective property */
void report_objective_property(FILE *fpt)
{
	int i, j;

	switch (model) 
	{
	case 7:
		{
			fprintf(fpt,"min\t");
			for (j=0; j<nsobj-1; j++)
			{
				if (j==3 || j==4)
				{
					fprintf(fpt,"max\t");
				}
				else
				{
					fprintf(fpt,"min\t");
				}
			}
			fprintf(fpt,"min\n\n");
			break;
		}
	case 8:
		{
			fprintf(fpt,"min\t");
			for (j=0; j<nsobj-1; j++)
			{
				if (j==2 || j==3 || j==4)
				{
					fprintf(fpt,"max\t");
				}
				else
				{
					fprintf(fpt,"min\t");
				}
			}
			fprintf(fpt,"max\n\n");
			break;
		}
	default:
		{
			fprintf(fpt,"min\t");
			for (j=0; j<nsobj-1; j++)
			{
				fprintf(fpt,"min\t");
			}
			fprintf(fpt,"min\n\n");
		}
	}
	return;
}


/* Output of individuals in the objective space */
void report_objective(population *pop, int size, FILE *fpt)
{
	int i, j;

	switch (model) 
	{
	case 7:
		{
			for (i=0; i<size; i++)
			{
				fprintf(fpt,"%.1f\t", pop->ind[i].fobj);
				for (j=0; j<nsobj-1; j++)
				{
					if (j==3 || j==4)
					{
						fprintf(fpt,"%.1f\t", -pop->ind[i].sobj[j]);
					}
					else
					{
						fprintf(fpt,"%.1f\t", pop->ind[i].sobj[j]);
					}
				}
				fprintf(fpt,"%.1f\n", pop->ind[i].sobj[nsobj-1]);
			}
			fprintf(fpt,"\n\n");
			break;
		}
	case 8:
		{
			for (i=0; i<size; i++)
			{
				fprintf(fpt,"%.1f\t", pop->ind[i].fobj);
				for (j=0; j<nsobj-1; j++)
				{
					if (j==2 || j==3 || j==4)
					{
						fprintf(fpt,"%.1f\t", -pop->ind[i].sobj[j]);
					}
					else
					{
						fprintf(fpt,"%.1f\t", pop->ind[i].sobj[j]);
					}
				}
				fprintf(fpt,"%.1f\n", -pop->ind[i].sobj[nsobj-1]);
			}
			fprintf(fpt,"\n\n");
			break;
		}
	default:
		{
			for (i=0; i<size; i++)
			{
				fprintf(fpt,"%.1f\t", pop->ind[i].fobj);
				for (j=0; j<nsobj-1; j++)
				{
					fprintf(fpt,"%.1f\t", pop->ind[i].sobj[j]);
				}
				fprintf(fpt,"%.1f\n", pop->ind[i].sobj[nsobj-1]);
			}
			fprintf(fpt, "\n\n");
		}
	}
	return;
}

/* Output of individuals in the decision space */
void report_variable (population *pop, int size, FILE *fpt)
{
	int i, j;
	for (i=0; i<size; i++)
	{
		for (j=0; j<nstring-1; j++)
		{
			fprintf(fpt,"%d\t",pop->ind[i].gene[j]);
		}
		fprintf(fpt,"%d\n",pop->ind[i].gene[nstring-1]);  
	}
	fprintf(fpt, "\n\n");
    return;
}

void report_test(population *pop, int size, FILE *fpt)
{
	int i, j;
	
	for (i=0; i<size; i++)
	{
		for (j=0; j<nsobj-1; j++)
		{
			fprintf(fpt,"%f\t", pop->ind[i].sobj[j]);
		}
		fprintf(fpt,"%f\t\n", pop->ind[i].sobj[nsobj-1]);
   	}
	fprintf(fpt, "\n");
	return;
}


