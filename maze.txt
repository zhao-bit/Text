
/*
	迷宫问题，输出最短路径 
*/
#include <stdio.h>
#define N 9 
typedef struct {
	int x,y;
	int parent;
}Elem;
Elem que[N*N];		//将迷宫中可通点坐标加入队列，不会超过N*N个 
int front = 0,rear = 0;
int maze[N][N] = {{2, 2, 2, 2, 2, 2, 2, 2, 2},// 2为墙，0为通路 
                  {2, 0, 0, 0, 0, 0, 0, 0, 2},//走过的位置从0变-1，是最短路径上的节点最后置1
                  {2, 0, 2, 2, 0, 2, 2, 0, 2},
                  {2, 0, 2, 0, 0, 2, 0, 0, 2},
                  {2, 0, 2, 0, 2, 0, 2, 0, 2},
                  {2, 0, 0, 0, 0, 0, 2, 0, 2},
                  {2, 2, 0, 2, 2, 0, 2, 2, 2},
                  {2, 0, 0, 0, 0, 0, 0, 0, 2},
                  {2, 2, 2, 2, 2, 2, 2, 2, 2}};
int startI = 1, startJ = 1;  	// 入口
int endI = 7, endJ = 7;  		// 出口 
void addToQue(int parent,int x,int y){
	if(maze[x][y] == 0 ){
		Elem e;
		e.x = x;
		e.y = y;
		e.parent = parent;
		que[rear++] = e;
		maze[x][y] = -1;
	}
}
void showMaze(){
	int i,j;
	for(i = 0 ; i < N ; i ++){
		for(j = 0 ; j < N ; j ++)
			if(maze[i][j] == 2)
				printf("$");
			else if(maze[i][j] == 1)
				printf("◇");
			else
				printf("  ");
		
	}
	printf("\n");
}
int main(){
	Elem pe;			//创建一个队列元素	
	pe.x = startI;		//将开始点加入队列 
	pe.y = startJ;
	pe.parent = -1;			//开始点没有的父节点，因此设置为-1 
	que[front] = pe;
	rear++;
	showMaze();
	while(!(que[front].x == endI && que[front].y == endJ)){
		pe = que[front];
		maze[pe.x][pe.y] = -1;
		addToQue(front,pe.x,pe.y+1);//加入到队列中去 
		addToQue(front,pe.x,pe.y-1);
		addToQue(front,pe.x+1,pe.y);
		addToQue(front,pe.x-1,pe.y);	
		front++;
	}
	pe = que[front];
	if(pe.x == endI && pe.y == endJ){
		int step = 0;
		while(pe.parent != -1){		
			step ++;
			maze[pe.x][pe.y] = 1;
			pe = que[pe.parent];
		}
		printf("笨笨找到了最短路径的步数是: %d 步\n",step);
		showMaze();
	}	
	return 0;
}