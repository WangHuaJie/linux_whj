/*************************************************************************
# Copyright:     1994-
# File Name:     P163_4_1.c
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年11月25日 星期一 19时06分34秒
# History:
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#define Datatype char

/*
 * 用来存储分支的条数
 */
int number = 0;

char character = 'a';
extern Bitree *pre;
/*
 * 建立空二叉树
 */
void
Build_Full_Bintree(Bitree *Root,int floors)
{
	Bitree *Root1,
		   *Root2;
	
	if(floors > 0)
	{
		Root1 = (Bitree*)malloc(sizeof(Bitree)),
		Root2 = (Bitree*)malloc(sizeof(Bitree));
		Root1->Lc = NULL;
        Root1->Lt = 0;
		Root2->Rc = NULL;
        Root2->Rt = 0;

		/*
		 * 初始化二叉树数据
		 */
		Root->data = '0';
		floors--;
		Build_Full_Bintree(Root->Lc = Root1, floors);
		printf("%d\n",++number);
		Build_Full_Bintree(Root->Rc = Root2, floors);
		printf("%d\n",++number);
		
	}
	return ;
}
/*
 *
 */
Bitree *
Build_Full_Bintree1(int floors)
{
	Bitree *Root;
	Root = (Bitree*)malloc(sizeof(Bitree));
	Root->Lc = NULL;
	Root->Rc = NULL;

	Build_Full_Bintree(Root, floors);

	return Root;
}

/*
 *初始化二叉树数据
 */
void
Init_tree_data(Bitree *Root)
{
	if(Root->Lc && Root->Rc)
	{
		Root->data = character++;
		Init_tree_data(Root->Lc);
		Init_tree_data(Root->Rc);
	}
	return;
}

/*
 * 遍历一个节点
 */
void
Visit(Bitree *Root)
{
	printf("%c",Root->data);
	return;
}

/*
 * 先序遍历二叉树
 */
void
Preorder(Bitree *Root)
{
	if(Root != NULL)
	{
        if(Root->Lc == NULL){
            Root->Lc = pre;
            Root->Lt = 1;
        }
        if(Root->Rc == NULL)
            Root->Rt = 1;
        if(pre != NULL && pre->Rt == 1){
            pre->Rc = Root;
        }
        pre = Root;
		Preorder(Root->Lc);
		Preorder(Root->Rc);
	}
	return;
}

void
Preorder1(Bitree *Root)
{
    while(Root->Rc != NULL){
        if(Root->Lc != NULL){
            Visit(Root);
            Root = Root->Lc;
        }
        else{
            Visit(Root);
            Root = Root->Rc;
        }
    }
    return;
}

/*
 *
 */
int 
Get_Bintree_floors(void)
{
	int floors;
	scanf("%d",&floors);
	if(floors >= 1)
		return floors;
	else 
	{
		printf("Input error!\n");
		exit(0);
	}
}

