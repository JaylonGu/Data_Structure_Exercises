/*
006:我自己的 ostream_iterator
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空输出指定结果

#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
	for(; s != e; ++s,++x)
		*x = *s;
}


template<class T>
class myostream_iteraotr
{
// 在此处补充你的代码
};


int main()
{	const int SIZE = 5;
	int a[SIZE] = {5,21,14,2,3};
	double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
	list<int> lst(a,a+SIZE);
	myostream_iteraotr<int> output(cout,",");
	Copy( lst.begin(),lst.end(),output); 
	cout << endl;
	myostream_iteraotr<double> output2(cout,"--");
	Copy(b,b+SIZE,output2);
	return 0;
}
输入
无
输出
5,21,14,2,3,
1.4--5.56--3.2--98.3--3.3--
样例输入
无
样例输出
同输入
来源
Guo Wei
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
	for(; s != e; ++s,++x)
		*x = *s;
}


template<class T>
class myostream_iteraotr
{
// 在此处补充你的代码
	ostream& o;
	string s;
	T tmp;
public:
	myostream_iteraotr(ostream& _o,string _s):o(_o),s(_s){};
	T& operator*(){
		return tmp;
	}
	void operator++(){
		o<<tmp<<s;
	}
};


int main()
{	const int SIZE = 5;
	int a[SIZE] = {5,21,14,2,3};
	double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
	list<int> lst(a,a+SIZE);
	myostream_iteraotr<int> output(cout,",");
	Copy( lst.begin(),lst.end(),output); 
	cout << endl;
	myostream_iteraotr<double> output2(cout,"--");
	Copy(b,b+SIZE,output2);
	return 0;
}