
while (1):
    n = int(input("입력받을 갯수를 입력해주세요 : "))
    if n>20:
        print("20 이하의 정수를 입력해주세요.")
        continue
    else:
        break

listn=[]
print()

for i in range(n):
    nV=int(input(str(i+1)+"번째 점수를 입력해주세요 : "))
    listn.append(nV)

print("\n입력된 점수 : "+ str(listn))
listn.sort(reverse=True) # 높은 순으로 나열
print("높은 점수부터 정렬된 값 : "+ str(listn))
