numV=0 # 입력 값 저장
sumV=0 # 합계
avgV=0.0 # 평균
stV=0 # 80점 이상 학생 수

listV=[] # 리스트 생성 및 초기화

for i in range(0,5):
    numV=int(input(str(i+1)+"번째 학생의 성적을 입력하세요 : "))
    listV.append(numV)
    sumV+=numV

    if numV>=80:
        stV+=1

avgV=sumV/len(listV)

print("지정된 리스트 값 : " +str(listV))
print("="*30)
print("\n성적 합계 : "+ str(sumV))
print("평균 합계 : "+str(avgV))
print("성적이 80점 이상인 학생 수 : "+str(stV))

#
#
# s1 = int(input("1 번째 학생의 성적을 입력하세요 : "))
# s2 = int(input("2 번째 학생의 성적을 입력하세요 : "))
# s3 = int(input("3 번째 학생의 성적을 입력하세요 : "))
# s4 = int(input("4 번째 학생의 성적을 입력하세요 : "))
# s5 = int(input("5 번째 학생의 성적을 입력하세요 : "))
#
# slist = [s1, s2, s3, s4, s5]
# print("저장된 리스트 값:", slist)
# print("=" * 30)
#
# sum = s1 + s2 + s3 + s4 + s5
# print("성적 합계 : %d" % sum)
#
# aver = sum / 5
# print("평균 합계 : %.1f" % aver)
#
# st_num=0 # 80점 이상인 학생 수 변수
#
# for score in slist:
#     if score >= 80:
#         st_num+=1
# print("성적이 80점 이상인 학생 수 : %d" % st_num)
