/*
001:统计数字字符个数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一行字符，统计出其中数字字符的个数。

输入
一行字符串，总长度不超过255。
输出
输出为1行，输出字符串里面数字字符的个数。
样例输入
Peking University is set up at 1898.
样例输出
4
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[256];
    cin.getline(s,256);
    int l=strlen(s);
    cout<<l<<endl;
    int count=0;
    for(int i=0;i<l;++i){
        if(s[i]>='0' && s[i]<='9') count++;
    }
    cout<<count;
    return 0;
}
