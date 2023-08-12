n="김유덕, 이종표, 이재용, 박성호, 김성호, 최용수, 이성진, 박서영, 전경연, 송환수, 이재성, 김성호, 이성호, 박주상, 김성호"

listn=n.split(", ") # ,와 공백으로 분리

# listn=["김유덕", "이종표", "이재용", "박성호", "김성호", "최용수", "이성진", "박서영", "전경연", "송환수", "이재성", "김성호", "이성호", "박주상", "김성호"]

print("1) 15명 명단 출력 :\n" + str(listn))

print("\n2) '김성호'란 이름은 몇 번 반복했는가? : "+str(listn.count("김성호")))

slistn=[] # 중복 제거된 값 리스트
for value in listn:
    if value not in slistn:
        slistn.append(value)
print("\n3) 중복된 이름을 제거한 이름 출력 :\n"+str(slistn))

# slistn=list(set(listn))
# print("\n3) 중복된 이름을 제거한 이름 출력 :\n"+str(slistn))

slistn.sort()
print("\n4) 중복된 성명을 제거한 이름들 오름차순 정렬 후 출력 :\n"+str(slistn))