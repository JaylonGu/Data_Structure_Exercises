/*
004:编程填空：MyClass
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
补充下列代码，使得程序的输出为：
A:3
A:15
B:5
3
15
5

#include <iostream>
using namespace std;
class CMyClassA {
	int val;
public:
	CMyClassA(int);
	void virtual print();
};
CMyClassA::CMyClassA(int arg) {
	val = arg;
	printf("A:%d\n", val);
}
void CMyClassA::print() {
	printf("%d\n", val);
	return;
}
// 在此处补充你的代码
int main(int argc, char** argv) {
	CMyClassA a(3), *ptr;
	CMyClassB b(5);
	ptr = &a; ptr->print();
	a = b;
	a.print();
	ptr = &b; ptr->print();
	return 0;
}
输入
无
输出
见样例
样例输入
None
样例输出
A:3
A:15
B:5
3
15
5
*/

#include <iostream>
using namespace std;
class CMyClassA {
	int val;
public:
	CMyClassA(int);
	void virtual print();
};
CMyClassA::CMyClassA(int arg) {
	val = arg;
	printf("A:%d\n", val);
}
void CMyClassA::print() {
	printf("%d\n", val);
	return;
}
// 在此处补充你的代码
class CMyClassB:public CMyClassA{
int val;
public:
    CMyClassB(int arg):CMyClassA(arg*3){
        val=arg;
        printf("B:%d\n",val);
    }
    void print() {
	printf("%d\n", val);
	return;
    }
};


int main(int argc, char** argv) {
	CMyClassA a(3), *ptr;
	CMyClassB b(5);
	ptr = &a; ptr->print();
	a = b;
	a.print();
	ptr = &b; ptr->print();
	return 0;
}