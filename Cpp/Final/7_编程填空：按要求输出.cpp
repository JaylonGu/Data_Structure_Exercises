/*
007:编程填空：按要求输出
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
下列程序的输出为"10 13 18 15 17 12 16 19",  请补充代码



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
int  a[10] = {0, 6, 7, 3, 9, 5, 8, 6, 4, 9};
int  b[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int main(int argc, char** argv) {
// 在此处补充你的代码
for(int i=0; i<10; i++) 
		c[a[i]] = b[i];
	for(it=c.begin(); it!=c.end(); it++) 
		cout<<it->second<<" ";
	return 0;
}
输入
无
输出
10 13 18 15 17 12 16 19
样例输入
None
样例输出
10 13 18 15 17 12 16 19
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
int  a[10] = {0, 6, 7, 3, 9, 5, 8, 6, 4, 9};
int  b[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int main(int argc, char** argv) {
// 在此处补充你的代码
    map<int,int> c;
    map<int,int>::iterator it;

    for(int i=0; i<10; i++) 
		c[a[i]] = b[i];
	for(it=c.begin(); it!=c.end(); it++) 
		cout<<it->second<<" ";
	return 0;
}