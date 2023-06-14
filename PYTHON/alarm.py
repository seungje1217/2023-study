a=int(input("시:"))
b=int(input("분:"))

if b>=45:
    b-=45
elif b<45:
    a-=1
    b=b+60-45
elif a==0 and b<45:
    a=23
    b += b + 60 - 45
print(f"{a} {b}")