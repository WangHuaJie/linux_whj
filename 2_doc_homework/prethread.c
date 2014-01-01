/*************************************************************************
        > File Name: inthread.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Wed 25 Dec 2013 06:07:45 PM CST
        题目：建立先序遍历的线索二叉树
　　对二叉树的先序线索化，需对二叉树进行一次先序遍历，
　　在遍历过程中访问结点的操作是检查当前的左右指针域
　　是否为空，若为空，就将它们改为指向前驱结点或后继
　　节点的线索。为实现这一过程，设指针pre始终指向刚刚
　　访问的结点，即若指针p指向当前结点，则pre指向他的
　　前驱，以便设线索。

 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int Data = 1;

typedef struct node
{
    int data;
    struct node *Lc;
    struct node *Rc;
    int Lt,
        Rt;
}Node;

Node *pre;

Node *
init_node(void)
{
    Node *root = NULL;
    root = (Node*)malloc(sizeof(Node));
    root->data = 0;
    root->Lc = NULL;
    root->Rc = NULL;
    root->Lt = 0;
    root->Rt = 0;

    return root;
}


void
build(Node *root,int floor)
{
    Node *root1 = NULL,
         *root2 = NULL;

    if(floor-1){
        root1 = init_node();
        root2 = init_node();
        root->Lc = root1;
        root->Rc = root2;
        root->Lc->data = ++Data;
//        root->Rc->data = ++Data;
        floor--;

        build(root->Lc,floor);
        root->Rc->data = ++Data;
        build(root->Rc,floor);
    }
    return;
}

void
build_full_bitree(Node *root)
{
    int floor;

    printf("input the bitree's floor:\n");
    scanf("%d",&floor);        
    build(root,floor);

    return;
}

void
show(Node *root)
{
    if(root){
        printf("%d ",root->data);
        show(root->Lc);
        show(root->Rc);
    }
    return;
}

void
prethread(Node *root)
{
    if(root){
        if(!root->Lc){
            root->Lc = pre;
            root->Lt = 1;
        }
        if(!pre->Rc){
            pre->Rc = root;
            pre->Rt = 1;
        }
        pre = root;
        if(root->Lt == 0)
            prethread(root->Lc);
        if(root->Rt == 0)
            prethread(root->Rc);
    }
    return;
}

void
prethread_show(Node *root)
{
    Node *r = root;
    while(r->Rc){
            printf("%d ",r->data);
            if(r->Lt == 0)
                r = r->Lc;
            else
                r = r->Rc;
    }
    printf("%d ",r->data);
    printf("\n");
    return;
}

int 
main(void)
{
    Node *root = init_node();
    pre = init_node();
    root->data = Data;
    build_full_bitree(root);
    show(root);
    printf("\n");
    prethread(root);
    prethread_show(root);

    return 0;
}
