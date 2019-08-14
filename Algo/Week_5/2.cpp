/*
002:求排列的逆序数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
在Internet上的搜索引擎经常需要对信息进行比较，比如可以通过某个人对一些事物的排名来估计他（或她）对各种不同信息的兴趣，从而实现个性化的服务。

对于不同的排名结果可以用逆序来评价它们之间的差异。考虑1,2,…,n的排列i1，i2，…，in，如果其中存在j,k，满足 j < k 且 ij > ik， 那么就称(ij,ik)是这个排列的一个逆序。

一个排列含有逆序的个数称为这个排列的逆序数。例如排列 263451 含有8个逆序(2,1),(6,3),(6,4),(6,5),(6,1),(3,1),(4,1),(5,1)，因此该排列的逆序数就是8。显然，由1,2,…,n 构成的所有n!个排列中，最小的逆序数是0，对应的排列就是1,2,…,n；最大的逆序数是n(n-1)/2，对应的排列就是n,(n-1),…,2,1。逆序数越大的排列与原始排列的差异度就越大。

现给定1,2,…,n的一个排列，求它的逆序数。



输入
第一行是一个整数n，表示该排列有n个数（n <= 100000)。
第二行是n个不同的正整数，之间以空格隔开，表示该排列。
输出
输出该排列的逆序数。
样例输入
6
2 6 3 4 5 1
样例输出
8
提示
1. 利用二分归并排序算法（分治）；
2. 注意结果可能超过int的范围，需要用long long存储。
*/

// 分成两半，分别求两边的逆序数
// 求由左半边和右半边各取一个数构成的逆序数（ O(n) ） 关键在于两边都已经排好序

#include <cstdio>
using namespace std;

int a[100000];
int b[100000];

long long MergeAndCount(int a[], int s, int m, int e,int tmp[]){
    int pb=0;
    int p1=s,p2=m+1;
    long long count=0;
    while(p1<=m && p2<=e){
        if(a[p1]<=a[p2]){
            tmp[pb++]=a[p1++];
        }else{
            tmp[pb++]=a[p2++];
            count+=(m-p1+1);
        }
    }
    while(p1<=m) tmp[pb++]=a[p1++];
    while(p2<=e) tmp[pb++]=a[p2++];
    for(int i=0;i<e-s+1;++i) a[s+i]=tmp[i];
    return count;
}

long long MergeSortAndCount(int a[], int s, int e, int tmp[]){
    if(s<e){
        int m=s+(e-s)/2;
        return MergeSortAndCount(a,s,m,tmp)+MergeSortAndCount(a,m+1,e,tmp)+MergeAndCount(a,s,m,e,tmp);
    }else return 0;
}

int main(){
    int n;
    long long count;
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);

    count=MergeSortAndCount(a,0,n-1,b);
    printf("%lld",count);

    return 0;
}