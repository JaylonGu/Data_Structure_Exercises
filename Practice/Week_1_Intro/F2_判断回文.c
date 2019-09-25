/*
如果一串字符从左至右读和从右至左读相同，那么这串字符就是回文（Palindrome）。例如，ABCBA是回文，而ABCD则不是。本题要求编写一个判断字符串是否为回文的函数，并且通过函数参数获取字符串的中间字符（如果中间是两个字符，则获取靠左的那一个，例如字符串是ABCDEF，则中间字符是C）。题目保证输入的字符串长度在1至2000之间且不含空格、换行等分隔符。

函数接口定义：
int isPalindrome(const char* str, char* pch);
其中 str 和 pch 都是用户传入的参数。 str 是字符串的首地址； pch 是传入的要存放字符串中间字符的变量的地址。如果字符串是回文，函数须返1，否则返回0。

裁判测试程序样例：
测试程序仅为示例，实际的测试程序可能不同
#include <stdio.h>
#include <string.h>
#define MAXLENGTH 100
int isPalindrome(const char* str, char* pch);
int main(){
    char str[MAXLENGTH],mid;
    scanf("%s",str);
    if(isPalindrome(str, &mid))
        printf("是回文！中间字符是%c\n",mid);
    else
        printf("不是回文！中间字符是%c\n",mid);
    return 0;
}

你编写的函数代码将被嵌在这里
输入样例：
ABCDACBC
输出样例：
不是回文！中间字符是D
*/

#include <stdio.h>
#include <string.h>
#define MAXLENGTH 100
int isPalindrome(const char* str, char* pch);
int main(){
    char str[MAXLENGTH],mid;
    scanf("%s",str);
    if(isPalindrome(str, &mid))
        printf("是回文！中间字符是%c\n",mid);
    else
        printf("不是回文！中间字符是%c\n",mid);
    return 0;
}

int isPalindrome(const char* str, char* pch){
    int len=strlen(str);
    *pch=*(str+(len-1)/2);
    char *left=str, *right=str+len-1;
    while(left<=right){
        if(*left==*right) {
            // printf("%c %c\n",*left,*right);
            left++;
            right--;
            continue;
        }
        else return 0;
    }
    return 1;
}