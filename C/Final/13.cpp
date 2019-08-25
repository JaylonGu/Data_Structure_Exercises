/*
13:1的个数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个十进制非负整数N，求其对应2进制数中1的个数。

输入
输入包含一行，包含一个非负整数N。(N < 109)
输出
输出一行，包含一个整数，表示N的2进制表示中1的个数。
样例输入
100
样例输出
3
*/

#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int count=0;
    while(N/2){
        if(N%2) count++;
        N/=2;
    }
    if(N) count++;
    cout<<count;
    return 0;
}