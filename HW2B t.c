#include <stdio.h>
#define is_bound(x,y)(x >= 0 && x <= 7 && y >= 0 && y <= 7)

int chess[8][8] = {

    {0,0,0,0,0,0,0,0}
    {0,0,0,0,0,0,0,0}
    {0,0,0,0,0,0,0,0}
    {0,0,0,1,2,0,0,0}
    {0,0,0,2,1,0,0,0}
    {0,0,0,0,0,0,0,0}
    {0,0,0,0,0,0,0,0}
    {0,0,0,0,0,0,0,0}

};

int main(){

    int dx, dy;
    int i, j;
    int color;

    color = 1;
    i = 2;
    j = 4;
    dx = 1;
    dy = 1;

// int check(int chess[8][8], int i, int j, int dx, int dy, int color)
    int an_color = 3 - color;
    int an_color = color ^ 3;

    // # step 1. (i,j)可不可能可以下
    int x = i + dx;
    int y = i + dy;

    if(is_bound(x,y)){
        if(chess[x][y] != 2)
            printf("%d,%d is not free for color=%d.",i, j, color);
    }
    else{
        printf("%d,%d is not free for color=%d.",i, j, color);
        return;
    }

    // # step 2. chess[x][y] == 2
    x = x + dx;
    y = y + dy;
    while(is_bound(x,y)){
        if(chess[x][y] == 0){
            printf("%d,%d is not free for color=%d.",i, j, color);
            break;
        }
        if(chess[x][y] == 1){
            printf("%d,%d is free for color=%d.",i, j, color);
            break;
        }
        x = x + dx;
        y = y + dy;
    }

    return 0;
}