/*************************************************************************
# Copyright:     1994-
# File Name:     binqueue.c
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年11月27日 星期三 19时09分18秒
# History:
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"file.h"

/*
 *初始化队
 */
Binqueue *
Init_Binqueue(void)
{
	Binqueue * s;
	s = (Binqueue *)malloc(sizeof(Binqueue));
	s->front = -1;
	s->rear = -1;
	return s;
}

/*
 *判队空
 */
int 
Binqueue_Isempty(Binqueue *s)
{
	if(s->front == s->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 *入队
 */
int 
Binqueue_Push(Binqueue *s,Bitree node)
{
	if(BINQUEUE_MAXSIZE == (s->front-s->rear+1))
	{
		return 0;
	}
	else
	{
		s->front++;
		s->binode_pointer[s->front] = node;
		return 1;
	}
}

/*
 * 出队
 */
int 
Binqueue_Pop(Binqueue *s, Bitree *x)
{
	if(Binqueue_Isempty(s))
	{
		printf("Binqueue is full!\n");
		return -1;
	}
	else
	{	
		s->rear++;
		*x = s->binode_pointer[s->rear];
		return 1;
	}

}
