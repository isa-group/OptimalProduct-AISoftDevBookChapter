
int AntiCode(int* Feature, int* CodedFeature)
{
	int i;
	for(i = 0; i < 48; i++)
	{
		Feature[i] = 0;
	}

	//root node
	Feature[0] = 1;

	Feature[2] = CodedFeature[0];
	Feature[3] = CodedFeature[1];
	Feature[9] = CodedFeature[2];
	Feature[10] = CodedFeature[3];
	Feature[11] = CodedFeature[4];
	Feature[12] = CodedFeature[5];
	Feature[13] = CodedFeature[6];
	Feature[14] = CodedFeature[7];
	Feature[15] = CodedFeature[8];
	Feature[16] = CodedFeature[9];
	Feature[18] = CodedFeature[10];
	Feature[19] = CodedFeature[11];
	Feature[20] = CodedFeature[12];
	Feature[21] = CodedFeature[13];
	Feature[22] = CodedFeature[14];
	Feature[23] = CodedFeature[15];
	Feature[24] = CodedFeature[16];
	Feature[25] = CodedFeature[17];
	Feature[26] = CodedFeature[18];
	Feature[28] = CodedFeature[19];
	Feature[29] = CodedFeature[20];
	Feature[30] = CodedFeature[21];
	Feature[31] = CodedFeature[22];
	Feature[32] = CodedFeature[23];
	Feature[33] = CodedFeature[24];
	Feature[34] = CodedFeature[25];
	Feature[35] = CodedFeature[26];
	Feature[36] = CodedFeature[27];
	Feature[37] = CodedFeature[28];
	Feature[38] = CodedFeature[29];
	Feature[39] = CodedFeature[30];
	Feature[40] = CodedFeature[31];
	Feature[41] = CodedFeature[32];
	Feature[42] = CodedFeature[33];
	Feature[43] = CodedFeature[34];
	Feature[44] = CodedFeature[35];
	Feature[45] = CodedFeature[36];
	Feature[46] = CodedFeature[37];
	Feature[47] = CodedFeature[38];

	if(Feature[0] == 1)
		Feature[1] = 1;
	if(Feature[0] == 1)
		Feature[4] = 1;
	if(Feature[0] == 1)
		Feature[5] = 1;
	if(Feature[0] == 1)
		Feature[6] = 1;
	if(Feature[6] == 1)
		Feature[7] = 1;
	if(Feature[6] == 1)
		Feature[8] = 1;
	if(Feature[0] == 1)
		Feature[17] = 1;
	if(Feature[26] == 1)
		Feature[27] = 1;

	return 0;
}