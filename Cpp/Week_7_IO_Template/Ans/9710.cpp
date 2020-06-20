
/*
3) 自己编写一个能对任何类型的数组进行排序的mysort函数模版，可以如下使用:
	
4 8 10 11 123
123 11 10 8 4
1.400000 1.200000 1.800000 3.100000 3.200000 2.100000


提示:
1> an 和 an + NUM 的类型显然是一样的，都是 int *
2> mysort里用第二个参数减去第一个参数，就能知道要排序的元素有几个
3> mysort(an,an+NUM,Greater1) 会导致 Greater1在mysort内部被调用，用来比较元素大小，因此回忆一下函数指针的用法


	
*/
#include <iostream>
using namespace std;

bool Greater2(int n1,int n2) 
{
	return n1 > n2;
}
bool Greater1(int n1,int n2) 
{
	return n1 < n2;
}
bool Greater3(double d1,double d2)
{
	return d1 < d2;
}

template <class T1,class T2>
void mysort(
//your code starts here
 T1 * start , T1 * end, T2 myless )
{
	int size = end - start;
	for( int i = size -1;i >= 0 ; --i ) {
		for( int j = 0; j < i ; ++j ) {
			if(  myless( start[j+1],start[j] )) {
				T1 tmp = start[j];
				start[j] = start[j+1];
				start[j+1] = tmp; 
			}
		}
	}
}
/*答案2 ：
template<class T>
void Swap( T & a, T & b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <class T1,class T2>
void mysort( T1  start , T1  end, T2 myless )
{
	int size = end - start;
	for( int i = size -1;i >= 0 ; --i ) {
		for( int j = 0; j < i ; ++j ) {
			if(  myless( * ( start + j+1), * (start+j) )) {
				Swap(* ( start + j+1), * (start+j) );
			}
		}
	}
}
答案 3 
template <class T1,class T2>
void mysort( T1  start , T1  end, T2 myless )
{
	int size = end - start;
	for( int i = size -1;i >= 0 ; --i ) {
		for( int j = 0; j < i ; ++j ) {
			if(  myless( * ( start + j+1), * (start+j) )) {
				auto tmp = * ( start+j);
				* ( start +j ) = * ( start + j+1);
				* ( start + j+1)  = tmp; 
			}
		}
	}
}

*/

//your code ends here

#define NUM 5
int main()
{
    int an[NUM] = { 8,123,11,10,4 };
    mysort(an,an+NUM,Greater1); //从小到大排序 
    for( int i = 0;i < NUM; i ++ )
       cout << an[i] << ",";
    mysort(an,an+NUM,Greater2); //从大到小排序 
    cout << endl;
    for( int i = 0;i < NUM; i ++ )
        cout << an[i] << ","; 
    cout << endl;
    double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1};
    mysort(d+1,d+5,Greater3); //将数组从下标1到下标4从小到大排序 
    for( int i = 0;i < 6; i ++ )
         cout << d[i] << ","; 
	return 0;
}

