/*
001:拦截导弹
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
某国为了防御敌国的导弹袭击，开发出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭，并观测到导弹依次飞来的高度，请计算这套系统最多能拦截多少导弹。拦截来袭导弹时，必须按来袭导弹袭击的时间顺序，不允许先拦截后面的导弹，再拦截前面的导弹。
输入
输入有两行，
第一行，输入雷达捕捉到的敌国导弹的数量k（k<=25），
第二行，输入k个正整数，表示k枚导弹的高度，按来袭导弹的袭击时间顺序给出，以空格分隔。
输出
输出只有一行，包含一个整数，表示最多能拦截多少枚导弹。
样例输入
8
300 207 155 300 299 170 158 65
样例输出
6
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=25;


int main(){
    int k, m[MAXN],maxlen[MAXN];
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>m[i];
        maxlen[i]=1;
    }
    for(int i=1;i<k;i++){
        for(int j=0;j<i;j++){
            if(m[i]<=m[j]){
                maxlen[i]=max(maxlen[j]+1 , maxlen[i]);
            }
        }
    }

    cout<< *max_element(maxlen,maxlen+k);

    return 0;
}