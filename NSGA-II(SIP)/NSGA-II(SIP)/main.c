/*==========================================================================
//  Implementation of NSGA-II with SIP
//  Last update 7, FEB, 2016
//
//
//	Please find details of SIP in the following paper
//  R. M. Hierons, M. Li, X. Liu, S. Segura, and W. Zheng. SIP: Optimal product selection from feature models using many-objective 
//	evolutionary optimisation. ACM Transactions on Software Engineering and Methodology, 2016, in press.
//
//  Please find details of NSGA-II in the following paper
//	K. Deb, A. Pratap, S. Agarwal, and T. Meyarivan. A fast and elitist multiobjective genetic algorithm: NSGA-II. 
//	IEEE Transactions on Evolutionary Computation 6(2): 182-197, 2002.
//
//
//  The source code of the EA part was implemented by Miqing Li (http://www.cs.bham.ac.uk/~limx) 
//	and the encoding part (i.e. AntiCode.h and Violation.h) by Wei Zheng  
//
//  The codes are free for reserach work.
//  If you have any problem with the source codes, please contact
//  Miqing Li at limitsing@gmail.com 
===========================================================================*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# include "Global.h"
# include "Random.h"

	#define DrupalReal

int main (int argc, char **argv)
{
	int j;
	int random;
	double runTime, startTime, endTime;
	
	FILE *fptOutputObj;         // for the output of the final population in the objective space
    FILE *fptOutputVar;         // for the output of the final population in the variable space

	FILE *fptTest;
	
    population *parent_pop;
    population *child_pop;
    population *mixed_pop;

	srand((unsigned)time(NULL));
    random = rand()%1000;

    seed=(float) random/1000.0;
    if (seed<=0.0 || seed>=1.0)
    {
        printf("\n Entered seed value is wrong, seed value must be in (0,1) \n");
        exit(1);
    }

    fptOutputObj = fopen("populationObj","w");
    fptOutputVar = fopen("populationVar","w");
	fptTest = fopen("allbest.txt","w");

/*-------model selection------start---------*/
	
#ifdef DrupalReal
	model = 7;
#endif

/*-------model selection------end---------*/


/*-------test problem setting------start---------*/
	
// NOBJ is the number of all the objectives
	switch (model)  
	{
	case 7:
		{
			NOBJ = 8;
			break;
		}
	case 8:
		{
			NOBJ = 8;
			break;
		}
	default:
		{
			NOBJ = 5;
		}
	}
				
	nsobj = NOBJ - 1;				// number of the secondary objectives

// nstring_all is the number of all the features  
// nstring is the actual number of the features in the novel representation   
	switch (model)  
	{
	case 1:
		{
			nstring_all = 13;
			nstring = 10;	
			break;
		}
	case 2:
		{
			nstring_all = 36;
			nstring = 25;
			break;
		}
	case 3:
		{
			nstring_all = 43;
			nstring = 28;
			break;
		}
	case 4:
		{
			nstring_all = 290;
			nstring = 202;
			break;
		}
	case 5:
		{
			nstring_all = 48;
			nstring = 39;
			break;
		}
	case 6:
		{
			nstring_all = 79;
			nstring = 59;
			break;
		}
	case 7:
		{
			nstring_all = 48;
			nstring = 39;
			break;
		}
	case 8:
		{
			nstring_all = 79;
			nstring = 59;
			break;
		}
	case 9:
		{
			nstring_all = 10000;
			nstring = 5922;
			break;
		}
	}
	wholefeature = (int *)malloc(nstring_all * sizeof(int));		// the whole binary string
	
/*-------test problem setting------end---------*/

/*-------parameter setting in the algorithm------start---------*/
	popsize = 100;					// population size
    neval = 50000;					// maximal number of evaluations
	nrun = 30;						// total number of runs

	pcross_bin= 1.0;				// crossover probability		
	pmut_bin=1.0/nstring;			// mutation probability
/*-------parameter setting in the algorithm------end---------*/
	
	parent_pop = (population *)malloc(sizeof(population));
    child_pop = (population *)malloc(sizeof(population));
    mixed_pop = (population *)malloc(sizeof(population));

    allocate_memory_pop (parent_pop, popsize);
    allocate_memory_pop (child_pop, popsize);
    allocate_memory_pop (mixed_pop, 2*popsize);
		
    randomize();
	printf("Parameter setting done, now start running ");
   
	for (j=0; j<nrun; j++)
	{
		startTime = clock();
		printf("\n %d run; 0 generation...", j+1);
		currenteval = 0;
		initialize_pop (parent_pop);
		evaluate_pop (parent_pop, popsize);

		while (currenteval < neval)		
		{
			printf("\n %d run; %d evaluations...", j+1, currenteval);
			assign_rank_and_crowding_distance (parent_pop);		// fitness assignment for mating selection
			mating_selection (parent_pop, child_pop);			// mating selection and crossover
			mutation_pop (child_pop);							// mutation	
			evaluate_pop(child_pop, popsize);
			merge(parent_pop, child_pop, mixed_pop);			
			environmental_selection(mixed_pop, parent_pop);		// environmental selection	
		}
		endTime=clock();
		runTime=(endTime-startTime)/CLOCKS_PER_SEC;
		printf("\n the time of the %d run is %f\n", j+1, runTime);

		if (j==0)
		{
			report_objective_property(fptOutputObj);				// report the objective property (i.e., minimisation or maximisation)
		}		
		report_variable(parent_pop, popsize, fptOutputVar);			// report individuals' value in the decision space
		report_objective(parent_pop, popsize, fptOutputObj);		// report individuals' value in the objective space

		report_test(parent_pop, popsize, fptTest);
		
		fflush(stdout);
		fflush(fptOutputVar);
		fflush(fptOutputObj);

		fflush(fptTest);
	}
	fclose(fptOutputVar);
	fclose(fptOutputObj);
	fclose(fptTest);
	
	deallocate_memory_pop (parent_pop, popsize);
    deallocate_memory_pop (child_pop, popsize);
    deallocate_memory_pop (mixed_pop, 2*popsize);
    free (parent_pop);
    free (child_pop);
    free (mixed_pop);

	free(wholefeature);

    printf("\n Routine successfully exited \a\n");
    return (0);
}
