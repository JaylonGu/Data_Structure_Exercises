/*
002:还是sort简单题
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，产生指定输出结果

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point{
	int x;
	int y;
};
// 在此处补充你的代码
int main()
{
	int a[8] = {6,5,55,23,3,9,87,10 };
	sort(a,a+8,Rule1());
	for(int i = 0;i < 8; ++i)
		cout << a[i] << "," ; 
	cout << endl;
	Point ps[8] = {{1,0},{0,1},{0,-1},{-1,0},{1,-1},{1,1},{2,0},{-2,0} } ;
	sort(ps,ps+8,Rule2());
	for(int i = 0;i < 8; ++i)
		cout << "(" << ps[i].x << "," << ps[i].y << ")"; 
	return 0;
}
输入
无
输出
10,23,3,55,5,6,87,9,
(-1,0)(0,-1)(0,1)(1,0)(1,-1)(1,1)(-2,0)(2,0)

整数按照个位数从小到大排。个位数相同，则大的排前面 

点按照离原点从近到远排。距离相同，则按x坐标从小到大排。x坐标也相同，则按y坐标从小到大排
样例输入
无
样例输出
10,23,3,55,5,6,87,9,
(-1,0)(0,-1)(0,1)(1,0)(1,-1)(1,1)(-2,0)(2,0)
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point{
	int x;
	int y;
};
// 在此处补充你的代码
struct Rule1{
    bool operator()(const int &a1,const int &a2){
        if(a1%10!=a2%10) return a1%10<a2%10;
        else return a1>a2;
    }
};

struct Rule2{
    bool operator()(const Point &a1,const Point &a2){
        int dest1=a1.x*a1.x+a1.y*a1.y;
        int dest2=a2.x*a2.x+a2.y*a2.y;
        if(dest1!=dest2) return dest1<dest2;
        else if(a1.x!=a2.x) return a1.x<a2.x;
        else return a1.y<a2.y;
    }
};

int main()
{
	int a[8] = {6,5,55,23,3,9,87,10 };
	sort(a,a+8,Rule1());
	for(int i = 0;i < 8; ++i)
		cout << a[i] << "," ; 
	cout << endl;
	Point ps[8] = {{1,0},{0,1},{0,-1},{-1,0},{1,-1},{1,1},{2,0},{-2,0} } ;
	sort(ps,ps+8,Rule2());
	for(int i = 0;i < 8; ++i)
		cout << "(" << ps[i].x << "," << ps[i].y << ")"; 
	return 0;
}