/*************************************************************************
        > File Name: main.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Mon 09 Dec 2013 09:11:15 AM CST
        题目：邻接多重表的建立
　　邻接多重表的存储结构和十字链表类似，也是由顶点和边表
　　组成，每一条边用一个节点表示。其中顶点由两个域组成，
　　vertex 域存储和该顶点的信息相关的信息，firstedge域指
　　示第一条依附于该顶点的边；边表结点由六个域组成，mark
　　,ivex,ilink,jvex,link,info域，mark为标识域，ivex和jvex
　　为该边依附的两个顶点在图中的位置，link指向下一条依附
　　于该顶点ivex的边，jlink指向下一条依附于顶点jvex的边
　　info为指向和边相关的各种信息的指针域。
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"map.h"

int 
main(void)
{
    AdjMultipleList *G;
    G = (AdjMultipleList *)malloc(sizeof(AdjMultipleList));

    Build(G);
    Show(G);
    return 0;
}
