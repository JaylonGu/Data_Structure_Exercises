/*
到底应该怎样理解进制呢？首先得有“一个”的数量概念，然后就是这样的：
把用来表示数量的符号依次排列，例如： q w e r
然后定义最前面的符号为“零”，即“没有”，后面的符号表示的数量依次比前一个符号多“一个”
进制就这样产生了： 例如当我们数数，依次数到 q w e r ，再往后数一个，符号不够用了，那么就写成 wq
并且，我们把这种进制命名为“wq”进制。
感觉怪异吗？ 那么请换成我们熟悉的所谓“10”进制看看：
我们的用于表示数量的符号依次是： 0 1 2 3 4 5 6 7 8 9 ， 当数到9，再往后数“一个”时，就数到了 10

现在，给定表示数量的符号（这些符号就形成了某种进制），以及该种进制下的两个不超过100位的正整数，请计算两数之和。

输入格式:
第一行给定表示数量的符号，每个符号为一个字符、各不相同且中间没有空格，最多有30个符号且符号的可能范围是：数字0-9、大小写字母、!、@、#、$、%、^、&、*、(、)
接下来两行每行给出一个该进制下的不超过100位的正整数

输出格式:
在一行中输出该进制下的两数之和。

输入样例1:
0123456789
123
12
输出样例1:
135
输入样例2:
abcd
bcd
bc
输出样例2:
cab
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s;
    cin>>s;
    string s1,s2;
    cin>>s1>>s2;
    int l=s.length(), l1=s1.length(), l2=s2.length();
    int carry=0;
    int num[101]={0};

    for(int i=0, i1=l1-1, i2=l2-1; i1>=0 && i2>=0; --i1, --i2, ++i){
        num[i]=s.find(s1[i1])+s.find(s2[i2])+carry;
        // cout<<"i="<<i<<"num="<<num[i]<<endl;
        carry=num[i]/l;
        num[i]=num[i]%l;
    }

    if(l1>l2){
        for(int i=l2, i1=l1-l2-1; i1>=0 ; --i1,++i){
            num[i]=s.find(s1[i1])+carry;
            carry=num[i]/l;
            num[i]=num[i]%l;
        }
    }else if(l1<l2){
        for(int i=l1, i2=l2-l1-1; i2>=0 ; --i2,++i){
            num[i]=s.find(s1[i2])+carry;
            carry=num[i]/l;
            num[i]=num[i]%l;
        }
    }else{
        num[l1]=carry;
    }
    
    int end=num[max(l1,l2)] ? max(l1,l2): (max(l1,l2)-1);

    for(int i=end; i>=0;--i){
        cout<<s[num[i]];
    }
    cout<<endl;
    return 0;
}