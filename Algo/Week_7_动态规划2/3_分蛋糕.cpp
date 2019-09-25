/*
003:分蛋糕
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有一块矩形大蛋糕，长和宽分别是整数w 、h。现要将其切成m块小蛋糕，每个小蛋糕都必须是矩形、且长和宽均为整数。切蛋糕时，每次切一块蛋糕，将其分成两个矩形蛋糕。请计算：最后得到的m块小蛋糕中，最大的那块蛋糕的面积下限。

假设w= 4, h= 4, m= 4，则下面的切法可使得其中最大蛋糕块的面积最小。

<img src="http://media.openjudge.cn/images/upload/1372385654.gif" height="170" width="171"/>

假设w= 4, h= 4, m= 3，则下面的切法会使得其中最大蛋糕块的面积最小:


<img src="http://media.openjudge.cn/images/upload/1372385663.gif" height="176" width="179" />


输入
共有多行，每行表示一个测试案例。每行是三个用空格分开的整数w, h, m ，其中1 ≤ w, h, m ≤ 20 ， m ≤ wh. 当 w = h = m = 0 时不需要处理，表示输入结束。
输出
每个测试案例的结果占一行，输出一个整数，表示最大蛋糕块的面积下限。
样例输入
4 4 4
4 4 3
0 0 0
样例输出
4
6
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAX=21;
const int INF=1000;
int Way[MAX][MAX][MAX-1];

int main(){
    memset(Way,0,sizeof(Way));
    for(int i=1;i<MAX;i++){
        for(int j=1;j<MAX;j++){
            for(int k=0;k<MAX-1;k++){
                if(i*j<(k+1)) Way[i][j][k]=INF;
                else if(k==0) Way[i][j][k]=i*j;
                else{
                    Way[i][j][k]=INF;
                    for(int m=1;m<i;m++) // 第一刀竖着切，切的宽度为m
                        for(int n=0;n<k;n++) // 剩下的左边切n刀，右边切k-1-n刀
                            Way[i][j][k]=min(Way[i][j][k],max(Way[m][j][n],Way[i-m][j][k-1-n]));
                    for(int m=1;m<j;m++) // 第一刀横着切，切的高度为m
                        for(int n=0;n<k;n++) // 剩下的上面切n刀，下面切k-1-n刀
                            Way[i][j][k]=min(Way[i][j][k],max(Way[i][m][n],Way[i][j-m][k-1-n]));
                }
            }
        }
    }
    int w,h,m;
    cin>>w>>h>>m;
    while(w || h || m){
        cout<<Way[w][h][m-1]<<endl;
        cin>>w>>h>>m;
    }

    return 0;
}