/*************************************************************************
        > File Name: main.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Mon 09 Dec 2013 09:11:15 AM CST
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
