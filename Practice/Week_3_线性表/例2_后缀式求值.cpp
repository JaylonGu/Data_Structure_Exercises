/*
我们人类习惯于书写“中缀式”，如 3 + 5 * 2 ，其值为13。 (p.s. 为什么人类习惯中缀式呢？是因为中缀式比后缀式好用么？）
而计算机更加习惯“后缀式”（也叫“逆波兰式”，Reverse Polish Notation）。上述中缀式对应的后缀式是： 3 5 2 * +
现在，请对输入的后缀式进行求值。

输入格式:
在一行中输入一个后缀式，运算数和运算符之间用空格分隔，运算数长度不超过6位，运算符仅有+ - * / 四种。

输出格式:
在一行中输出后缀式的值，保留一位小数。

输入样例:
3 5.4 2.2 * +
输出样例:
14.9
*/

#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<double> s;
    char tmp;
    while(cin>>tmp){
        if(tmp>='0' && tmp<='9'){
            s.push(tmp-'0');
        }else{
            int first,second;
            second=s.top();
            s.pop();
            first=s.top();
            s.pop();
            switch(tmp){
                case '+':
                    s.push(first+second);
                    break;
                case '-':
                    s.push(first-second);
                    break;
                case '*':
                    s.push(first*second);
                    break;
                case '/':
                    s.push(first/second);
                    break;
            }

        }
    }
    return 0;
}