/*
本题要求实现一个函数，查找数组中最大元素的下标。例如数组为{1,3,5,7,9}，则该函数应该返回4。题目输入保证数组元素各不相同。

函数接口定义：
int indexOfMax(int *array, int size);
其中 array 和 size 是用户传入的参数。 array 是数组首地址； size 是数组元素的个数。函数须返回数组中最大元素的下标（从0开始）。

裁判测试程序样例：
此测试程序仅为示例，实际的测试程序可能不同
#include <stdio.h>
#define MAXSIZE 100
int indexOfMax(int *array, int size);
int main(){
    int num[MAXSIZE];
    int total;
    scanf("%d",&total);
    for(int i=0; i<total; i++) scanf("%d",&num[i]);
    printf("%d\n",num[indexOfMax(num,total)]);
    return 0;
}

你所编写的函数代码将被嵌在这里 
输入样例：
4 2016 2017 1999 1998
输出样例：
2017
*/

#include <stdio.h>
#define MAXSIZE 100
int indexOfMax(int *array, int size);
int main(){
    int num[MAXSIZE];
    int total;
    scanf("%d",&total);
    for(int i=0; i<total; i++) scanf("%d",&num[i]);
    printf("%d\n",num[indexOfMax(num,total)]);
    return 0;
}

int indexOfMax(int *array, int size){
    int maxi=0, max=array[0];
    for(int i=1;i<size;++i){
        if(array[i]>max){
            max=array[i];
            maxi=i;
        }
    }
    return maxi;
}