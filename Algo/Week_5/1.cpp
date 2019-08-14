/*
001:输出前k大的数
查看 提交 统计 提问
总时间限制: 10000ms 单个测试点时间限制: 1000ms 内存限制: 65536kB
描述
给定一个数组，统计前k大的数并且把这k个数从大到小输出。

输入
第一行包含一个整数n，表示数组的大小。n < 100000。
第二行包含n个整数，表示数组的元素，整数之间以一个空格分开。每个整数的绝对值不超过100000000。
第三行包含一个整数k。k < n。
输出
从大到小输出前k大的数，每个数一行。
样例输入
10
4 5 6 9 8 7 1 2 3 0
5
样例输出
9
8
7
6
5
*/

// 把前m大的都弄到数组最右边 O(n)
// 然后对这最右边m个元素排序 O(mlogm)

#include <cstdio>
#include <algorithm>
using namespace std;

int array[100000];

void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

void arrangeRight(int a[], int start, int end, int k){
    if(end-start+1==k) return;
    int i=start, j=end, key=a[start];
    while(i<j){
        while(i<j && a[j]>=key) --j;
        swap(a[i],a[j]);    // 此时a[j]为key
        while(i<j && a[i]<=key) ++i;
        swap(a[i],a[j]);
    }
    int r=end-i+1;
    if(r==k) return;
    else if(r>k) arrangeRight(a,i+1,end,k);
    else arrangeRight(a,start,i-1,k-r);
}

int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&array[i]);
    scanf("%d",&k);

    arrangeRight(array,0,n-1,k);
    sort(array+n-k-1,array+n);
    for(int i=n-1;i>=n-k;--i) printf("%d\n",array[i]);

    return 0;
}