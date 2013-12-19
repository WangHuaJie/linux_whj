/*************************************************************************
# Copyright:     1994-
# File Name:     binstack.c
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年11月26日 星期二 18时28分13秒
# History:
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include"file.h"

/*
 *初始化二叉树节点指针栈
 */
Binstack *
Init_Binstack(void)
{
//	printf("1\n");

	Binstack *S;
	S = (Binstack *)malloc(sizeof(Binstack));
	S->binstack_top = -1;
	return S;
}

/*
 *判栈空
 */
int
Binstack_Isempty(Binstack *s)
{
//	printf("2\n");

	if (s->binstack_top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 *入栈
 */
int
Binstack_Push(Binstack *s,Bitree node)
{
//	printf("3\n");

	if(s->binstack_top == BINSTACK_MAXSIZE -1)
	{
		return 0;
	}
	else
	{
		s->binstack_top++;
		s->binode_pointer[s->binstack_top] = node;
		return 1;
	}
}

/*
 *出栈
 */
int
Binstack_Pop(Binstack *s,Bitree *x)
{
//	printf("4\n");

	if(s->binstack_top == -1)
	{
		return -1;
	}
	else
	{
		*x = s->binode_pointer[s->binstack_top];
		s->binstack_top--;
		return 1;
	}
}

