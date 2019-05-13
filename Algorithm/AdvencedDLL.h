#pragma once
#ifndef __ADVENCED_DOUBLY_LINKED_LIST_H__
#define __ADVENCED_DOUBLY_LINKED_LIST_H__

#define True 1
#define False 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *next;
	struct _node *prev;
} Node;

typedef struct _DoublyLinkedList
{
	Node *head;
	Node *cur;
	Node *prev;
	int numOfData;
} List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);
int LCount(List *plist);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
int LPrevious(List *plist, Data *pdata);

#endif // !__ADVENCED_DOUBLY_LINKED_LIST_H__
