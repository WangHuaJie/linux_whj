/*************************************************************************
        > File Name: horse.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Thu 19 Dec 2013 08:09:08 PM CST
 ************************************************************************/

#include<stdio.h>

#define ROW 8
#define COLUMN 8

/*
int chessboard[ROW][COLUMN] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
};
*/

int chessboard[ROW][COLUMN] = {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
};

void
get_start(int *rowp,int *columnp)
{
    printf("Please input the start point row:\n");
    scanf("%d",rowp);
    printf("And the start point column:\n");
    scanf("%d",columnp);
    return;
}

int
check_start(int *rowp,int *columnp)
{
    int row = *rowp,
        column = *columnp;

    if((row > -1)&&(row < ROW)&&(column > -1)&&(column < COLUMN))
        return 1;
    return -1;
}

void
over_board(int chessboard[][COLUMN],int row,int column)
{
    chessboard[row][column] = 1;

    if(((row-2)>-1)&&((column+1)<COLUMN)){
        if(chessboard[row-2][column+1] == 0){
            row -= 2;
            column += 1;
            printf("   %d,%d",row,column);
            over_board(chessboard,row,column);
            return;
        }
    }
    if(((row-1)>-1)&&((column+2)<COLUMN)){
        if(chessboard[row-1][column+2] == 0){
            row -= 1;
            column += 2;
            printf("   %d,%d",row,column);
            over_board(chessboard,row,column);
            return;
        }
    }
    if(((row +1)<ROW)&&((column+2)<COLUMN)){
        if(chessboard[row+1][column+2] == 0){
            row += 1;
            column += 2;
            printf("   %d,%d",row,column);
            over_board(chessboard,row,column);
            return;
        }
    }
    if(((row+2)<ROW)&&((column+1)<COLUMN)){
        if(chessboard[row+2][column+1] == 0){
            row += 2;
            column += 1;
            printf("   %d,%d",row,column);
            over_board(chessboard,row,column);
            return;
        }
    }
    if(((row+2)<ROW)&&((column-1)>-1)){
        if(chessboard[row+2][column-1] == 0){
            row += 2;
            column -= 1;
            printf("   %d,%d",row,column);
            over_board(chessboard,row,column);
            return;
        }
    }
    if(((row+1)<ROW)&&((column-2)>-1)){
        if(chessboard[row+1][column-2] == 0){
            row += 1;
            column -= 2;
            printf("   %d,%d",row,column);
            over_board(chessboard,row,column);
            return;
        }
    }
    if(((row-1)>-1)&&((column-2)>-1)){
        if(chessboard[row-1][column-2] == 0){
            row -= 1;
            column -= 2;
            printf("   %d,%d",row,column);
            over_board(chessboard,row,column);
            return;
        }
    }
    if(((row-2)>-1)&&((column-1)>-1)){
        if(chessboard[row-2][column-1] == 0){
            row -=2;
            column -= 1;
            printf("   %d,%d",row,column);
            over_board(chessboard,row,column);
            return;
        }
    }

    return;



    return;
}

int 
main(void)
{
    int row,
        column;
    int *rowp = &row,
        *columnp = &column;

    while(1){
        get_start(rowp,columnp);
        if(check_start(rowp,columnp) == 1)
            break;
    }
    over_board(chessboard,row,column);

    return 0;
}
