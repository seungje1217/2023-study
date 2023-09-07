n = int(input())
a = input()
v = int(input())

sum = 0
for i in range(0, len(a), 2):
    if int(a[i]) == v:
        sum += 1
print(sum)