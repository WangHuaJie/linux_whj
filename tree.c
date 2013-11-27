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
#define Datatype char

typedef struct Node
{
	Datatype data;
	struct Node *Lc;
	struct Node *Rc;
}Bitnode, *Bitree;

/*
 * 用来存储分支的条数
 */
int number = 0;

char character = 'a';

/*
 * 建立空二叉树
 */
void
Build_Full_Bintree(Bitree Root,int floors)
{
	Bitree Root1,
		   Root2;
	
	if(floors > 0)
	{
		Root1 = (Bitree)malloc(sizeof(Bitnode)),
		Root2 = (Bitree)malloc(sizeof(Bitnode));
		Root1->Lc = NULL;
		Root2->Rc = NULL;

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
Bitree
Build_Full_Bintree1(int floors)
{
	Bitree Root;
	Root = (Bitree)malloc(sizeof(Bitnode));
	Root->Lc = NULL;
	Root->Rc = NULL;

	Build_Full_Bintree(Root, floors);

	return Root;
}

/*
 *初始化二叉树数据
 */
void
Init_tree_data(Bitree Root)
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
Visit(Bitree Root)
{
	printf("%c",Root->data);
	return;
}

/*
 * 先序遍历二叉树
 */
void
Preorder(Bitree Root)
{
	if(Root)
	{
		Visit(Root);
		Preorder(Root->Lc);
		Preorder(Root->Rc);
	}
	return;
}

/*
 *中序遍历二叉树
 */
void
Inorder(Bitree Root)
{
	if(Root)
	{
		Inorder(Root->Lc);
		Visit(Root);
		Inorder(Root->Rc);
	}
	return;
}

/*
 *后序遍历二叉树
 */
void
Postorder(Bitree Root)
{
	if(Root)
	{
		Postorder(Root->Lc);
		Postorder(Root->Rc);
		Visit(Root);
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

