# 별찍기

a=int(input("숫자입력:"))
for i in range(1,a+1):
    print(" "*(a-i),"*"*i+"*"*(i-1))
for x in range(a-1,0,-1):
    print(" "*(a-x),"*"*x+"*"*(x-1))