/*
002:找第一个只出现一次的字符
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出no。

输入
一个字符串，长度小于100000。
输出
输出第一个仅出现一次的字符，若没有则输出no。
样例输入
abcabd
样例输出
c
*/

#include <iostream>
using namespace std;

int main(){
    char c[100001];
    cin>>c;
    int i=0;
    while(c[i]){
        int j=0;
        while(c[j]){
            if(i!=j && c[j]==c[i]) break;
            j++;
        }
        if(!c[j]) break;
        i++;
    }
    if(!c[i]) cout<<"no";
    else cout<<c[i];
    return 0;
}
