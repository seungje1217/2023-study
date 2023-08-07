# 양의 정수 덧셈 / 0입력 시 프로그램 종료
while (1):
    n1 = int(input("정수 입력 : "))
    if n1==0:
        break
    n2 = int(input("정수 입력 : "))
    if n2 == 0:
        break
    else:
        sum=n1+n2
        print("%d + %d = %d" % (n1,n2,sum))