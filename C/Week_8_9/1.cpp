/*
001:指针练习：输出Hello
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
下面程序片段的输出结果是 Hello ,请填空

#include <iostream>
using namespace std;
int main() {
	char s[] = "Hello";  
	char * p;
	for(
// 在此处补充你的代码
)
		cout << * p ;
	return 0;
}
输入
无
输出
Hello
样例输入
无
样例输出
Hello
*/

#include <iostream>
using namespace std;
int main() {
	char s[] = "Hello";  
	char * p;
	for(
// 在此处补充你的代码
    p=s;*p;p++
)
		cout << * p ;
	return 0;
}