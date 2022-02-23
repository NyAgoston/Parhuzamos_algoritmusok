/* C Program to count the Number of Lines in a Text File */
#include <stdio.h>
#define MAX_FILE_NAME 100

int main()
{
	FILE *fp;
	int count = 0; 
	char c; 

	fp = fopen("meret.txt", "r");

	if (fp == NULL)
	{
		printf("Could not open file meret.txt");
		return 0;
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') 
			count += 1;

	
	fclose(fp);
	printf("The file meret.txt has %d lines\n ", count + 1);

	return 0;
}
