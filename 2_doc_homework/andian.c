#include<stdio.h>
#define M 3
#define N 3

//每行都会有一个或多个相同的最小值，找到后，存入b【n】
//每列也会有一个或多个相同的最大值，找到后，存入c【m]

int main(void)
{
	int a[M][N] = {
		{1,1,1},
		{1,1,1},
		{1,1,1}
	};

	int b[M],
		c[N];
	int i,j,k = 0;

	for(i = 0; i < M; i++)
	{
		k = a[i][0];
		for(j = 1; j < N; j++)
		{
			if(k > a[i][j])
				k = a[i][j];
		}
		b[i] = k;
	}

	for(i = 0;i < N; i++)
	{
		k = a[0][i];
		for(j = 1; j < M; j++)
		{
			if(k < a[j][i])
				k = a[j][i];
		}
		c[i] = k;
	}

	for(i = 0; i < M; i++)
		printf("第%d行中最小的是:%d\n",i,b[i]);
	for(i = 0; i < N; i++)
		printf("第%d列中最大的是:%d\n",i,c[i]);
	
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
		{
			if(a[i][j] == b[i] && a[i][j] == c[j])
				printf("a[%d][%d] is a andian point!\n",i,j);
		}

	scanf("%d",&k);
	return 0;
}