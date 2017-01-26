#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertNode (char item);
void freeList ();
int searchList (char target);

typedef struct Node
{
	char item;
	struct Node *next;
}NodeStruct;

NodeStruct *g_pHead = NULL; // First Node
NodeStruct *g_pTail = NULL; // Last Node

int main ()
{
	int N,i,j;
	int tmp = 0;
	int result = 0;
	char string[100];
	scanf("%d",&N);
	for (i=0; i<N; i++)
	{
		scanf("%s",string);
		tmp = strlen(string)-1;
		if (tmp == 0)
		{
			result ++;
			continue;
		}
		for (j=1; j<=tmp; j++)
		{
			if (string[j] != string[j-1])
			{
				if (!searchList (string[j])) // there is no duplication.
					insertNode(string[j-1]);
				else
					break;
			}
			if (j == tmp) result++;
		}
		string[0] = '\0';
		freeList();
	}
	printf ("%d\n", result);
	return 0;
}

void insertNode (char item)
{
	NodeStruct *pNewNode;
	// Create new Node
	pNewNode = (NodeStruct*) malloc(sizeof(NodeStruct));
	pNewNode->item = item;
	pNewNode->next = NULL;
	if (g_pHead == NULL) // new Node is first
		g_pHead = pNewNode;
	else // not First Node
		g_pTail->next = pNewNode;
	g_pTail = pNewNode; // Last Node is new Node.
}

void freeList ()
{
	NodeStruct *pTempNode;
	while (g_pHead != NULL)
	{
		pTempNode = g_pHead;
		g_pHead = pTempNode->next;
		free(pTempNode);
	}
}

int searchList (char target)
{
	NodeStruct *pTempNode = g_pHead;
	if (pTempNode == NULL) return 0;
	do
	{
		if (target == pTempNode->item) return 1; // target detection.
		pTempNode = pTempNode->next;
	} while (pTempNode != NULL);
	return 0;
}
