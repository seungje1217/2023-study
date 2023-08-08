# 튜플 실습 2
tupleDog=('플루토','구피','피피')

q=str(input("찾으실 애완견 이름을 입력하세요 : "))
if q in tupleDog:
    print("%s는 나의 애완견입니다." % q)
else:
    print("%s는 나의 애완견이 아닙니다."% q)