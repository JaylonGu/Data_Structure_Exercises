'''
输入格式:
无

输出格式:
输出一句短语，Python语言简单易学。

如果包含汉字，用"print(s.encode("utf-8"))"输出.

如：

     s="人生苦短，我学Python"  
     print(s.encode("utf-8"))
输入样例:
无
输出样例:
"人生苦短，我学Python" 的输出：

b'\xe4\xba\xba\xe7\x94\x9f\xe8\x8b\xa6\xe7\x9f\xad\xef\xbc\x8c\xe6\x88\x91\xe5\xad\xa6Python'
'''

s="Python语言简单易学"  
print(s.encode("utf-8"))