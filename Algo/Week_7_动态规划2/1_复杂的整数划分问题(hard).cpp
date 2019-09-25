/*
001:复杂的整数划分问题
查看 提交 统计 提问
总时间限制: 200ms 内存限制: 65536kB
描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。

输入
标准的输入包含若干组测试数据。每组测试数据是一行输入数据,包括两个整数N 和 K。 
(0 < N <= 50, 0 < K <= N)
输出
对于每组测试数据，输出以下三行数据:
第一行: N划分成K个正整数之和的划分数目
第二行: N划分成若干个不同正整数之和的划分数目
第三行: N划分成若干个奇正整数之和的划分数目
样例输入
5 2
样例输出
2
3
3
提示
第一行: 4+1, 3+2,
第二行: 5，4+1，3+2
第三行: 5，1+1+3， 1+1+1+1+1+1
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN=51;
int dp[MAXN][MAXN]; 

int main(){
    int N,K;
    while(cin>>N>>K){
        // case1
        // dp[i][j]表示i划分为j个数之和的数目
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;++i) dp[i][1]=1;
        for(int i=2;i<=N;++i){
            for(int j=2;j<=i;++j){
                dp[i][j]=dp[i-j][j]+dp[i-1][j-1]; // 把i-j划分为j个整数的情况（每个数都加上1即为i划分为j个整数的情况）+把(i-1)划分为(j-1)个数的情况
            }
        }
        cout<<dp[N][K]<<endl;
        // case2
        // dp[i][j]表示上限为j时的划分方法数
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<=N;++i){
            for(int j=1;j<=N;++j){
                if(j<=i) dp[i][j]=dp[i-j][j-1]+dp[i][j-1];  // 有j的情况+没j的情况
                else dp[i][j]=dp[i][i];
            }
        }
        cout<<dp[N][N]<<endl;
        // case3
        // dp[i][j]表示上限为j时的划分方法数
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;++i){
            dp[i][1]=1;
            if(i%2) dp[0][i]=1; // dp[i-i][i]只有该奇数
        }
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                if(j%2){
                    if(j<=i) dp[i][j]=dp[i-j][j]+dp[i][j-1];
                    else dp[i][j]=dp[i][i];
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        cout<<dp[N][N]<<endl;
    }
    
    return 0;
}