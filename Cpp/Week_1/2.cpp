/*
002:难一点的swap
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填空，使得程序输出结果是：

5,3

#include <iostream>
using namespace std;

void swap(
// 在此处补充你的代码
)
{
	int * tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 3,b = 5;
	int * pa = & a;
	int * pb = & b;
	swap(pa,pb);
	cout << *pa << "," << * pb;
	return 0;
}
输入
无
输出
5,3
样例输入
无
样例输出
5,3
*/

#include <iostream>
using namespace std;

void swap(
// 在此处补充你的代码
int* &a, int* &b
)
{
	int * tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 3,b = 5;
	int * pa = & a;
	int * pb = & b;
	swap(pa,pb);
	cout << *pa << "," << * pb;
	return 0;
}