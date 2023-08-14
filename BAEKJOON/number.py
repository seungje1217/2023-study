# 개수 세기
N = int(input())
# 한 줄로 들어오는 수열을 int list로 만드는 경우가 많이 있는데,
# 코드는 다음과 같이 작성할 수 있습니다.
num = list(map(int, input().split()))
# 또는 num = [int(x) for x in input().split()]로 작성할 수 있습니다.
v = int(input())
# 리스트에서 특정 값의 개수는 다음과 같이 구합니다.
print(num.count(v))