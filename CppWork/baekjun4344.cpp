// baekjoon problem / 4344 
// 평균은 넘겠지

#include <stdio.h>
#include <stdlib.h>

int main(int argc, int *argv[])
{
	int c = 0;
	scanf("%d", &c);
	int *n = NULL;
	for (int i = 0; i < c; i++)
	{
		int sizeInput = 0;
		double sum = 0;
		int *nTmp = NULL;
		double nPosition = 0;
		scanf("%d", &sizeInput);
		nTmp = (int*)malloc(sizeof(int)*sizeInput);
		for (int j = 0; j < sizeInput; j++)
		{
			scanf("%d", &nTmp[j]);
			sum += nTmp[j];
		}
		for (int j = 0; j < sizeInput; j++)
		{
			if (sum/sizeInput < nTmp[j]) nPosition++;
		}

		printf("%.3f%%\n",(float)nPosition/(float)sizeInput*100);
		free(nTmp);
	}
	
	return 0;
}