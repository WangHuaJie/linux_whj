/*************************************************************************
# Copyright:     1994-
# File Name:     file.h
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年11月25日 星期一 21时20分57秒
# History:
 ************************************************************************/

#define Datatype char

/*
 *定义节点的结构体
 */
typedef struct Node
{
	Datatype data;
	struct Node *Lc;
	struct Node *Rc;
}Bitnode, *Bitree;

/*
 *建立满二叉树，层数为floors
 */
void
Build_Full_Bintree(Bitree Root, int floors);
/*
 *将上一函数建立的满二叉树返回
 */
Bitree
Build_Full_Bintree(int floors);

/*
 *初始化二叉树
 */
void
Init_tree_data(Bitree Root);

/*
 *遍历一个节点
 */
void
Visit(Bitree Root);

/*
 *先序遍历二叉树
 */
void
Preorder(Bitree Root);

/*
 *中序遍历二叉树
 */
Inorder(Bitree Root);

/*
 *后续遍历二叉树
 */
Postorder(Bitree Root);

