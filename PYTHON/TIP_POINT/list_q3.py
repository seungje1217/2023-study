num3H=0 # 최대값
num3L=1000 # 최소값

listN=[]

while (1):
    num3=int(input("세 자리 이하의 정수 입력 : "))

    if num3>1000:
        print("999보다 작은 정수를 입력하세요.")
        continue
    elif num3==999:
        print("\n999가 입력되어 입력을 종료합니다.\n")
        break

    listN.append(num3) # 리스트에 입력받은 값 추가

    if num3 > num3H:
        num3H = num3
    elif num3 < num3L:
        num3L = num3

print("리스트에 입력되어진 값 : " + str(listN))
print("\n리스트에 입력된 최대값 : %d" % num3H)
print("리스트에 입력된 최소값 : %d" % num3L)