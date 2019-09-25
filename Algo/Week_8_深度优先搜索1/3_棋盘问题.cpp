/*
003:棋盘问题
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
输入
输入含有多组测试数据。
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n
当为-1 -1时表示输入结束。
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。
输出
对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
样例输入
2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
样例输出
2
1
来源
蔡错@pku
*/

#include <iostream>
#include <cstring>
using namespace std;

char chessboard[8][8];
bool visited[8];
int n,k;
int chess=0;
int ways=0;

void DFS(int row){
    if(chess==k){
        ++ways;
        return;
    }
    if(row>=n) return;
    for(int col=0;col<n;++col){
        if(!visited[col] && chessboard[row][col]=='#'){
            visited[col]=true;
            ++chess;
            DFS(row+1);
            visited[col]=false;
            --chess;
        }
    }
    DFS(row+1);
}


int main(){
    while(1){
        cin>>n>>k;
        if(n==-1&&k==-1) break;
        memset(visited,0,sizeof(visited));
        ways=0;
        chess=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>chessboard[i][j];
        DFS(0);
        cout<<ways<<endl;
    }

    return 0;
}