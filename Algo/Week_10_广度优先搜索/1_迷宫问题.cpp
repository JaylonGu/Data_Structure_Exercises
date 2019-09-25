/*
001:迷宫问题
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
定义一个二维数组：

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。



输入
一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
输出
左上角到右下角的最短路径，格式如样例所示。
样例输入
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
样例输出
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
*/

#include <iostream>
#include <stack>
using namespace std;

const int MAXN=5;

struct box{
    int x,y;
    struct box *prev;
};

int maze[MAXN][MAXN];
int visited[MAXN][MAXN]{0};
struct box q[MAXN*MAXN];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    for(int i=0;i<MAXN;++i){
        for(int j=0;j<MAXN;++j){
            cin>>maze[i][j];
        }
    }
    int front=0,rear=0;
    q[rear].x=0;
    q[rear].y=0;
    q[rear++].prev=NULL;
    visited[0][0]=1;
    while(q[front].x!=4 || q[front].y!=4){
        int x=q[front].x, y=q[front].y;
        for(int i=0;i<4;++i){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && nx<5 && ny>=0 && ny<5 && !maze[nx][ny] && !visited[nx][ny]){
                q[rear].x=nx;
                q[rear].y=ny;
                q[rear++].prev=&q[front];
                visited[nx][ny]=1;
            }
        }
        front++;
    }

    stack<box*> s;
    box* b=&q[front];
    while(b){
        s.push(b);
        b=b->prev;
    }
    
    while(!s.empty()){
        cout<<"("<<s.top()->x<<", "<<s.top()->y<<")"<<endl;
        s.pop();
    }

    return 0;
}