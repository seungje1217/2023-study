# 수를 입력받아 소수인지 판별

while True:
    n = int(input("정수 입력 : "))

    if n == 0:
        print("Exit")
        break
    elif n == 1:
        print("1이상의 정수를 입력하세요.")
        continue
    else:
        decimal = True
        for i in range(2, n):
            # n이 2인 경우에는 for문 실행 x -> 바로 True
            if n % i == 0:
                decimal = False
                break

        if decimal: # True인 경우
            print("%d -> 소수" % n)
        else: # False인 경우
            print("%d -> 소수x." % n)
