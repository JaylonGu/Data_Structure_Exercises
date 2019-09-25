'''
代码格式如下：
def prime(num):
        ...
def monisen(no):
        … …
        return  xxx

print(monisen(int(input())))    # 此处输入由系统自动完成不需要自己输入，只要写这样一条语句即可（3分）
题目内容：

找第n个默尼森数。P是素数且M也是素数，并且满足等式M=2^P-1，则称M为默尼森数。例如，P=5，M=2^P-1=31，5和31都是素数，因此31是默尼森数。

输入格式: 

按提示用input()函数输入

输出格式：

int类型

输入样例：

4

输出样例：

127
'''

import math

def prime(num):
    if num<2:
        return False
    else:
        for i in range(2,num):
            if num%i==0:
                return False
        return True

def monisen(no):
    i=0
    P=2
    M=0
    while i<no:
        M=2**P-1
        if(prime(P) and prime(M)):
            i+=1
        P+=1
    return  M

print(monisen(int(input()))) 