/*
003:数字反转
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例2）。

输入
输入共 1 行，一个整数N。

-1,000,000,000 ≤ N≤ 1,000,000,000。
输出
输出共 1 行，一个整数，表示反转后的新数。
样例输入
样例 #1：
123

样例 #2：
-380
样例输出
样例 #1：
321

样例 #2：
-83
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char num[12];
    cin.getline(num,12,'\n');
    int len=strlen(num);
    if(len==1 && num[0]=='0') cout<<0;
    else if(num[0]!='-'){
        int i=len-1;
        while(num[i]=='0') --i;
        for(;i>=0;i--) cout<<num[i];
    }else{
        int i=len-1;
        while(num[i]=='0') --i;
        cout<<'-';
        for(;i>0;i--) cout<<num[i];        
    }
    return 0;
}