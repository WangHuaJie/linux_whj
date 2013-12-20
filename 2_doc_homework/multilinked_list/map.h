/*************************************************************************
        > File Name: map.h
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Mon 09 Dec 2013 08:50:35 AM CST
 ************************************************************************/
#include<string.h>
#define MAXVEX 20
//#define weight int
typedef struct ArcNode
{
    int mark,
        pvex,
        bvex;
    int distence,
        time,
        money;
    
    struct ArcNode *pvex_next,
                   *bvex_next;
}ArcNode;

//#define Datatype char
typedef struct VertexNode
{
    char name[20];
    int No;
    ArcNode *head;
}VertexNode;

typedef struct 
{
    VertexNode vertex[MAXVEX];
    int vexnum,
        arcnum;
}AdjMultipleList;

//function in Build.c**********************************
void
init_map(AdjMultipleList *G);

void
read_vex_data(AdjMultipleList *G);

int
cmp(const char *ch,AdjMultipleList *G);

void
init_arc(ArcNode *arc,int r1,int r2,const char *ch1,const char *ch2);

void
oversert(AdjMultipleList *G,ArcNode *arc,int no);

void
arc_insert(AdjMultipleList *G,ArcNode *arc);
void
arc_build(AdjMultipleList *G,int r1,int r2,const char *ch1,const char *ch2);

void
read_arc_data(AdjMultipleList *G);

void
Build(AdjMultipleList *G);

//functon in Show.c***********************************

void
vexallarc(AdjMultipleList *G,int i);

void
Show(AdjMultipleList *G);

//function in Dfserch.c******************************

void
get2places(char *ch1,char *ch2);

void
printwrong(const char *ch);

int
changeintono(AdjMultipleList *G,const char *ch1,const char *ch2);

void
copy(int *road,int *copyroad);

void
output(AdjMultipleList *G,int *road);

int 
overoad(int *road,int now);

void
addroad(int *road,int now);

void
overarc(AdjMultipleList *G,int *vexarray,int now);

void
recur(AdjMultipleList *G,int *road,int now,int end);

void
search(AdjMultipleList *G);

void
Dfsearch(AdjMultipleList *G);

//function in Mstprime.c **********************************************

void
getplace(char *ch);

int
cmp1(AdjMultipleList *G,char *ch);

void
printwrong1(char *ch);

void
init_vexarray(AdjMultipleList *G,int j,int *vexarray);

int 
cmp2(int *vexarray,int no);
/*
void
init_arc1(AdjMultipleList *G,int j,ArcNode *arc[]);
*/
void
ovexarray(AdjMultipleList *G,int *vexarray,ArcNode *arc[]);

void
mst(AdjMultipleList *G,char *ch,ArcNode *arc[]);

void
show_mst(AdjMultipleList *G,ArcNode *arc[]);

void
Mstprime(AdjMultipleList *G);
