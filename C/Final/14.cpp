/*
14:判断元素是否存在
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有一个集合M是这样生成的： (1) 已知 k 是集合 M 的元素； (2) 如果 y 是 M 的元素，那么， 2y+1 和 3y+1 都是 M 的元素； (3) 除了上述二种情况外，没有别的数能够成为 M 的一个元素。

问题：任意给定 k 和 x，请判断 x 是否是 M 的元素。这里的 k是无符号整数，x 不大于 100000， 如果是，则输出YES，否则，输出 NO

输入
输入整数 k 和 x, 逗号间隔。
输出
如果是，则输出 YES，否则，输出NO
样例输入
0,22
样例输出
YES
*/

#include <iostream>
#include <cstdio>
using namespace std;

bool contain(int k, int x){
    if(x==k) return true;
    if(k>x) return false;
    return (contain(2*k+1,x)||contain(3*k+1,x));
}

int main(){
    int k,x;
    scanf("%d,%d",&k,&x);
    if(contain(k,x)) cout<<"YES";
    else cout<<"NO";

    return 0;
}