val="자격증, 여행, 토익, 독서, 알바"

val=[]
val_1=list()
val_2=["자격증", "여행"]

# print(val)
# print(val_1)
# print(val_2)
# print(val_2[1])

for i in val_2:
    print(i)


cnt=len(val_2)-1
print("val_2에 저장된 값을 출력 (while) ")
while (cnt>=0):
    print("val_2["+str(cnt)+"] : " + val_2[cnt])

    cnt-=1

# 리스트에서 값을 수정하는 방법
# 변수명[ 위치번호 ] = 값
# index() --> 값의 위치를 확인하기 위한 방법
#         --> 값이 중복될 때, 제일 처음 만나는 값의 위치만 확인 가능

# count() --> 리스트의 값 중에서 해당되는 값이 있는지 확인
#         --> 만약, 값이 있다면 해당되는 개수를 출력. 값이 없다면 0 출력.

val_2.append("여행")
print(val_2.index("여행"))
print(val_2.count("토익"))
# print(val_2.index("토익"))      오류남

val_2[val_2.index("여행")] = "토익"
print(val_2)


# val_2.remove("토익")
# print(val_2)
#
# print(val_2.pop())
# print(val_2)
#
# if (val_2.count("토익")>0):
#     del (val_2[val_2.index("토익")])
#     val_2.remove("토익")


val_2.append("방학")
val_2.reverse()
print(val_2)

sortV=sorted(val_2)
print("정렬 : "+str(sortV))
print("기존 : "+str(val_2))

