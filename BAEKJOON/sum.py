# n을 입력받아서 1부터 n까지의 합을 구하기

sum=0
i=1
n=int(input())

while i<=n:
    sum+=i
    i+=1

print(sum)