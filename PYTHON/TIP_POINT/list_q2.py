dog_n="" # 강아지 이름 변수

listD=[] # 리스트 생성

while (1):
    dog_n=input("강아지 이름 입력 : ")

    if dog_n=="": # 공백 입력 시 프로그램 종료
        break
    else:
        listD.append(dog_n)

print("\n===== 출력 =====")
for i in range(0,len(listD)):
    print(str(i+1)+"번째 강아지 이름 : "+str(listD[i]))

print("\n리스트에 저장된 값 : " + str(listD))

