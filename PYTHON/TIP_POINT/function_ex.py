# 함수 선언 - 더하기
def calc_Plus(n1,n2):
    result=n1+n2

    return result

# 변수 선언
sumVal=0     # 합계 저장 변수
numVal1=0    # 입력값 저장
numVal2=0    # 입력값 저장

numVal1=int(input("정수 1 입력 : "))
numVal2=int(input("정수 2 입력 : "))

sumVal=calc_Plus(numVal1,numVal2)

print("입력한\n정수 1 : %d\n정수 2 : %d\n더한 결과값 : %d입니다." % (numVal1,numVal2,sumVal))
