/* Optimisation problem definitions */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
#include <string.h>

# include "Global.h"
# include "Random.h"
# include "Violation.h"
# include "AntiCode.h"



	
void test_problem (int *gene, double *sobj, double *fobj)
{
	int j;
	AntiCode(wholefeature, gene);		// Determine the value of the whole binary string

	*fobj = Violations(wholefeature); // Correctness (Min)

	sobj[0] = 0;  // Number of missing features (Min)
	sobj[1] = 0;  // Line of Code (Min)
	sobj[2] = 0;  // Cyclomatic Complexity (Min)
	sobj[3] = 0;  // Test assertions (Max)
	sobj[4] = 0;  // Installations (Max)
	sobj[5] = 0;  // Developers (Min)
	sobj[6] = 0;  // Changes (Min)

	// Calculate the secondary objectives
	sobj[0] = MissingFeatures(wholefeature);
	for (j = 1; j<nstring_all; j++)
	{
		sobj[1] += wholefeature[j] * (LineOfCode[j-1]);
	}

	for (j=1; j<nstring_all; j++)
	{
		sobj[2] += wholefeature[j] * (CyclomaticComplexity[j-1]);			
	}

	for (j = 1; j<nstring_all; j++)
	{
		sobj[3] += wholefeature[j] * (-TestAssertions[j-1]);
	}
	for (j = 1; j<nstring_all; j++)
	{
		sobj[4] += wholefeature[j] * (-Installations[j-1]);
	}

	for (j=1; j<nstring_all; j++)
	{
		sobj[5] += wholefeature[j] * (Developers[j-1]);			
	}

	for (j = 1; j<nstring_all; j++)
	{
		sobj[6] += wholefeature[j] * (Changes[j-1]);
	}

	return;
}
