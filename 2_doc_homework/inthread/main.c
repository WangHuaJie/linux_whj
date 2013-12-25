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
#include<stdlib.h>
#include"file.h"

Bitree *pre = NULL;

int
main(void)
{
	Bitree *Root;
	Root = Build_Full_Bintree1(Get_Bintree_floors());
	Init_tree_data(Root);
/*    pre = (Bitree *)malloc(sizeof(Bitree));
    pre->Lc = NULL;
    pre->Rc = NULL;
    pre->Lt = 0;
    pre->Rt = 0;
*/
	Preorder(Root);
	printf("\n");
    Preorder1(Root);
    printf("\n");

	return 0;
}
