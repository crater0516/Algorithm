#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
	void *buffer[100];
	int top;
} StackStruct;

void push (StackStruct *st, void *data);
void *pop (StackStruct *st);
int getTop (StackStruct *st);

int main ()
{
	int T,i,j,k;
	int count = 1, result = 0;
	char string[100] = "";
	StackStruct st = {0, };
	StackStruct *stptr = &st;
	scanf("%d",&T);
	for (i=0; i<T; i++)
	{
		scanf("%s",string);
		for (j=0; j<=strlen(string); j++)
		{
			if (string[j] == 'O')
				push (stptr, (int *)1);
			else if (string[j] == 'X' || string[j] == '\0')
			{
				while (pop(stptr) != NULL) result += count++;
				count = 1;
			}
		}
		printf("%d\n",result);
		string[0] = '\0';
		count = 1;
		result = 0;
	}
}

void push(StackStruct *st, void *data)
{
	if (st->top < 100) st->buffer[st->top++] = data;
	else exit(-1);
}

void *pop(StackStruct *st)
{
	if (st->top > 0) return st->buffer[--st->top];
	else return NULL;
}

int getTop(StackStruct *st)
{
	return st->top;
}
