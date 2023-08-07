# 높이랑 반지름을 입력 받아서 부피와 면적 계산

height=float(input("높이 입력 : "))
radius=float(input("반지름 입력 : "))

V=3.14*radius*radius*height

A=((2*3.14*radius)*height)+((3.14*radius**2)**2)

print("부피 : %f" % V)

print("면적 : %f" % A)