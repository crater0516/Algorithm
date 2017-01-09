#include <stdio.h>
#include <string.h>

int main ()
{
    int n,i;
    int top = 0;
    int stack[10000] = {0,};
    char command[10] = "";
    char *strings[5] = {"push","pop","size","empty","top"};

    scanf("%d",&n);

    for (i=0; i<n; i++)
    {
	scanf("%s",command);
	if (strcmp(command,strings[0]) == 0) // push
	{
	    scanf("%d",&stack[top]);
	    top++;
	}
	else if (strcmp(command,strings[1]) == 0) // pop
	{
	    if (top == 0) printf("-1\n");
	    else printf("%d\n", stack[--top]);
	}
	else if (strcmp(command,strings[2]) == 0) // size
	{
	   printf("%d\n",top);
	}
	else if (strcmp(command,strings[3]) == 0) // empty
	{
	    if (top == 0) printf("1\n");
	    else printf("0\n");
	}
	else if (strcmp(command,strings[4]) == 0) // top
	{
	    if (top == 0) printf("-1\n");
	    else printf("%d\n", stack[top-1]);
	}
    }
}
