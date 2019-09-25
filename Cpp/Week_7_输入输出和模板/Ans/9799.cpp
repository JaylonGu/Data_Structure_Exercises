/*
读入两个整数，输出两个整数 ,直到碰到-1

输入

多组数据，每组一行，是两个整数

输出

对每组数据，原样输出 
当碰到输入中出现-1 时，程序结束 
输入中保证会有 -1 


输入样例

12 44
344 555
-1
2 3

输出样例 

12 44
344 555


*/
#include <iostream>
using namespace std;
class MyCin
{
	//your code starts here
    bool valid;    
    public:
        MyCin():valid(true) { }
        operator bool( ) { //重载类型强制转换运算符 bool
            return valid; 
        }
        MyCin & operator >> (int & n)
        {
            cin >> n;
            if( n == -1 )
            	valid = false;
            
            return * this;
        }
//your code ends here        
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}

