/*
	题目：迷宫路径搜索问题
　　以一个二位数组作为迷宫的载体，‘0’代表不通，‘1’代表通路，
　　运用递归个标记的思想，每前进一步，标记为‘2’，表示已走过，
　　下一步，顺时针按上、右、下、左顺序递归搜索四个方向，向
　　标记为‘1’的方向前进一步，接着继续递归搜索，直至找到终点
　　位置为止。
*/
#include<stdio.h>

#define ROW 10
#define COLUMN 10

int Maze[ROW][COLUMN] = {
		{1,1,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,1,1,1,0,0,0},
		{0,0,1,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
};

void
Search(int maze[][COLUMN],int row,int column)
{
    maze[row][column] = 2;

    if((row - 1) > -1){
		if(maze[row-1][column] == 1){
			printf(" %d,%d ",--row,column);
			Search(maze,row,column);
		}
	}
	if((column + 1) < ROW){
		if((column+1 == COLUMN - 1) && (row == ROW - 1)){
			if(maze[row][column+1] == 1){
				printf(" %d,%d ",row,++column);
				printf("You find the way out !\n");
				return;
			}
		}
		else if(maze[row][column+1] == 1)
        {
            
			printf(" %d,%d ",row,++column);
			Search(maze,row,column);
        }
	}
	if((row + 1) < COLUMN){
		if((column == COLUMN - 1) && (row+1 == ROW - 1)){
			if(maze[row+1][column] == 1){
				printf(" %d,%d ",++row,column);
				printf("You find the way out !\n");
				return;
			}
		}
		else if(maze[row+1][column] == 1)
        {
			printf(" %d,%d ",++row,column);
			Search(maze,row,column);
		}
	}
	if((column - 1) > -1){
		if(maze[row][column-1] == 1){
			printf(" %d,%d ",row,--column);
			Search(maze,row,column);
		}
	}
	
		return;
}

int 
main(void)
{
	Search(Maze,0,0);
	return 0;
}
