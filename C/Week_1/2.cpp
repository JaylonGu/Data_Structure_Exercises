/*
002:字符菱形
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符，用它构造一个对角线长5个字符，倾斜放置的菱形。

输入
输入只有一行， 包含一个字符。
输出
该字符构成的菱形。
样例输入
*
样例输出
  *
 ***
*****
 ***
  *
*/


#include <iostream>
using namespace std;

int main()
{
    char a;
    cin>>a;
    for(int i=2;i>=0;i--){
        for(int j=i;j>0;j--){
            cout<<" ";
        }
        for(int j=5-2*i;j>0;j--){
            cout<<a;
        }
        cout<<endl;
    }
    for(int i=0;i<2;i++){
        for(int j=i+1;j>0;j--){
            cout<<" ";
        }
        for(int j=3-2*i;j>0;j--){
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}