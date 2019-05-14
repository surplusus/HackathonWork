#include <stdio.h>
#include "DBLinkedList.h"

int main()
{
	// ����� ���� ����Ʈ ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// 8�� ������ ����
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 8); LInsert(&list, 9);
	LInsert(&list, 6); LInsert(&list, 5);

	// ����� ������ ��ȸ
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// ������ ���� �̵��ϸ� ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		// ���� ���� �̵��ϸ� ������ ��ȸ
		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}