#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char s1[80], s2[80], s3[80];
	FILE *instream;

	printf("File: ");
	scanf("%80s", s1);

	printf("File2: ");
	scanf("%80s", s2);

	printf("File mix name: ");
	scanf("%80s", s3);

	FILE *fp = fopen(s1, "r");
	FILE *pf = fopen(s2, "r");
	
	if ((instream = fopen(s1, "r")) == NULL)
	{
		printf("Unable to open file %s\n", s1);
		exit(-1);
	}
	else if ((instream = fopen(s2, "r")) == NULL)
	{
		printf("Unable to open file %s\n", s2);
		exit(-1);
	}
	
	FILE *ff = fopen(s3, "w+b");

	while (!feof(fp))
	{
		fgets(s3, 1024, fp);
		fputs(s3, ff);
	}
	while (!feof(pf))
	{
		fgets(s3, 1024, pf);
		fputs(s3, ff);
	}
	printf("Success");
	
	fclose(instream);
	fclose(fp);
	fclose(pf);
	fclose(ff);

	return 0;
}