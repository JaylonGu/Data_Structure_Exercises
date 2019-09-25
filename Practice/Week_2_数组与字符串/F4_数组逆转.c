/*
本题要求实现一个函数，可将一个整型数组里的元素逆转。例如原数组是[1,3,5,7,9]，逆转之后变成[9,7,5,3,1]

函数接口定义：
void reverse(int *array, int size);
其中参数 array是数组首地址，size是数组的长度（size>0）。

裁判测试程序样例：
函数被调用进行测试的一个可能的例子像这样：
#include <stdio.h>
void reverse(int *array, int size);
int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i=0; i<n; i++) scanf("%d", array+i);
    reverse(array, n);
    for(int i=0; i<n-1; i++) printf("%d ", array[i]);
    printf("%d", array[n-1]);
    return 0;
}
你提交的代码将被嵌到这里
输入样例：
5
1 2 3 4 5
输出样例：
5 4 3 2 1
*/

#include <stdio.h>
void reverse(int *array, int size);
int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i=0; i<n; i++) scanf("%d", array+i);
    reverse(array, n);
    for(int i=0; i<n-1; i++) printf("%d ", array[i]);
    printf("%d", array[n-1]);
    return 0;
}

void reverse(int *array, int size){
    int i=0,tmp;
    size--;
    while(i<size){
        tmp=array[i];
        array[i]=array[size];
        array[size]=tmp;
        i++;
        size--;
    }
}