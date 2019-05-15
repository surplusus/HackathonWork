#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 100
int top;
int stack[MAX_STACK_SIZE];

void Init()
{
	top = -1;
}
int pop()
{
	if (top == -1)
	{
		printf("stack_underflow\n");
		return 0;
	}
	return stack[(top)--];
}
void push(int item)
{
	if (top >= MAX_STACK_SIZE - 1)
		cout << "stack_overflow" << endl;

	stack[++top] = item;
}
void Search(int num)
{
	for (int i = 0; i < sizeof(stack); i++)
	{
		if (stack[i] == num)
		{
			cout << "값은 " << i << "인덱스에 있습니다." << endl;
			return;
		}
	}
}
void PrintAll()
{
	int tmp;
	while (tmp = pop())
	{
		cout << "value = " << tmp << endl;
	}
}
int main()
{
	Init();
	push(4);
	push(2);
	push(5);
	push(1);
	Search(2);
	PrintAll();

	return 0;
}