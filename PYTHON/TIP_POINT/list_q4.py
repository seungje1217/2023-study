listn=[]
n5=0 # 5의 배수
sum5=0 # 5의 배수 합
aver5=0.0 # 5의 배수 평균

print("0을 입력하면 프로그랩 종료합니다.")
while (1):
    n=int(input("정수를 입력하세요 : "))

    if n==0:
        print("\n0을 입력하면 프로그랩 종료합니다.\n")
        break

    if n%5==0:
        listn.append(n)
        sum5+=n
        n5+=1

if n5 > 0: # 5의 배수가 있어야지 평균이 존재
    aver5 = sum5 / n5

print("입력 되어진 값 중 5의 배수 갯수 : %d\n" % n5)
print("5의 배수 합계 : %d" % sum5)
print("5의 배수 평균 : %.1f" % aver5)