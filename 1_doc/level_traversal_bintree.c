/*************************************************************************
# Copyright:     1994-
# File Name:     level_traversal_bintree.c
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年11月27日 星期三 19时56分03秒
# History:
 ************************************************************************/

#include"file.h"
#include<stdio.h>

void
Levelorder(Bitree root)
{
	printf("Levelorder: ");
	Binqueue *s;
	Bitree p,
		   *q;
	s = Init_Binqueue();
	Binqueue_Push(s,root);
	while(!Binqueue_Isempty(s))
	{
		Binqueue_Pop(s,q);
		p = *q;
		Visit(p);
		if(p->Lc != NULL)
		{
			Binqueue_Push(s,p->Lc);
		}
		if(p->Rc != NULL)
		{
			Binqueue_Push(s,p->Rc);
		}
	}
	printf("\n");
}
