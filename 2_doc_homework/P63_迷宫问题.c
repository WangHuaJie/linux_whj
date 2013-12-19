/*************************************************************************
# Copyright:     1994-
# File Name:     P63_迷宫问题.c
# Description:
# Author:        WangHuaJie
# Version:
# Date:          2013年10月28日 星期一 18时31分42秒
# History:       1.10.28搭好了基本框架
#				 2.上传代码到了github上
#				 3.进一步修改数据结构模式，以便于数据的传输
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

#define N_open maze[s->rode[s->step][0]-1][s->rode[s->step][1]]==1 
#define EN_open maze[s->rode[s->step][0]-1][s->rode[s->step][1]+1]==1 
#define E_open maze[s->rode[s->step][0]][s->rode[s->step][1]+1]==1
#define ES_open maze[s->rode[s->step][0]+1][s->rode[s->step][1]+1]== 1
#define S_open maze[s->rode[s->step][0]+1][s->rode[s->step][1]]==1 
#define WS_open (maze[s->rode[s->step][0] + 1][s->rode[s->step][1] - 1] == 1) 
#define W_open (maze[s->rode[s->step][0]][s->rode[s->step][1] - 1] == 1) 
#define WN_open (maze[s->rode[s->step][0] - 1][s->rode[s->step][1] - 1] == 1) 

typedef	struct
{
//	int save_point[][];					//保留点，在搜索过程中，如果
										//一个以上的未知路口，则次点
										//将作为保留点
	int rode[LONG][2];                  //记录了当前是第LONG步，二维位
	int step;							//置是rode[LONG][0],
//	int	Dir[8];							//rodd[LONG][1]
}WAY,*WAYP;                             //记录当前能走的方向，
										//Dir[8]={1,2,3,0,5,0,7,8}
										//则代表ES和WS方向不通，当然
										//，当该区域还未进行搜索时
										//，八个方向初始化都
										//为0

WAYP Init_way(void)
{
	WAYP	s;
	s = (WAYP)malloc(sizeof(WAY));
	s->step = -1;
	return s;
}

int** Go_ahead(WAYP s,int** maze ,int r,int c,int Dir)
{
	s->step++;

	if(s->step == LONG -1)
	{
		printf("stack is full !\n");
		return NULL;
	}
	else
	{
		if(Dir == 1)
		{
			s->rode[step][0] = r - 1;
			s->rode[step][1] = c;
			return &maze[r-1][c];
		}
		else if(Dir == 2)
		{
			s->rode[step][0] = r - 1;
			s->rode[step][1] = c + 1;
			return &maze[r-1][c+1];
		}
		else if(Dir == 3)
		{
			s->rode[step][0] = r;
			s->rode[step][1] = c + 1;
			return &maze[r][c+1];
		}
		else if(Dir == 4)
		{
			s->rode[step][0] = r + 1;
			s->rode[step][1] = c + 1;
			return &maze[r+1][c+1];
		}
		else if(Dir == 5)
		{
			s->rode[step][0] = r + 1;
			s->rode[step][1] = c;
			return &maze[r+1][c];
		}
		else if(Dir == 6)
		{
			s->rode[step][0] = r + 1;
			s->rode[step][1] = c - 1;
			return &maze[r+1][c-1];
		}
		else if(Dir == 7)
		{
			s->rode[step][0] = r;
			s->rode[step][1] = c - 1;
			return &maze[r][c-1];
		}
		else if(Dir == 8)
		{
			s->rode[step][0] = r - 1;
			s->rode[step][1] = c - 1;
			return &maze[r-1][c-1];
		}
		else
			return NULL;
	}

}

/*
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
*/

int  Show_way(WAYP s)
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

WAYP Search_way(WAYP s,int** maz)
{
	int r,
		c;
	r = (maz - maze) / (sizeof(int)*ROW) + 1;
	c = (maz - maze) % (sizeof(int)*ROW) + 1;

	while(s->rode[s->step][0] != (ROW-2) && s->rode[s->step][1] 
			!= (COL-2))
	{
		if(N_open)
			Search_way(s,Go_ahead(s,maze[r][c],N));
		else if(EN_open)
			Search_way(s,Go_ahead(s,maze[r][c],EN));
		else if(E_open)
			Search_way(s,Go_ahead(s,maze[r][c],E));
		else if(ES_open)
			Search_way(s,Go_ahead(s,maze[r][c],ES));
		else if(S_open)
			Search_way(s,Go_ahead(s,maze[r][c],S));
		else if(WS_open)
			Search_way(s,Go_ahead(s,maze[r][c],WS));
		else if(W_open)
			Search_way(s,Go_ahead(s,maze[r][c],W));
		else if(WN_open)
			Search_way(s,Go_ahead(s,maze[r][c],WN));
	}
	return s;
	
}

int main(void)
{
	extern static int maze[ROW][COL] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,1,1,1,0,0,0},
		{0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,1,0,0},
		{0,0,1,0,0,1,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,1,1,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,1,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	
	WAYP s = Init_way();
	Search_way(s,maze[1][1]);
	Show_way(s);

	return 0;
}
