# 윤년 계산
y=int(input("연도를 입력하세요 : "))

if (y%4==0 and 100%y!=0) or 400%y==0:
    print("%d년은 윤년입니다." % y)

else:
    print("%d년은 평년입니다." % y)
