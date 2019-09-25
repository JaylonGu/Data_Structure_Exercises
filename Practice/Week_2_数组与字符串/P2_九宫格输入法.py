keyborad=["0 ","1,.?!","2ABC","3DEF","4GHI","5JKL","6MNO","7PQRS","8TUV","9WXYZ"]
str=input().split()
for s in str:
    o=keyborad[int(s[0])]
    print(o[(len(s)-1)%(len(o))],end="")