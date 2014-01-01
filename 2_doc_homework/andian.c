/*
题目:搜索马鞍点问题
　　先遍历整个二位数组，找出每行中最小的元素存入a[],再找出每列最大的元素，
　　存入b[],然后在对a[],b[]两数组进行遍历比较，即可找出马鞍点。
*/

#include<stdio.h>
#define M 3
#define N 3

//ÿ�ж�����һ����������ͬ����Сֵ���ҵ��󣬴���b��n��
//ÿ��Ҳ����һ����������ͬ������ֵ���ҵ��󣬴���c��m]

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
		printf("��%d������С����:%d\n",i,b[i]);
	for(i = 0; i < N; i++)
		printf("��%d������������:%d\n",i,c[i]);
	
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
		{
			if(a[i][j] == b[i] && a[i][j] == c[j])
				printf("a[%d][%d] is a andian point!\n",i,j);
		}

	scanf("%d",&k);
	return 0;
}
