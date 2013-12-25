/*************************************************************************
# Copyright:     1994-
# File Name:     file.h
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年11月25日 星期一 21时20分57秒
# History:
 ************************************************************************/

/*
 *
 */
#define Datatype char

/*
 *定义节点的结构体
 */
typedef struct Node
{
	Datatype data;
	struct Node *Lc;
	struct Node *Rc;
    int Lt,
        Rt;
}Bitree;

/*
 *建立满二叉树，层数为floors
 */
void
Build_Full_Bintree(Bitree *Root, int floors);
/*
 *将上一函数建立的满二叉树返回
 */
Bitree *
Build_Full_Bintree1(int floors);

/*
 *初始化二叉树
 */
void
Init_tree_data(Bitree *Root);

/*
 *遍历一个节点
 */
void
Visit(Bitree *Root);

/*
 *先序遍历二叉树
 */
void
Preorder(Bitree *Root);

void
Preorder1(Bitree *Root);

/*
 *中序遍历二叉树
 */
void
Inorder(Bitree *Root);

/*
 *后续遍历二叉树
 */
void
Postorder(Bitree *Root);

/*
 *获取满二叉树层数
 */
int 
Get_Bintree_floors(void);

/*
 * ***********************************************************
 */

/*
 *
 */
#define BINSTACK_MAXSIZE 1024

/*
 *定义二叉树节点栈结构体
 */
typedef	struct
{
	/*
	 *定义二叉树节点指针数组
	 */
	Bitree	binode_pointer[BINSTACK_MAXSIZE];
	int binstack_top;
}Binstack;

/*
 *初始化二叉树节点指针栈
 */
Binstack *
Init_Binstack(void);

/*
 *判断二叉树节点指针栈空
 */
int 
Binstack_Isempty(Binstack *s);

/*
 *入栈
 */
int
Binstack_Push(Binstack *s, Bitree node);

/*
 *出栈
 */
int 
Binstack_Pop(Binstack *s,Bitree *x);

/*
 * ***********************************************************
 */

/*
 *
 */
void
Unrecursive_Preorder(Bitree root);

/*
 *
 */
void 
Unrecursive_Inorder(Bitree root);

/*
 *
 */
void
Unrecursive_Postorder(Bitree root);

/*
 * *************************************************************
 */

/*
 *
 */
#define BINQUEUE_MAXSIZE 1024

/* 
 *定义二叉树节点的队结构体
 */
typedef	struct
{
	Bitree binode_pointer[BINQUEUE_MAXSIZE];
	int front,
		rear;
}Binqueue;

/*
 *初始化队
 */
Binqueue *
Init_Binqueue(void);

/*
 *判队空
 */
int
Binqueue_Isempty(Binqueue *s);

/*
 *入队
 */
int 
Binqueue_Push(Binqueue *s, Bitree node);

/*
 *出队
 */
int
Binqueue_Pop(Binqueue *s,Bitree *x);

/*
 *
 */
void
Levelorder(Bitree root);
