/*
004:计算球的体积
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
对于半径为r的球，其体积的计算公式为V=4/3*πr3，这里取π= 3.14。

现给定r，求V。

输入
输入为一个不超过100的非负实数，即球半径，类型为double。
输出
输出一个实数，即球的体积，保留到小数点后2位。
样例输入
4
样例输出
267.95
*/

#include <iostream>
#define pi 3.14
using namespace std;

int main(){
    double r;
    scanf("%lf",&r);
    printf("%.2f",4.0/3*pi*r*r*r);
    return 0;
}