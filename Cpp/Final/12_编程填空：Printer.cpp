/*
012:编程填空：Printer
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
完成以下程序，使得输入的整数x，以及若干正整数，将
大于x的正整数输出；然后输入若干字符串，将字符串长度大于x的字符串输出

#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;


class Printer{
// 在此处补充你的代码
int main(){

	int t;
	cin >> t;
	while(t--) {
		int n,x;
		cin>>x>>n;
		
		vector<int> intVec;
		for(int i = 0;i < n; ++i) {
			int y;
			cin >> y;
			intVec.push_back(y);
		}
		for_each(intVec.begin(), intVec.end(), Printer(x));
		cout<<endl;
		
		vector<string> strVec;
		for(int i = 0;i < n; ++i) {
			string str;
			cin >> str;
			strVec.push_back(str);
		}
		for_each(strVec.begin(), strVec.end(), Printer(x));
		cout<<endl;
	}
	return 0;
}
输入
第一行是整数t，表示一共t组数据
每组数据有三行
第一行是整数x和整数 n
第二行是n个整数
第三行是n个不带空格的字符串
输出
对每组数据
先按原序输出第一行中大于x的正整数(数据保证会有输出）
再按原序输出第二行中长度大于x的字符串 (数据保证会有输出）
样例输入
2
5 6
1 3 59 30 2 40
this is hello please me ha
1 1
4
this
样例输出
59,30,40,
please,
4,
this,
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;


class Printer{
// 在此处补充你的代码
    int x;
public:
    Printer(int _x):x(_x){}
    void operator () (int y){
        if(y>x) cout<<y<<",";
    }
    void operator () (string s){
        if(s.length()>x) cout<<s<<",";
    }
};

int main(){

	int t;
	cin >> t;
	while(t--) {
		int n,x;
		cin>>x>>n;
		
		vector<int> intVec;
		for(int i = 0;i < n; ++i) {
			int y;
			cin >> y;
			intVec.push_back(y);
		}
		for_each(intVec.begin(), intVec.end(), Printer(x));
		cout<<endl;
		
		vector<string> strVec;
		for(int i = 0;i < n; ++i) {
			string str;
			cin >> str;
			strVec.push_back(str);
		}
		for_each(strVec.begin(), strVec.end(), Printer(x));
		cout<<endl;
	}
	return 0;
}