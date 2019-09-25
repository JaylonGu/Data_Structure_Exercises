/*
06:大整数加法
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
求两个不超过200位的非负整数的和。

输入
有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。
输出
一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
样例输入
22222222222222222222
33333333333333333333
样例输出
55555555555555555555
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char c1[201],c2[201];
    cin>>c1>>c2;
    int len1=strlen(c1), len2=strlen(c2);
    int num1[200], num2[200],num[201];
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    memset(num,0,sizeof(num2));
    for(int i=0;i<len1;i++){
        num1[i]=c1[len1-1-i]-'0';
    }
    for(int i=0;i<len2;i++){
        num2[i]=c2[len2-1-i]-'0';
    }
    int maxl=max(len1,len2);
    int carry=0;
    for(int i=0;i<maxl;i++){
        num[i]=num1[i]+num2[i]+carry;
        if(num[i]>=10) {
            num[i]-=10;
            carry=1;
        }else{
            carry=0;
        }
    }
    if(carry==1){
        cout<<1;
        for(int i=maxl-1;i>=0;--i) cout<<num[i];
    }else{
        while(num[maxl-1]==0 && maxl>=1) maxl--;
        for(int i=maxl-1;i>=0;--i) 
            cout<<num[i];
        if(maxl==0) cout<<0;
    }

    return 0;
}
