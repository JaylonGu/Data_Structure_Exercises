/*
������գ����ָ�����


���룺
�������ݡ�ÿ���һ����һ�������ո���ַ���
�ڶ���������n
��������n������

�����
��ÿ�����ݣ���������������ַ�����ÿ����ĸ��������ÿ����ĸ����Ӷ���
Ȼ����������������n������ ����ÿ����������Ӷ��� 


�������� 
Tom 
3
3 4 5
Jack
4
1 2 3 4


�������:
 
T,o,m,
3,4,5,
J,a,c,k,
1,2,3,4,


*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>  
class myclass { 
//your code starts here
	T * p;;
	int size;
public:
	myclass ( T a [], int n)  
	
	{
		p = new T[n];
		for( int i = 0;i < n;i ++ )
			p[i] = a[i];
		size = n;
	} 
//your code ends here	
	~myclass( ) {
		delete [] p;
	}
	void Show()
	{
		for( int i = 0;i < size;i ++ ) {
			cout << p[i] << ",";
		}
		cout << endl;
	}
};
int a[100];
int main() {
	char line[100];
	while( cin >> line ) {
		myclass<char> obj(line,strlen(line));;
		obj.Show();
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		myclass<int> obj2(a,n);
		obj2.Show();
	}
	return 0;
}

