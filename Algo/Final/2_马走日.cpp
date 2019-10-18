/*
02:马走日
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
马在中国象棋以日字形规则移动。

请编写一段程序，给定n*m大小的棋盘，以及马的初始位置(x，y)，要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。

输入
第一行为整数T(T < 10)，表示测试数据组数。
每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标n,m,x,y。(0<=x<=n-1,0<=y<=m-1, m < 10, n < 10)
输出
每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，0为无法遍历一次。
样例输入
1
5 4 0 0
样例输出
32
*/

#include <iostream>
#include <cstring>
using namespace std;

int xc[8]={-1,1,-1,1,-2,2,-2,2}, yc[8]={-2,2,2,-2,-1,1,1,-1};
int visited[10][10];
int sum=0;
int n,m;

bool traversal(){
    for (int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!visited[i][j]) return false;
        }
    }
    return true;
}

void dfs(int x, int y){
    visited[x][y]=1;
    if(traversal()){
        ++sum;
        visited[x][y]=0;
        return;
    }
    for(int i=0;i<8;++i){
        int nx=x+xc[i], ny=y+yc[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
            dfs(nx,ny);
        }
    }
    visited[x][y]=0;
}

int main(){
    int t;
    int x,y;
    cin>>t;
    while(t--){
        cin>>n>>m>>x>>y;
        sum=0;
        memset(visited,0,sizeof(visited));
        dfs(x,y);
        cout<<sum<<endl;
    }
    
    return 0;
}