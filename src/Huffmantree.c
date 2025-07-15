#include<stdio.h>
int endx,endy;
int min=999999;
int a[100][100];//1表示路，2表示墙
int visited[100][100]//0表示未标记，1表示标记过
void dfs( int x,int y,int step ){
    if(x==endx && y==endy){
        if(step<min) min = step;
        return ;
    }
    //右走
    if(a[x+1][y]==1 && visited[x+1][y]==0){
        visited[x+1][y]=1;
        dfs(x+1,y,step+1);
        visited[x+1][y]=0;
    }
    //左走
    if(a[x-1][y]==1 && visited[x-1][y]==0){
        visited[x-1][y]=1;
        dfs(x-1,y,step+1);
        visited [x-1][y]=0;
    }
    //上走
    if(a[x][y+1]==1 && visited[x][y+1]==0){
        visited[x][y+1]=1;
        dfs(x,y+1,step+1);
        visited[x][y+1]=0;
    }
    //下走
    if(a[x][y-1]==1 && visited[x][y--1]==0){
        visited[x][y-1]=1;
        dfs(x,y-1,step+1);
        visited[x][y+-]=0;
    }
    return;
}
int main(){

    scanf("请输入%d行%列",&m,&n);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
              scanf("%d",&w);
        }
    }
    printf("请输入起点：")；
    scanf("%d %d",&x,&y);
    printf("请输入终点：");
    scafn9



    return
}
