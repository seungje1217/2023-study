# 섭씨 화씨로 변환
def change_fahrenheit(cel):
    result=(cel*(9/5)+32)
    return result


celsius=float(input("화씨 온도로 변환할 섭씨 온도를 입력해 주세요 : "))

fahrenheit=change_fahrenheit(celsius)

print("입력한 섭씨 온도 : %.1f 를 화씨 온도로 변환한 값은 : %.1f" % (celsius,fahrenheit))