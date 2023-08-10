dictV={}
print(type(dictV))

dictV["자두"]="안녕 자두야"
"""
dictV["짱구는 못말려"]="짱구"
dictV["짱구는 못말려"]="훈이"
# 딕셔너리는 키 값이 중복되지 않기에 짱구 -> 훈이로 바뀜 (키값 변경)
"""

dictV["짱구"]="짱구는 못말려"
dictV["탄지로"]="귀멸의 칼날"
dictV["도라에몽"]="도라에몽"
dictV["양파쿵야"]="쿵야쿵야"

print(dictV["짱구"])
print(dictV.get("양파쿵야"))

print(dictV.keys())
print(list(dictV.keys()))

for i in list(dictV.keys()):
    print(i+" : "+dictV[i])

print(dictV.values())
print(list(dictV.values()))

print(dictV.items()) # 투플 형태 값 출력 -> (소괄호) 읽기 전용

print("자두"in dictV)
print("코난"in dictV)