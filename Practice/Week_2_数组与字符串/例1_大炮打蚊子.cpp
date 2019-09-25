/*
现在，我们用大炮来打蚊子：蚊子分布在一个M×N格的二维平面上，每只蚊子占据一格。向该平面的任意位置发射炮弹，炮弹的杀伤范围如下示意：

 O
OXO
 O
其中，X为炮弹落点中心，O为紧靠中心的四个有杀伤力的格子范围。若蚊子被炮弹命中（位于X格），一击毙命，若仅被杀伤（位于O格），则损失一半的生命力。也就是说，一次命中或者两次杀伤均可消灭蚊子。现在给出蚊子的分布情况以及连续k发炮弹的落点，给出每炮消灭的蚊子数。

输入格式:
第一行为两个不超过20的正整数M和N，中间空一格，表示二维平面有M行、N列。

接下来M行，每行有N个0或者#字符，其中#表示所在格子有蚊子。

接下来一行，包含一个不超过400的正整数k，表示发射炮弹的数量。

最后k行，每行包括一发炮弹的整数坐标x和y（0≤x<M，0≤y<N），之间用一个空格间隔。

输出格式:
对应输入的k发炮弹，输出共有k行，第i行即第i发炮弹消灭的蚊子数。

输入样例:
5 6
00#00#
000###
00#000
000000
00#000
2
1 2
1 4
输出样例:
0
2
*/

#include <iostream>
using namespace std;

int main(){
    int wz[20][20];
    int M,N,k;
    cin>>M>>N;
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            char tmp;
            cin>>tmp;
            if(tmp=='0') wz[i][j]=0;
            else wz[i][j]=2;
        }
    }
    cin>>k;
    int x,y,count=0;
    int xc[4]={0,0,1,-1},yc[4]={1,-1,0,0};
    while(k--){
        cin>>x>>y;
        int tmpx=x,tmpy=y;
        if(wz[tmpx][tmpy]>0){
            count++;
            wz[tmpx][tmpy]=0;
        }
        for(int i=0;i<4;++i){
            tmpx=x+xc[i];
            tmpy=y+yc[i];
            if(tmpx>=0 && tmpy>=0 && tmpx<M && tmpy<N){
                if(wz[tmpx][tmpy]==2) wz[tmpx][tmpy]--;
                else if(wz[tmpx][tmpy]==1){
                    count++;
                    wz[tmpx][tmpy]--;
                }
            }
        }
        cout<<count<<endl;
        count=0;
    }
    return 0;
}