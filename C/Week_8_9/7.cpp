/*
007:指针练习：MyMax
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
编写一个 MyMax函数，可以用来求任何数组中的最大值 使得程序按要求输出
#include <iostream>
using namespace std;
// 在此处补充你的代码
int Compare1(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return ((*p1)%10) - ((*p2)%10);
}
int Compare2(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return *p1 - *p2;
}
#define eps 1e-6
int	Compare3(void * n1,void * n2)
{
	float * p1 = (float * )n1;
	float * p2 = (float * )n2;
	if( * p1 - * p2 > eps)
		return 1;
	else if(* p2 - * p1 > eps)
		return -1;
	else
		return 0; 
}

int main()
{
	int t;
	int a[10];
	float d[10];
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		for(int i = 0;i < n; ++i)
			cin >> d[i];
		int * p = (int *) MyMax(a,sizeof(int),n,Compare1);
		cout << * p << endl;
		p = (int *) MyMax(a,sizeof(int),n,Compare2);
		cout << * p << endl;
		float * pd = (float * )MyMax(d,sizeof(float),n,Compare3);
		cout << * pd << endl;
	}
	return 0;
}
输入
第一行是测试数据组数 t
对每组数据：
第一行是整数n (1<=n<=10)
第2行是 n个整数
第3行是n个浮点数
输出
对每组数据：

先输出n个整数中个位数最大的数(答案保证唯一） 
再输出n个整数中最大的数
再输出n个浮点数中最大的数
样例输入
2
5
31 20 100 7 8
30.1 100.2 2.5 9.8 48.4
2
1 2
0.1 0.2
样例输出
8
100
100.2
2
2
0.2
*/

#include <iostream>
using namespace std;
// 在此处补充你的代码
void* MyMax(void* array, int size, int num,int (*Compare)(void* n1,void* n2)){
    void* max=array;
    for(int i=0;i<num;i++){
        if(Compare(array+i*size,max)>0) max=array+i*size;
    }
    return max;
}

int Compare1(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return ((*p1)%10) - ((*p2)%10);
}
int Compare2(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return *p1 - *p2;
}
#define eps 1e-6
int	Compare3(void * n1,void * n2)
{
	float * p1 = (float * )n1;
	float * p2 = (float * )n2;
	if( * p1 - * p2 > eps)
		return 1;
	else if(* p2 - * p1 > eps)
		return -1;
	else
		return 0; 
}

int main()
{
	int t;
	int a[10];
	float d[10];
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		for(int i = 0;i < n; ++i)
			cin >> d[i];
		int * p = (int *) MyMax(a,sizeof(int),n,Compare1);
		cout << * p << endl;
		p = (int *) MyMax(a,sizeof(int),n,Compare2);
		cout << * p << endl;
		float * pd = (float * )MyMax(d,sizeof(float),n,Compare3);
		cout << * pd << endl;
	}
	return 0;
}