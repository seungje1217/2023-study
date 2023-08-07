# 문자열을 입력받아 모음을 없애고 자음을 출력

n="" # 문자열을 입력받기 위한 변수
n_1="" # 자음 문자열

vowels="aeiouAEIOU" # 모음을 비교하기위한 변수

n=input("영어 문자열을 입력하세요 : ")

for i in n:
    # in -> 포함되어진 것을 확인
    #not in -> 포함되지 않은 것을 확인
    if (i in vowels) :
        print("모음 : "+ i)
        continue  # 모음이라면 반복문 처음으로 이동

    else:
        n_1+=i  # 자음이라면 문자열 추가

print("모음을 제회한 문자열 (자음) : " + n_1)