/*
008:编程填空：还是Fun和Do
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填写代码，使输出结果为
A::Fun
B::Do
C::Fun
C::Do
A::Fun
B::Do

#include <iostream> 
using namespace std;

class A { 
	public: 
		virtual void Fun() { 
			cout << "A::Fun" << endl; 
		}; 
		virtual void Do() { 
			cout << "A::Do" << endl; 
		} 
};
// 在此处补充你的代码
{ 
	p.Fun(); 
	p.Do(); 
} 

void Call2(B p) {
	p.Fun();
	p.Do();
}



int main() { 
	C c;
	B b;
	Call1(b);
	Call1(c); 
	Call2(c);
	return 0;
}
输入
无
输出
A::Fun
B::Do
C::Fun
C::Do
A::Fun
B::Do
样例输入
None
样例输出
A::Fun
B::Do
C::Fun
C::Do
A::Fun
B::Do
*/

#include <iostream> 
using namespace std;

class A { 
	public: 
		virtual void Fun() { 
			cout << "A::Fun" << endl; 
		}; 
		virtual void Do() { 
			cout << "A::Do" << endl; 
		} 
};
// 在此处补充你的代码
class B:public A{
public:
    void Do(){
        cout<<"B::Do"<<endl;
    }
};

class C:public B{
public:
    void Fun(){
        cout<<"C::Fun"<<endl;
    }
    void Do(){
        cout<<"C::Do"<<endl;
    }
};

void Call1(A& p)
{ 
	p.Fun(); 
	p.Do(); 
} 

void Call2(B p) {
	p.Fun();
	p.Do();
}



int main() { 
	C c;
	B b;
	Call1(b);
	Call1(c); 
	Call2(c);
	return 0;
}