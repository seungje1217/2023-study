# 사칙연산 입력 계산
def calcul(n1,n2,cal):
    if cal=="+":
        result=n1+n2
    elif cal=="-":
        if n1>n2:
            result=n1=n2
        elif n1==n2:
            result=0
        else:
            result=n2-n1
    elif cal=="*":
        result=n1*n2
    else:
        if n1>n2:
            result=n1/n2
        elif n1==n2:
            result=1
        else:
            Val=n2/n1
    return result



# 변수 선언
VAL=0        # 계산 변수
numVal1=0    # 입력값 저장
numVal2=0    # 입력값 저장

cal=input("계산하고자 하는 사칙 연산자 (+, -, *, / )입력 : ")

numVal1=int(input("정수 1 입력 : "))
numVal2=int(input("정수 2 입력 : "))

VAL=calcul(numVal1,numVal2,cal)

print("입력하신 연산자로 계산한 결과 : %d 입니다." % VAL)