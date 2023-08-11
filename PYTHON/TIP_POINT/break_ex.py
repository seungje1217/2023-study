while (1):
    n1=int(input("첫 번째 정수를 입력하세요 : "))
    if n1==0:
        print("첫 번째 정수가 0이 입력되어 프로그램을 종료합니다.")
        break
    n2=int(input("두 번째 정수를 입력하세요 : "))
    sum=n1+n2
    print("%d + %d = %d" % (n1,n2,sum))