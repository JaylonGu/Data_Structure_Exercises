/*
程序填空，按要求输出


输入
第一行是整数t，表示有t组数据
每组数据一行，三个整数加两个字符串。字符串是不含空格的

输出：

对每组数据，输出二行 
在第一行输出第一个数
第二行原样输出输入的内容

输入样例 
2
79 90 20 hello me
12 34 19 take up

输出样例：

79
79 90 20 hello me
12
12 34 19 take up

提示：


C++标准模板库 istream_iterator模版使用说明：

其构造函数执行过程中就会要求输入，然后每次执行++，则读取输入流中的下一个项目，执行 * 则返回上次从输入流中读取的项目。例如，下面程序运行时，就会等待用户输入数据，输入数据后程序才会结束：
#include <iostream>
#include <iterator>
using namespace std;
int main()  { 
	 istream_iterator<int> inputInt(cin);
	 return 0;  
}

下面程序运行时，如果输入 12   34  程序输出结果是： 12,12
#include <iostream>
#include <iterator>
using namespace std;
int main()  
{ 
	 istream_iterator<int> inputInt(cin);
	 cout << * inputInt << "," << * inputInt << endl;
	 return 0;  
}

下面程序运行时，如果输入 12   34   56程序输出结果是： 12,56
#include <iostream>
#include <iterator>
using namespace std;
int main()  
{ 
	 istream_iterator<int> inputInt(cin);
	 cout << * inputInt << "," ;
	 inputInt ++;
	 inputInt ++;
	 cout << * inputInt;
	 return 0;  
}
 

*/


#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
//your code starts here	
	istream &  r;
	T v;
	public:
		T operator *() {
			return v;	
		}
		CMyistream_iterator( istream & rr):r(rr) {
			r >> v ;
		}
		void operator ++ (int) {
			 r >> v ;
		}
//your code ends here		
};



int main()  
{ 
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //读入 n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;   
		 n2 = * inputInt; //读入 n2
		 inputInt ++;
		 n3 = * inputInt; //读入 n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;  
}

