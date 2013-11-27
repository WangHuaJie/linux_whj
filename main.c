/*************************************************************************
# Copyright:     1994-
# File Name:     main.c
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年11月26日 星期二 19时46分45秒
# History:
 ************************************************************************/

#include<stdio.h>
#include"file.h"

int
main(void)
{
	Bitree Root;
	Root = Build_Full_Bintree1(Get_Bintree_floors());
	Init_tree_data(Root);
	Preorder(Root);
	printf("\n");
	Inorder(Root);
	printf("\n");
	Postorder(Root);
	printf("\n");
	Unrecursive_Preorder(Root);
	Unrecursive_Inorder(Root);
	Unrecursive_Postorder(Root);

	return 0;
}
