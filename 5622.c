#include <stdio.h>
#include <string.h>

int main ()
{
	char string[16] = "";
	scanf("%s",string);
	int i;
	int time = 0;

	for (i=0; i<strlen(string); i++)
	{
		if ('A' <= string[i] && 'C' >= string[i]) time += 3;
		else if ('D' <= string[i] && 'F' >= string[i]) time += 4;
		else if ('G' <= string[i] && 'I' >= string[i]) time += 5;
		else if ('J' <= string[i] && 'L' >= string[i]) time += 6;
		else if ('M' <= string[i] && 'O' >= string[i]) time += 7;
		else if ('P' <= string[i] && 'S' >= string[i]) time += 8;
		else if ('T' <= string[i] && 'V' >= string[i]) time += 9;
		else if ('W' <= string[i] && 'Z' >= string[i]) time += 10;
	}

	printf("%d\n",time);
}
