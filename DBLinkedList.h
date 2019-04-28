#pragma once
#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define True 1
#define False 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *next;
	struct _node *prev;
} Node;

typedef struct _DLinkedList 
{
	Node *head;
	Node *cur;
	int numOfData;
} List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);

int LFirst(List *plist, Data *data);
int LNext(List *plist, Data *data);
int LPrevious(List *plist, Data *data);

int LCount(List *plist);

#endif // !__DB_LINKED_LIST_H__
