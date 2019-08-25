/*
04:求出e的值
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
利用公式e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n! 求e 。
输入
输入只有一行，该行包含一个整数n（2<=n<=15），表示计算e时累加到1/n！。
输出
输出只有一行，该行包含计算出来的e的值，要求打印小数点后10位。
样例输入
10
样例输出
2.7182818011
提示
1、e以及n!用double表示

2、要输出浮点数、双精度数小数点后10位数字，可以用下面这种形式：

printf("%.10f", num);
*/

#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    double e=1.0;
    double fact=1.0;
    for(int i=1;i<=n;++i){
        fact*=i;
        e+=1/fact;
    }
    printf("%.10f",e);

    return 0;
}