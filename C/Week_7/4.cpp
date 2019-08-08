/*
004:最长最短单词
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入1行句子（不多于200个单词，每个单词长度不超过100），只包含字母、空格和逗号。单词由至少一个连续的字母构成，空格和逗号都是单词间的间隔。

试输出第1个最长的单词和第1个最短单词。 

输入
一行句子。
输出
两行输出：
第1行，第一个最长的单词。
第2行，第一个最短的单词。
样例输入
I am studying Programming language C in Peking University
样例输出
Programming
I
提示
如果所有单词长度相同，那么第一个单词既是最长单词也是最短单词。
*/

#include <iostream>
#include <cstring>
using namespace std;

struct S{
    char c[100];
};

int main(){
    struct S s[200];
    int n=0;
    while(cin>>s[n++].c);
    n--;
    int i;
    int max=0,min=0;
    int longest=strlen(s[max].c), shortest=strlen(s[min].c);
    for(i=1;i<n;++i){
        if(strlen(s[i].c)>longest){
            longest=strlen(s[i].c);
            max=i;
        }
        if(strlen(s[i].c)<shortest){
            shortest=strlen(s[i].c);
            min=i;
        }
    }
    cout<<s[max].c<<endl<<s[min].c;
    return 0;
}
