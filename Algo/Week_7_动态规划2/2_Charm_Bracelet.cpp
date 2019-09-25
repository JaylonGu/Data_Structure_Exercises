/*
002:Charm Bracelet
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N(1 ≤ N≤ 3,402) available charms. Each charm iin the supplied list has a weight Wi(1 ≤ Wi≤ 400), a 'desirability' factor Di(1 ≤ Di≤ 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M(1 ≤ M≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.



输入
Line 1: Two space-separated integers: N and M
Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di
输出
Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints
样例输入
4 6
1 4
2 6
3 12
2 7
样例输出
23
来源
USACO 2007 December Silver
*/

#include <iostream>
using namespace std;

const int MAXN=3402;
const int MAXM=12881;

int main(){
    int N,M;
    cin>>N>>M;
    int w[MAXN],d[MAXN];
    int dp[MAXM]={0}; // 表示最大重量为j时，最大价值是多少
    for(int i=0;i<N;++i){
        cin>>w[i]>>d[i];
    }
    for(int i=0;i<N;++i){   // 尝试一个个放进去
        for(int j=M;j>=w[i];--j){
            dp[j]=max(dp[j], dp[j-w[i]]+d[i]); // 判断放不放第i个charm
        }
    }
    cout<<dp[M];

    return 0;
}