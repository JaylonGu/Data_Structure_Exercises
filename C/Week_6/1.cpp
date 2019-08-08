/*
001:Pell数列
查看 提交 统计 提问
总时间限制: 3000ms 内存限制: 65536kB
描述
Pell数列a1, a2, a3, ...的定义是这样的，a1 = 1, a2 = 2, ... , an = 2 * an − 1 + an - 2 (n > 2)。
给出一个正整数k，要求Pell数列的第k项模上32767是多少。
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数k (1 ≤ k < 1000000)。
输出
n行，每行输出对应一个输入。输出应是一个非负整数。
样例输入
2
1
8
样例输出
1
408
*/

#include <iostream>
using namespace std;

int Pell(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int n1=1,n2=2,result;
    for(int i=3;i<=n;i++){
        result=(n1+2*n2)%32767;
        n1=n2;
        n2=result;
    }
    return result;
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int t;
        cin>>t;
        cout<<Pell(t)<<endl;
    }
    return 0;
}