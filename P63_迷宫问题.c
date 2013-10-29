/*************************************************************************
# Copyright:     1994-2013
# File Name:     P63_迷宫问题.c
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年10月28日 星期一 18时31分42秒
# History:       1.10.28搭好了基本框架
#				 2.将本文件成功上传到github
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N	1
#define EN	2
#define E	3
#define ES	4
#define S	5
#define WS	6
#define W	7
#define WN	8

#define LONG	50
#define ROW		14
#define COL		10
typedef	struct
{
	int save_point[][];					//保留点，在搜索过程中，如果
										//一个以上的未知路口，则次点
										//将作为保留点
	int rode[LONG][2];                  //记录了当前是第LONG步，二维位
	int step;							//置是rode[LONG][0],
	int	Dir[8]							//rodd[LONG][1]
}WAY,*WAYP;                             //记录当前能走的方向，
										//Dir[8]={1,2,3,0,5,0,7,8}
										//则代表ES和WS方向不通，当然
										//，当该区域还未进行搜索时
										//，八个方向初始化都
										//为0

WAYP Init_way()
{
	WAYP	s;
	s = (WAYP)malloc(sizeof(WAY));
	s->step = -1;
	return s;
}

int Go_ahead(WAYP s,int m, int n)
{
	if(s->step == LONG -1)
		return -1;
	else
	{
		s->step++;
		s->rode[s->step][0] = m;
		s->rode[s->step][1] = n;
		return 1;
	}

}

int Back_up(WAYP s)
{
	if(s->step ==-1)
		return -1;
	else
	{
		s->rode[s->step][0] = 0;
		s->rode[s->step][1] = 0;
		s->step--;
		return 1;
	}
}

void Show_way(WAYP s)
{
	if(s->step == -1)
		return -1;
	else
	{
		while(s->step > -1)
		{
			printf("%d %d,",s->rode[s->step][0],s->rode[s->step][1]);
			s->step--;
		}
		return 1;
	}
}

void Search_way(WAYP s,*maze[])
{

	while(s->rode[s->step][0] != (ROW-2) && s->rode[s-step][1] 
			!= (COL-2))
	{
		if(maze[s->rode[s->step][0] - 1][s->rode[s->step][1]] == 1)
			s->Dir[0] = N;
		if(maze[s->rode[s->step][0] - 1][s->rode[s->step][1] + 1] == 1)
			s->Dir[1] = EN;
		if(maze[s->rode[s->step][0]][s->rode[s->step][1] + 1] == 1)
			s->Dir[2] = E;
		if(maze[s->rode[s->step][0] + 1][s->rode[s->step][1] + 1] == 1)
			s->Dir[3] = ES;
		if(maze[s->rode[s->step][0] + 1][s->rode[s->step][1]] == 1)
			s->Dir[4] = S;
		if(maze[s->rode[s->step][0] + 1][s->rode[s->step][1] - 1] == 1)
			s->Dir[5] = WS;
		if(maze[s->rode[s->step][0]][s->rode[s->step][1] - 1] == 1)
			s->Dir[6] = W;
		if(maze[s->rode[s->step][0] - 1][s->rode[s->step][1] - 1] == 1)
			s->Dir[7] = WN;
	}
}

int main(void)
{
	int maze[ROW][COL] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,0,0},
		{0,0,1,1,1,1,1,1,0,0},
		{0,0,0,1,0,0,0,0,0,0},
		{0,0,1,0,1,0,1,1,0,0},
		{0,0,1,0,0,1,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0},
		{0,0,1,1,1,1,0,1,0,0},
		{0,0,1,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,1,0},
		{0,0,0,0,0,0,0,0,0,0},
	};



	return 0;
}
