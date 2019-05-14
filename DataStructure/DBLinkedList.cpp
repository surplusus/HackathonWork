#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;
	
	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->head == NULL)
		return False;

	plist->cur = plist->head;	// 처음엔 머리를 가리킨다

	*pdata = plist->cur->data;
	
	return True;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->cur->next == NULL)
		return False;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return True;
}

int LPrevious(List *plist, Data *pdata)
{
	if (plist->cur->prev == NULL)
		return false;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return True;
}

int LCount(List *plist)
{
	return plist->numOfData;
}