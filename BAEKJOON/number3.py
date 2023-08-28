# 가장 단순

n = int(input())
a = input().split()
v = int(input())

count = a[::2].count(str(v))
print(count)
