/*
09:行程长度编码
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
在数据压缩中，一个常用的途径是行程长度压缩。对于一个待压缩的字符串而言，我们可以依次记录每个字符及重复的次数。这种压缩，对于相邻数据重复较多的情况比较有效。 例如，如果待压缩串为"AAABBBBCBB"，则压缩的结果是(A,3)(B,4)(C,1)(B,2)。当然，如果相邻字符重复情况较少，则压缩效率就较低。

现要求根据输入的字符串，得到大小写不敏感压缩后的结果（即所有小写字母均视为相应的大写字母）。

输入
一个字符串，长度大于0，且不超过1000，全部由大写或小写字母组成。
输出
输出为一行，表示压缩结果，形式为：
(A,3)(B,4)(C,1)(B,2)
即每对括号内部分别为字符（都为大写）及重复出现的次数，不含任何空格。
样例输入
aAABBbBCCCaaaaa
样例输出
(A,3)(B,4)(C,3)(A,5)
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[1001];
    cin>>s;
    int len=strlen(s);
    int cnt=1;
    for(int i=1;i<len;i++){
        if(s[i]==s[i-1] || abs(s[i]-s[i-1])=='a'-'A') cnt++;
        else{
            s[i-1]=(s[i-1]>='A' && s[i-1]<='Z')? s[i-1]: (s[i-1]+'A'-'a');
            cout<<'('<<s[i-1]<<','<<cnt<<')';
            cnt=1;
        }
    }
    s[len-1]=(s[len-1]>='A' && s[len-1]<='Z')? s[len-1] : (s[len-1]+'A'-'a');
    cout<<'('<<s[len-1]<<','<<cnt<<')';
    return 0;
}