#include <stdio.h>

int main ()
{
	int n;
	int cost;
	int result = 0;
	int max[1000][1000] = {0, };
	int i,j;

	scanf("%d",&n);
	scanf("%d",&max[0][0]);
	for (i=1; i<n; i++)
	{
		for (j=0; j<=i; j++)
		{
			scanf("%d",&cost);
			if (j == 0) max[i][j] = max[i-1][j] + cost;
			else max[i][j] = ((max[i-1][j-1] > max[i-1][j]) ? max[i-1][j-1] : max[i-1][j]) + cost;
		}
	}
	for (i=0; i<n; i++) result = (max[n-1][i] > result) ? max[n-1][i] : result;
	printf("%d\n", result);
}
