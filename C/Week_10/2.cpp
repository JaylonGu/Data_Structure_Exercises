/*
002:分数线划定
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
世博会志愿者的选拔工作正在 A 市如火如荼的进行。为了选拔最合适的人才，A市对所有报名的选手进行了笔试，笔试分数达到面试分数线的选手方可进入面试。面试分数线根据计划录取人数的150%划定，即如果计划录取m名志愿者，则面试分数线为排名第m*150%（向下取整）名的选手的分数，而最终进入面试的选手为笔试成绩不低于面试分数线的所有选手。

现在就请你编写程序划定面试分数线，并输出所有进入面试的选手的报名号和笔试成绩。

输入
第一行，两个整数n，m（5 ≤ n ≤ 5000，3 ≤ m ≤ n），中间用一个空格隔开，其中n 表示报名参加笔试的选手总数，m 表示计划录取的志愿者人数。输入数据保证m*150%向下取整后小于等于n。
第二行到第 n+1 行，每行包括两个整数，中间用一个空格隔开，分别是选手的报名号k（1000 ≤ k ≤ 9999）和该选手的笔试成绩s（1 ≤ s ≤ 100）。数据保证选手的报名号各不相同。
输出
第一行，有两个整数，用一个空格隔开，第一个整数表示面试分数线；第二个整数为进入面试的选手的实际人数。
从第二行开始，每行包含两个整数，中间用一个空格隔开，分别表示进入面试的选手的报名号和笔试成绩，按照笔试成绩从高到低输出，如果成绩相同，则按报名号由小到大的顺序输出。
样例输入
6 3
1000 90
3239 88
2390 95
7231 84
1005 95
1001 88
样例输出
88 5
1005 95
2390 95
1000 90
1001 88
3239 88
提示
样例说明：m*150% = 3*150% = 4.5，向下取整后为4。保证4个人进入面试的分数线为88，但因为88有重分，所以所有成绩大于等于88的选手都可以进入面试，故最终有5个人进入面试。
来源
NOIP2009复赛 普及组 第二题
*/

#include <cstdio>
using namespace std;

struct Candidate{
    int num;
    int grade;
};

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct Candidate* candidates=new struct Candidate[n];
    for(int i=0;i<n;++i){
        scanf("%d %d",&candidates[i].num, &candidates[i].grade);
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<i;j++){
            if ((candidates[i].grade>candidates[j].grade) || 
                (candidates[i].grade==candidates[j].grade && candidates[i].num<candidates[j].num)){
                struct Candidate tmp=candidates[i];
                for(int k=i;k>j;k--){
                    candidates[k]=candidates[k-1];
                }
                candidates[j]=tmp;
                break;
            }
        }
    }
    int enrollnum=(int) (m*1.5);
    int level=candidates[enrollnum-1].grade;
    enrollnum=0;
    for(int i=0;i<n;++i){
        if(candidates[i].grade>=level){
            enrollnum++;
        }else break;
    }
    printf("%d %d\n",level,enrollnum);
    for(int i=0;i<enrollnum;i++)
        printf("%d %d\n",candidates[i].num,candidates[i].grade);

    return 0;
}