#include <stdio.h>

int main ()
{
	int n[100][2] = {0,};
	int i,j,N,m;
	n[0][0] = 1;
	n[0][1] = 0;
	n[1][0] = 0;
	n[1][1] = 1;

	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		scanf("%d",&m);
		for(j=2; j<=m; j++)
		{
			n[j][0] = n[j-1][0] + n[j-2][0];
			n[j][1] = n[j-1][1] + n[j-2][1];
		}
		printf("%d %d\n",n[m][0],n[m][1]);
	}
}
