/*************************************************************************
# Copyright:     1994-
# File Name:     unrecursive_traversal_bintree.c
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年11月26日 星期二 20时20分44秒
# History:
 ************************************************************************/

#include"file.h"
#include<stdio.h>

/*
 *
 */
void
Unrecursive_Preorder(Bitree root)
{
	Binstack *s;
	Bitree p,
		   *q;
	s = Init_Binstack();
	p = root;
	while(p != NULL || !Binstack_Isempty(s))
	{
		while(p != NULL)
		{
			Visit(p);
			Binstack_Push(s,p);
			p = p->Lc;
		}
		if( !Binstack_Isempty(s))
		{
			Binstack_Pop(s,q);
			p = *q;
			p = p->Rc;
		}
	}
	printf("\n");
}

/*
 *
 */
void
Unrecursive_Inorder(Bitree root)
{
	Binstack *s;
	Bitree p,
		   *q;
	s = Init_Binstack();
	p = root;
	while(p != NULL || !Binstack_Isempty(s))
	{
		while(p != NULL)
		{
			Binstack_Push(s,p);
			p = p->Lc;
		}
		if( !Binstack_Isempty(s))
		{
			Binstack_Pop(s,q);
			p = *q;
			Visit(p);
			p = p->Rc;
		}
		
	}
	printf("\n");
}

/*
 *
 */
void
Unrecursive_Postorder(Bitree root)
{

}
