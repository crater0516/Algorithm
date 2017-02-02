#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int min (int args, ...);

int main ()
{
	int N,i;
	int r,g,b;
	int arr[1001][3] = {0, };
	scanf("%d",&N);
	for (i=1; i<=N; i++)
	{   
		scanf("%d %d %d",&r,&g,&b);
		arr[i][0] = min(2, arr[i-1][1]+r, arr[i-1][2]+r);
		arr[i][1] = min(2, arr[i-1][0]+g, arr[i-1][2]+g);
		arr[i][2] = min(2, arr[i-1][0]+b, arr[i-1][1]+b);
	}   
	printf("%d\n", min(3, arr[N][0], arr[N][1], arr[N][2]));
}

int min (int args, ...)
{
	va_list argptr;
	int min = 10000000;
	int temp;
	int i;
	va_start(argptr, args);
	for (i=0; i<args; i++)
	{   
		temp = va_arg(argptr, int);
		min = (min <= temp) ? min : temp;
	}   
	va_end(argptr);
	if (args < 2) return 0; // args error.
	return min;
}

