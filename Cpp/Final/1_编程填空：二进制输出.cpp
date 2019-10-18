/*
001:编程填空：二进制输出
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给出一个int表示范围内的正整数x，输出其二进制表示。一共要输出31位，不足处要补0。

#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
// 在此处补充你的代码
}
int main(){
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}
输入
第一行是整数n(n<15)，表示有n个正整数要处理
第二行是n个正整数
输出
对每个给出的正整数，输出其二进制表示。不足31位则用0补齐到31位
样例输入
3
1 2 3
样例输出
0000000000000000000000000000001
0000000000000000000000000000010
0000000000000000000000000000011
*/

#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
// 在此处补充你的代码
    string s(31,'0');
    int i=30;
    while(x){
        s[i--]=x%2?'1':'0';
        x/=2;
    }
    return s;
}
int main(){
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}