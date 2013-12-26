/*************************************************************************
        > File Name: inthread.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Wed 25 Dec 2013 06:07:45 PM CST
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
