Y=int(input("연도 입력 : "))
M=int(input("월 입력 : "))

if ( M == 4 or 6 or 9 or 11  ) :
    print("%d년 %d월은 1~30일 까지 있습니다." % (Y,M))
elif ( M == 2 ) :
    if (Y % 4 == 0 and 100 % Y != 0) or 400 % Y == 0:
        print("%d년 %d월은 1~29일 까지 있습니다." % (Y,M))
    else :
        print("%d년 %d월은 1~28일 까지 있습니다." % (Y,M))
else :
    print("%d년 %d월은 1~31일 까지 있습니다." % (Y,M))
