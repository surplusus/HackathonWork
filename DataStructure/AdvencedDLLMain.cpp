#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "AdvencedDLL.h"

int main()
{
	List list;
	int data = 0;
	ListInit(&list);

	while (true)
	{
		printf("데이터 입력(-1은 종료) :");
		scanf("%d", &data);
		if (data == -1) break;
		LInsert(&list, data);
	}

	if (LFirst(&list, &data)&&data%3==0)
		printf("%d\t", data);
	while (LNext(&list, &data))
	{
		if(data%3 ==0)
			printf("%d\t", data);
	}

	return 0;
}