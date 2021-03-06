/*
003:指针练习：ForEach
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，使得输出结果为：

1,4,9,16,25, 
h,e,l,l,o,!,

#include <iostream>
using namespace std;

void ForEach(void * a, int width, int num,
// 在此处补充你的代码
)

{
	for(int i = 0;i < num; ++i) 
		f((char*)a+width*i);
}

void PrintSquare(void * p)
{
	int * q = (int*)p;
	int n = *q;
	cout << n * n << ",";
}
void PrintChar(void * p) {
	char * q = (char*)p;
	cout << *q << ",";
}
int main()
{
	int a[5] = {1,2,3,4,5};
	char s[] = "hello!";
	ForEach(a,sizeof(int),5,PrintSquare); 
	cout << endl;
	ForEach(s,sizeof(char),6,PrintChar);
	return 0;
}
输入
无
输出
1,4,9,16,25,
h,e,l,l,o,!,
样例输入
无
样例输出
1,4,9,16,25,
h,e,l,l,o,!,
*/

#include <iostream>
using namespace std;

void ForEach(void * a, int width, int num,
// 在此处补充你的代码
    void (*f)(void*)
)

{
	for(int i = 0;i < num; ++i) 
		f((char*)a+width*i);
}

void PrintSquare(void * p)
{
	int * q = (int*)p;
	int n = *q;
	cout << n * n << ",";
}
void PrintChar(void * p) {
	char * q = (char*)p;
	cout << *q << ",";
}
int main()
{
	int a[5] = {1,2,3,4,5};
	char s[] = "hello!";
	ForEach(a,sizeof(int),5,PrintSquare); 
	cout << endl;
	ForEach(s,sizeof(char),6,PrintChar);
	return 0;
}