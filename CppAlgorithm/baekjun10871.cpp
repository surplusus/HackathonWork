// baekjoon problem / 10871
// X보다 작은 수

#include <stdio.h>

int main()
{
    int n = 0, x=0;
    scanf("%d %d", &n, &x);
    const int n1 = n;
    int inputSample[] = {1,10,4,9,2,3,8,5,7,6};
    int *pInput = NULL;
    for (int i = 0; i < x; i++)
    {
        if (inputSample[i] < x)
            printf("%d ", inputSample[i]);
    }
    
    return 0;
}