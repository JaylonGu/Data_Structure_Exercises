/*
004:这个指针哪来的
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填空，按要求输出

#include <iostream>
using namespace std;

struct A
{
	int v;
	A(int vv):v(vv) { }
// 在此处补充你的代码
};

int main()
{
	const A a(10);
	const A * p = a.getPointer();
	cout << p->v << endl;
	return 0;
}
输入
无
输出
10
样例输入
无
样例输出
10
*/

#include <iostream>
using namespace std;

struct A
{
	int v;
	A(int vv):v(vv) { }
// 在此处补充你的代码
    const A* getPointer() const {return this;} // 常量对象只能调用常量函数，常量对象不能自动类型转换为非常量对象
};

int main()
{
	const A a(10);
	const A * p = a.getPointer();
	cout << p->v << endl;
	return 0;
}