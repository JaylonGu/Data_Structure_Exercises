/*
004:神秘的数组初始化
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填空，使得程序输出指定结果

#include <iostream>
using namespace std;

int main()
{
	int * a[] = {
// 在此处补充你的代码
};
	
	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5];
	}
	return 0;
}
输入
无
输出
123,456
样例输入
无
样例输出
123,456
*/

#include <iostream>
using namespace std;

int main()
{
	int * a[] = {NULL,NULL,new int,new int[6]};
	
	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5];
	}
	return 0;
}