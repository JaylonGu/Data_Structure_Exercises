/*
006:编程填空：去除重复元素排序
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，使其按要求输出

#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	int  a[100];
	cin >> t;
	while(t--) {
		for(int i = 0;i < 12; ++i)
			cin >> a[i];
// 在此处补充你的代码
std::copy(b.begin(), b.end(), c);
		cout << endl;

	}
	return 0;
}
输入
第一行是个整数，表示输入数据组数
每组数据一行,有12个整数
输出
对每组数据, 将12个整数从小到大排序并去除重复元素后输出
样例输入
2
34 5 4 6 3 9 8 34 5 3 3 18
31 2 4 6 2 9 8 31 5 3 3 18
样例输出
3 4 5 6 8 9 18 34 
2 3 4 5 6 8 9 18 31 
提示
注意：行末都有一个空格
*/

#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	int  a[100];
	cin >> t;
	while(t--) {
		for(int i = 0;i < 12; ++i)
			cin >> a[i];
// 在此处补充你的代码
        set<int> b;
        for(int i=0;i<12;++i) b.insert(a[i]);
        for(int i : b) cout<<i<<" ";
        int c[100];
        
        std::copy(b.begin(), b.end(), c);
		cout << endl;
	}
	return 0;
}