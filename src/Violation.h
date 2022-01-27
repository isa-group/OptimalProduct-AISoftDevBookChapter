#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <math.h>


int LineOfCode[] = {9945,551,2849,20827,4497,8618,1292,1097,898,2996,5027,1894,17572,317,2683,284,8419,54270,782,5757,5627,1026,4580,3429,1627,2696,6312,792,2383,13196,2274,1934,13483,11639,50762,3115,998,8483,13390,480,1462,13088,327,3940,13830,1271,3306};
double CyclomaticComplexity[] = {0.27,0.16,0.24,0.31,0.17,0.41,0.3,0.29,0.17,0.28,0.29,0.67,0.52,0.19,0.46,0.3,0.26,0.41,0.37,0.23,0.23,0.14,0.51,0.23,0.55,0.44,0.6,0.36,0.44,0.51,0.29,0.63,0.59,0.37,0.26,0.19,0.28,0.56,0.35,0.35,0.23,0.41,1.09,0.47,0.49,0.15,0.39};
int TestAssertions[] = {1391,244,677,2138,958,870,94,444,227,287,677,2293,121,0,0,0,1355,1089,538,677,3287,330,347,316,135,1724,106,0,0,456,200,1275,0,0,0,731,0,16,0,0,0,851,6,0,285,7,0};
double Installations[] = {5259525,5259525,5259525,5259525,5259525,5259525,5259525,5259525,5259525,5259525,5259525,5259525,747248,747248,747248,747248,5259525,802467,802467,5259525,5259525,5259525,715563,622478,516333,412324,412324,412324,412324,402163,348278,286892,280919,281797,286556,226295,226295,209653,206805,206805,206805,407569,407569,392705,238388,238388,238388};
int Developers[] = {94,94,94,94,94,94,94,94,94,94,94,94,75,75,75,75,94,178,178,94,94,94,31,33,7,42,42,42,42,46,21,31,29,7,17,43,43,36,43,43,43,45,45,13,52,52,52};
int Changes[] = {4,0,2,16,3,7,2,1,1,3,3,1,32,0,5,1,12,27,0,4,1,2,10,2,7,9,11,4,6,46,14,11,40,90,1,15,0,72,34,2,20,14,1,9,5,4,1};

int Violations(int *gene)
{
	int num = 0;
	int i = 0;
	int feature[48];

	for (i = 0; i < 48; i++)
	{
		feature[i] = gene[i];
	}

	if (feature[0] == 0)
		num++;

	/*Every child requires its own parent.*/
	if (feature[1] == 1 && feature[0] == 0)
		num++;
	if (feature[2] == 1 && feature[1] == 0)
		num++;
	if (feature[3] == 1 && feature[1] == 0)
		num++;
	if (feature[4] == 1 && feature[0] == 0)
		num++;
	if (feature[5] == 1 && feature[0] == 0)
		num++;
	if (feature[6] == 1 && feature[0] == 0)
		num++;
	if (feature[7] == 1 && feature[6] == 0)
		num++;
	if (feature[8] == 1 && feature[6] == 0)
		num++;
	if (feature[9] == 1 && feature[6] == 0)
		num++;
	if (feature[10] == 1 && feature[0] == 0)
		num++;
	if (feature[11] == 1 && feature[0] == 0)
		num++;
	if (feature[12] == 1 && feature[0] == 0)
		num++;
	if (feature[13] == 1 && feature[0] == 0)
		num++;
	if (feature[14] == 1 && feature[13] == 0)
		num++;
	if (feature[15] == 1 && feature[13] == 0)
		num++;
	if (feature[16] == 1 && feature[13] == 0)
		num++;
	if (feature[17] == 1 && feature[0] == 0)
		num++;
	if (feature[18] == 1 && feature[0] == 0)
		num++;
	if (feature[19] == 1 && feature[18] == 0)
		num++;
	if (feature[20] == 1 && feature[0] == 0)
		num++;
	if (feature[21] == 1 && feature[0] == 0)
		num++;
	if (feature[22] == 1 && feature[0] == 0)
		num++;
	if (feature[23] == 1 && feature[0] == 0)
		num++;
	if (feature[24] == 1 && feature[0] == 0)
		num++;
	if (feature[25] == 1 && feature[0] == 0)
		num++;
	if (feature[26] == 1 && feature[0] == 0)
		num++;
	if (feature[27] == 1 && feature[26] == 0)
		num++;
	if (feature[28] == 1 && feature[26] == 0)
		num++;
	if (feature[29] == 1 && feature[26] == 0)
		num++;
	if (feature[30] == 1 && feature[0] == 0)
		num++;
	if (feature[31] == 1 && feature[0] == 0)
		num++;
	if (feature[32] == 1 && feature[0] == 0)
		num++;
	if (feature[33] == 1 && feature[0] == 0)
		num++;
	if (feature[34] == 1 && feature[0] == 0)
		num++;
	if (feature[35] == 1 && feature[0] == 0)
		num++;
	if (feature[36] == 1 && feature[0] == 0)
		num++;
	if (feature[37] == 1 && feature[36] == 0)
		num++;
	if (feature[38] == 1 && feature[0] == 0)
		num++;
	if (feature[39] == 1 && feature[0] == 0)
		num++;
	if (feature[40] == 1 && feature[39] == 0)
		num++;
	if (feature[41] == 1 && feature[39] == 0)
		num++;
	if (feature[42] == 1 && feature[0] == 0)
		num++;
	if (feature[43] == 1 && feature[42] == 0)
		num++;
	if (feature[44] == 1 && feature[0] == 0)
		num++;
	if (feature[45] == 1 && feature[0] == 0)
		num++;
	if (feature[46] == 1 && feature[45] == 0)
		num++;
	if (feature[47] == 1 && feature[45] == 0)
		num++;

	/*If the child is mandatory, the parent requires the child.*/
	if (feature[0] == 1 && feature[1] == 0)
		num++;
	if (feature[0] == 1 && feature[4] == 0)
		num++;
	if (feature[0] == 1 && feature[5] == 0)
		num++;
	if (feature[0] == 1 && feature[6] == 0)
		num++;
	if (feature[6] == 1 && feature[7] == 0)
		num++;
	if (feature[6] == 1 && feature[8] == 0)
		num++;
	if (feature[0] == 1 && feature[17] == 0)
		num++;
	if (feature[26] == 1 && feature[27] == 0)
		num++;

	/*Every cross-tree constraint (CTC) is a rule.*/
	if (feature[3] == 1 && feature[20] == 0)
		num++;
	if (feature[3] == 1 && feature[9] == 0)
		num++;
	if (feature[3] == 1 && feature[21] == 0)
		num++;
	if (feature[11] == 1 && feature[12] == 0)
		num++;
	if (feature[15] == 1 && feature[18] == 0)
		num++;
	if (feature[18] == 1 && feature[13] == 0)
		num++;
	if (feature[19] == 1 && feature[13] == 0)
		num++;
	if (feature[20] == 1 && feature[9] == 0)
		num++;
	if (feature[24] == 1 && feature[23] == 0)
		num++;
	if (feature[24] == 1 && feature[22] == 0)
		num++;
	if (feature[28] == 1 && feature[27] == 0)
		num++;
	if (feature[29] == 1 && feature[27] == 0)
		num++;
	if (feature[29] == 1 && feature[18] == 0)
		num++;
	if (feature[29] == 1 && feature[13] == 0)
		num++;
	if (feature[39] == 1 && feature[13] == 0)
		num++;
	if (feature[40] == 1 && feature[13] == 0)
		num++;
	if (feature[41] == 1 && feature[13] == 0)
		num++;
	if (feature[45] == 1 && feature[42] == 0)
		num++;
	if (feature[45] == 1 && feature[43] == 0)
		num++;
	if (feature[46] == 1 && feature[42] == 0)
		num++;
	if (feature[46] == 1 && feature[43] == 0)
		num++;
	if (feature[47] == 1 && feature[42] == 0)
		num++;
	if (feature[47] == 1 && feature[43] == 0)
		num++;

	return num;
}

int MissingFeatures(int *gene)
{
	int num = 0;
	int i;
	for (i = 0; i<48; i++)
	if (gene[i] == 0)
		num++;
	return num;
}