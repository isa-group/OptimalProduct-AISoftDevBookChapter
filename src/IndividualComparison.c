/* individual relation checking routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "Global.h"
# include "Random.h"

// Compare Pareto dominance relation between individuals a and b by considering the main objective first and then the secondary ones  
// The function will return the following values
// 1 if a dominates b
// -1 if b dominates a
// 0 if both a and b are non-dominated 
int check_dominance (individual *a, individual *b)
{
    int i;
    int flag1;
    int flag2;
    flag1 = 0;
    flag2 = 0;

	if (a->fobj < b->fobj)
	{
		return (1);
	}
	else
	{
		if (a->fobj > b->fobj)
		{
			return (-1);
		}
		else
		{
			for (i=0; i<nsobj; i++)
			{
				if (a->sobj[i] < b->sobj[i])
				{
					flag1 = 1;
				}
				else
				{
					if (a->sobj[i] > b->sobj[i])
					{
						flag2 = 1;
					}
				}
			}
			if (flag1==1 && flag2==0)
			{
				return (1);
			}
			else
			{
				if (flag1==0 && flag2==1)
				{
					return (-1);
				}
				else
				{
					return (0);
				}
			}
		}
	}	
}
