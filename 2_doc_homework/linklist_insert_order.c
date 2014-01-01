/*************************************************************************
        > File Name: linklist_insert_order.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Wed 25 Dec 2013 12:43:48 PM CST
        题目：链表的插入排序
　　假设有一个无序的带头结点的单链表L，首先将表头置空，然后用指针p循环单链
　　表，每一次循环，将p所指的结点插入到L中合适的位置，这个合适的位置是指第
　　一个大于p->data的指针q的前面或者表的最后（此时此值最大）。
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *head = NULL;

void
insert_link(Node *p)
{
    Node *q = head;
    while(1)
    {
        if( head->data == -32768){
            head = p;
            break;
        }
        if(p->data < q->data){
            p->next = q;
            head = p;
            break;
        }

        if(p->data > q->data && q->next == NULL){
            q->next = p;
            break;
        }
        if(p->data > q->data && p->data < q->next->data){
            p->next = q->next;
            q->next = p;
            break;
        }
        q = q->next;
    }
    return;
}

void
Build_sort()
{
    Node *p = NULL;
    int num = 1,
        a;
    
    while(1)
    {
        printf("Please input the %d number:\n",num);
        scanf("%d",&a);
        if(404 == a)
            break;
        p = (Node*)malloc(sizeof(Node));
        p->data = a;
        p->next = NULL;
        insert_link(p);
        num++;
    }

    return;
}

void
Show(Node *head)
{
    Node *p = head;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");

    return;
}


int
main(void)
{
    head = (Node*)malloc(sizeof(Node));
    head->data = -32768;
    head->next = NULL;

    Build_sort();
    Show(head);

    return 0;
}

