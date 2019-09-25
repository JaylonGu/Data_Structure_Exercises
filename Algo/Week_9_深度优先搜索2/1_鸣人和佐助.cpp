/*
001:鸣人和佐助
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
佐助被大蛇丸诱骗走了，鸣人在多少时间内能追上他呢？

已知一张地图（以二维矩阵的形式表示）以及佐助和鸣人的位置。地图上的每个位置都可以走到，只不过有些位置上有大蛇丸的手下，需要先打败大蛇丸的手下才能到这些位置。鸣人有一定数量的查克拉，每一个单位的查克拉可以打败一个大蛇丸的手下。假设鸣人可以往上下左右四个方向移动，每移动一个距离需要花费1个单位时间，打败大蛇丸的手下不需要时间。如果鸣人查克拉消耗完了，则只可以走到没有大蛇丸手下的位置，不可以再移动到有大蛇丸手下的位置。佐助在此期间不移动，大蛇丸的手下也不移动。请问，鸣人要追上佐助最少需要花费多少时间？

输入
输入的第一行包含三个整数：M，N，T。代表M行N列的地图和鸣人初始的查克拉数量T。0 < M,N < 200，0 ≤ T < 10
后面是M行N列的地图，其中@代表鸣人，+代表佐助。*代表通路，#代表大蛇丸的手下。
输出
输出包含一个整数R，代表鸣人追上佐助最少需要花费的时间。如果鸣人无法追上佐助，则输出-1。
样例输入
样例输入1
4 4 1
#@##
**##
###+
****

样例输入2
4 4 2
#@##
**##
###+
****
样例输出
样例输出1
6

样例输出2
4
*/

#include <iostream>
#include <cstring>
using namespace std;

int M,N,T,t=0,mint=40000;
char map[200][200];
bool visited[200][200];
short smallest[200][200][9]; // 保存到达该点时的最短时间
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};

void DFS(int row,int col){
    for(int i=0;i<4;++i){
        int nextrow=row+y[i],nextcol=col+x[i];
        if(nextrow>=0 && nextrow<M && nextcol>=0 && nextcol<N && !visited[nextrow][nextcol] && smallest[nextrow][nextcol][T]>t){
            smallest[nextrow][nextcol][T]=t;
            if(map[nextrow][nextcol]=='*'){
                t++;
                visited[nextrow][nextcol]=true;
                DFS(nextrow,nextcol);
                t--;
                visited[nextrow][nextcol]=false;
            }
            else if(map[nextrow][nextcol]=='#'){
                if(T){
                    T--;
                    t++;
                    visited[nextrow][nextcol]=true;
                    DFS(nextrow,nextcol);
                    T++;
                    t--;
                    visited[nextrow][nextcol]=false;
                }else continue;
            }
            else{
                if(++t<mint) mint=t;
                t--;
            }
        }
        else continue;
    }
    return;
}

int main(){
    // freopen("in.txt","r",stdin);
    cin>>M>>N>>T;
    int _row,_col;
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            cin>>map[i][j];
            if(map[i][j]=='@'){
                _row=i; _col=j;
            }
        }
    }

    memset(visited,0,sizeof(visited));
    memset(smallest,127,sizeof(smallest));
    visited[_row][_col]=true;
    DFS(_row,_col);

    if(mint == 40000) cout << -1;
    else cout << mint;
    return 0;
}