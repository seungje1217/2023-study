# 1이상의 정수 입력하여 약수 출력

n=int(input("정수 입력 : "))

while n < 1: # 1이하의 수를 입력했을 때
    print("1 이상의 정수를 입력하세요.")
    n = int(input("정수 입력: "))

for i in range(1, n + 1): # 1부터 n까지
    if n % i == 0:
        print(i)
