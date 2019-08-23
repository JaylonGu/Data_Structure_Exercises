/*
002:Zipper
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Given three strings, you are to determine whether the third string can be formed by combining the characters in the first two strings. The first two strings can be mixed arbitrarily, but each must stay in its original order.

For example, consider forming "tcraete" from "cat" and "tree":

String A: cat
String B: tree
String C: tcraete

As you can see, we can form the third string by alternating characters from the two strings. As a second example, consider forming "catrtee" from "cat" and "tree":

String A: cat
String B: tree
String C: catrtee

Finally, notice that it is impossible to form "cttaree" from "cat" and "tree".
输入
The first line of input contains a single positive integer from 1 through 1000. It represents the number of data sets to follow. The processing for each data set is identical. The data sets appear on the following lines, one data set per line.

For each data set, the line of input consists of three strings, separated by a single space. All strings are composed of upper and lower case letters only. The length of the third string is always the sum of the lengths of the first two strings. The first two strings will have lengths between 1 and 200 characters, inclusive.
输出
For each data set, print:

Data set n: yes

if the third string can be formed from the first two, or

Data set n: no

if it cannot. Of course n should be replaced by the data set number. See the sample output below for an example.
样例输入
3
cat tree tcraete
cat tree catrtee
cat tree cttaree
样例输出
Data set 1: yes
Data set 2: yes
Data set 3: no
*/

#include<iostream>
#include<cstring>
using namespace std;

const int MAXL=200;

int main(){
    int n;
    int dp[MAXL+1][MAXL+1];
    cin>>n;
    for(int cnt=1;cnt<=n;++cnt){
        char s1[MAXL+2],s2[MAXL+2],s[MAXL*2+2];
        cin>>s1+1>>s2+1>>s+1;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int len1=strlen(s1+1), len2=strlen(s2+1);
        
        for(int i=0;i<=len1;++i)
            for(int j=0;j<=len2;++j){
                if(i+j==0) continue;
                if(s1[i]==s[i+j]&&dp[i-1][j]) dp[i][j]=1;
                if(s2[j]==s[i+j]&&dp[i][j-1]) dp[i][j]=1;
            }

        cout<<"Data set "<<cnt<<": ";
        if(dp[len1][len2])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

    return 0;
}