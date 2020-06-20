
/*
填写模板 PrintArray,使得程序输出结果是：

TomJackMaryJohn
10


不得编写SumArray函数 

*/ 


#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(
//your code starts here
T * begin, T * end) {
	T tmp = * begin;
	++ begin;
	for(;  begin != end ; ++ begin)
		tmp += * begin;
	return tmp;
//your code ends here	
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
} 

