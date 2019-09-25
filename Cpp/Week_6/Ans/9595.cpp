/*
程序填空输出指定结果

destructor B
destructor A

*/

 
#include <iostream> 
using namespace std;
class A 
{ 
public:
	A() { }
//your code starts here	
	virtual ~A() { cout << "destructor A" << endl; } 
//your code ends here	
}; 
class B:public A { 
	public: 
	~B() { cout << "destructor B" << endl; } 
}; 
int main() 
{ 
	A * pa; 
	pa = new B; 
	delete pa; 
	return 0;
} 

