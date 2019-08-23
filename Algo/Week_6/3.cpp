/*
003:最佳加法表达式
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36

输入
有不超过15组数据
每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
第二行是若干个数字。数字总数n不超过50,且 m <= n-1
输出
对每组数据，输出最小加法表达式的值
样例输入
2
123456
1
123456
4
12345
样例输出
102
579
15
提示
要用到高精度计算，即用数组来存放long long 都装不下的大整数，并用模拟列竖式的办法进行大整数的加法。
*/

#include <iostream>
#include <cstring>
using namespace std;

class BigInt
{
public:
	int num[110];
	int len;

	BigInt operator+(const BigInt & n) { //重载+，使得 a + b在 a,b都是 BigInt变量的时候能成立
		int ml = max(len,n.len);
		int carry = 0; //进位 
		BigInt result;
		for(int i = 0;i < ml; ++i) {
			result.num[i] = num[i] + n.num[i] + carry;
			if( result.num[i] >= 10) 	{
				carry = 1;
				result.num[i] -= 10;
			}
			else
				carry = 0;
		}
		if ( carry == 1) {
			result.len = ml + 1;
			result.num[ml] = 1;
		}
		else 
			result.len = ml;
		return result;
	}

	bool operator<(const BigInt & n) {
		if( len > n.len )
			return false;
		else if( len < n.len)
			return true;
		else {
			for(int i = len -1; i >= 0; -- i) {
				if( num[i] < n.num[i])
					return true;
				else if( num[i] > n.num[i])
					return false;
			}
			return false;
		}
	}

	BigInt() {
		len = 1;
		memset(num,0,sizeof(num));
	}

	BigInt(const char * n,int L) { //由长度为L的char数组构造大整数。n里面的元素取值范围从 1-9。 
		memset(num,0,sizeof(num));
		len = L;
		for(int i = 0; n[i]; ++i)
			num[len-i-1] = n[i] - '0';
	}
};

ostream & operator <<(ostream & o,const BigInt & n) 
{
	
	for(int i = n.len - 1;i >= 0; --i)
		o << n.num[i];
	return o;
}

const int MAXN  = 53;
char a[MAXN];
BigInt Num[MAXN][MAXN];//Num[i][j]表示从第i个数字到第j个数字所构成的整数 
BigInt V[MAXN][MAXN]; //V[i][j]表示i个加号放到前j个数字中间，所能得到的最佳表达式的值。 

int main()
{
	int m,n;
	BigInt inf; //无穷大 
	inf.num[MAXN-2] = 1;
	inf.len = MAXN-1;

	while(cin >> m ) {
		cin >> a+1;
		n = strlen(a+1);
		for(int i = 1;i <= n; ++i) // 存储从i到j的数字
			for(int j = i;j<= n; ++j) {
				Num[i][j] = BigInt(a+i,j-i+1);  
			}
        
		for(int j = 1; j <= n; ++j)  {
			V[0][j] = BigInt(a+1,j);
		}
		
		for(int i = 1;i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				if( j - 1 < i) 
					V[i][j] = inf;
				else {
					BigInt tmpMin = inf;
					for(int k = i; k < j; ++k) {
						BigInt tmp = V[i-1][k] + Num[k+1][j]; 
						if (tmp < tmpMin)
							tmpMin = tmp;
					}
					V[i][j] = tmpMin;
				}
			}
		}

		cout << V[m][n] << endl;
	}
	return 0;
}