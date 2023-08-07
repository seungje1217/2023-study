n = int(input("과목수 입력 : "))

# 과목수는 10개 이하
if 0 < n < 11:  # if (n>0 and n<11):
    sum = 0 # sum 초기화
    for i in range(n):
        score = float(input(str(i + 1) + "번째 점수 입력 : "))
        sum += score  # sum = sum + score

    average = sum / n

    if average >= 80:
        print("합격")
    else:
        print("불합격")

else:
    print("과목수는 0이상 10이하의 수만 가능합니다")
