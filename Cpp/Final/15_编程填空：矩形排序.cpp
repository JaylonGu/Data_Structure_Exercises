/*
015:编程填空：矩形排序
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
给定一系列边长已知的矩形，输出对矩形进行两种排序的结果。

在第一种排序中，先按矩形的面积从大到小排序；若两个矩形的面积相同，则周长大的排在前。

在第二种排序中，先按矩形的周长从小到大排序；若两个矩形的周长相同，则面积小的排在前。



#include <iostream>
#include <set>
using namespace std;
// 在此处补充你的代码
int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
	return 0;
}
输入
第一行是一个整数n，表示输入的矩形个数。
接下来n行表示了n个矩形。每行有两个整数a与b，表示该矩形的长与宽。
输出
先用n行输出第一种排序的结果。每行两个整数，依次表示该矩形的面积与周长。
再输出一个空行。
最后用n行输出第二种排序的结果。每行两个整数，依次表示该矩形的面积与周长。
样例输入
6
3 8
4 6
10 2
6 6
4 8
3 6
样例输出
36 24
32 24
24 22
24 20
20 24
18 18

18 18
24 20
24 22
20 24
32 24
36 24
*/

#include <iostream>
#include <set>
using namespace std;
// 在此处补充你的代码
class Rectangle{
public:
    int x,y;
    int area, perimeter;
    Rectangle(int _x, int _y):x(_x),y(_y){
        area=x*y;
        perimeter=2*(x+y);
    }
    bool operator<(Rectangle r){
        if(area != r.area) return area>r.area;
        else{
            return perimeter>r.perimeter;
        }
    }
    friend ostream& operator <<(ostream& o, const Rectangle& r){
        return o<<r.area<<" "<<r.perimeter;
    }
};

struct Comp{
    bool operator()(const Rectangle& a1, const Rectangle& a2)
    {
        if(a1.perimeter != a2.perimeter) return a1.perimeter<a2.perimeter;
        else{
            return a1.area<a2.area;
        }  
    }
};


int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
	return 0;
}