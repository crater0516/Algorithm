#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
	void *buffer[100];
	int top;
};

void push(struct Stack *st, void *data);
void *pop(struct Stack *st);
int getTop(struct Stack *st);

int main ()
{
	int T,i,j;
	char string[100] = "";
	struct Stack st = {0, };
	struct Stack *stptr = &st;
	scanf("%d",&T);
	for (i=0; i<T; i++)
	{
		scanf("%s",string);
		for (j=0; j<strlen(string); j++)
		{
			if (string[j] == '(') push(stptr, (char*)'(');
			else if (string[j] == ')')
			{
				if (pop(stptr) == NULL)
				{
					printf("NO\n");
					break;
				}
			}
			if (j == strlen(string) - 1)
				if (getTop(stptr) != 0) printf("NO\n");
				else printf("YES\n");
		}
		string[0] = '\0';
		st.top = 0;
	}
}

void push (struct Stack *st, void *data)
{
	if (st->top < 100)
		st->buffer[st->top++] = data;
	else exit(-1);
}

void *pop (struct Stack *st)
{
	if (st->top > 0)
		return st->buffer[--st->top];
	else
		return NULL;
}

int getTop (struct Stack *st)
{
	return st->top;
}

