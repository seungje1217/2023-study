"""for문 사용"""
n = int(input("정수 입력: "))
dictn = {}

for i in range(1, n+1): # 1부터 입력받은 정수까지
    dictn[i] = i ** 2

print("딕셔너리(사전)에 입력된 값 :\n" + str(dictn))

""" while문 사용

num=0
cntV=1
dictV=dict()

num=int(input("정수 입력: "))

while (cntV<=num):
    dictV[cntV]=cntV**2
    cntV+=1

print("딕셔너리(사전)에 입력된 값 :\n" + str(dictV))
"""