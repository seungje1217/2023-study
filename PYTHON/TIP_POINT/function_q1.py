def calc_Minus(n1,n2):
    if n1>n2:
        result=n1-n2
    elif n1==n2:
        result=0
    else:
        result=n2-n1

    return result

# 변수 선언
minusVal=0     # 차이 저장 변수
numVal1=0    # 입력값 저장
numVal2=0    # 입력값 저장

numVal1=int(input("정수 1 입력 : "))
numVal2=int(input("정수 2 입력 : "))

minusVal=calc_Minus(numVal1,numVal2)

print("입력한 정수 중 큰 수에서 작은 수를 뺀 결과\n입력한 정수 : %d, %d 를 뺀 결과 : %d 입니다." % (numVal1,numVal2,minusVal))