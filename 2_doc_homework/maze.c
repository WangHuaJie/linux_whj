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
