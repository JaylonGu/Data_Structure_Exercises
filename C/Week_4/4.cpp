/*
004:求特殊自然数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
一个十进制自然数,它的七进制与九进制表示都是三位数，且七进制与九进制的三位数码表示顺序正好相反。编程求此自然数,并输出显示。

输入
无。
输出
三行：
第一行是此自然数的十进制表示；
第二行是此自然数的七进制表示；
第三行是此自然数的九进制表示。
样例输入
（无）
样例输出
（不提供）
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    for(int i=81;i<=49*7;++i){
        int seventh[3];
        int ninth[3];
        for(int j=0;j<3;++j){
            seventh[j]=i/((int)pow(7,j))%7;
            ninth[j]=i/((int)pow(9,j))%9;
        }
        // cout<<i<<" "<<seventh[0]<<" "<<ninth[0]<<endl;
        if(seventh[0]==ninth[2] && seventh[1]==ninth[1] && seventh[2]==ninth[0] ){
            cout<<i<<endl;
            cout<<seventh[2]<<seventh[1]<<seventh[0]<<endl;
            cout<<ninth[2]<<ninth[1]<<ninth[0];
            break;
        }
    }
    return 0;
}