#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_QUEUE_SIZE = 10001;

struct Queue
{
	int buf[10001];
	int fr, ba;
	int size;
};

void push (struct Queue *qu, int data);
int pop (struct Queue *qu);
int size (struct Queue *qu);
int empty (struct Queue *qu);
int front (struct Queue *qu);
int back (struct Queue *qu);

int main ()
{
	struct Queue qu = {0, };
	struct Queue *quptr = &qu;
	const char *command[6] = {"push", "pop", "size", "empty", "front", "back"};
	char cmd[5] = "";
	int N, i;
	int data;
	scanf("%d",&N);
	for (i=0; i<N; i++)
	{
		scanf("%s",cmd);
		if (!strcmp(cmd, command[0])) // push
		{
			scanf("%d", &data);
			push(quptr, data);
		}
		else if (!strcmp(cmd, command[1])) // pop
			printf("%d\n", pop(quptr));
		else if (!strcmp(cmd, command[2])) // size
			printf("%d\n", size(quptr));
		else if (!strcmp(cmd, command[3])) // empty
			printf("%d\n", empty(quptr));
		else if (!strcmp(cmd, command[4])) // front
			printf("%d\n", front(quptr));
		else if (!strcmp(cmd, command[5])) // back
			printf("%d\n", back(quptr));
		cmd[0] = '\0';
	}
}

void push (struct Queue *qu, int data)
{
	if (qu->size < MAX_QUEUE_SIZE)
	{
		qu->buf[qu->ba] = data;
		qu->size ++;
		if (qu->ba == MAX_QUEUE_SIZE-1) qu->ba = 0;
		else qu->ba ++;
	}
	else exit(-1);
}

int pop (struct Queue *qu)
{
	int tmp = qu->buf[qu->fr];
	if (qu->size > 0)
	{
		if (qu->fr == MAX_QUEUE_SIZE-1) qu->fr = 0;
		else qu->fr ++;
		qu->size --;
		return tmp;
	}
	else return -1;
}

int size (struct Queue *qu)
{
	return qu->size;
}

int empty (struct Queue *qu)
{
	if (qu->size > 0) return 0;
	else return 1;
}

int front (struct Queue *qu)
{
	if (qu->size == 0) return -1;
	else return qu->buf[qu->fr];
}

int back (struct Queue *qu)
{
	if (qu->size == 0) return -1;
	else return qu->buf[qu->ba-1];
}
