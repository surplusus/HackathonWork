#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdvencedDLL.h"

void ListInit(List *plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	plist->head = newNode;
	newNode->prev = NULL;

	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->head == NULL)
		return False;
	
	plist->cur = plist->head;

	*pdata = plist->cur->data;
	return true;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->head == NULL)
		return False;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return True;
}

int LPrevious(List *plist, Data *pdata)
{
	if (plist->head == NULL)
		return false;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return true;
}