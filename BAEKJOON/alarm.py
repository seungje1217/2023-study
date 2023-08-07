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


# def change_alarm(hour, minute):
#     minute -= 45
#     if minute < 0:
#         hour -= 1
#         minute += 60

#     if hour < 0:  # 시간이 음수가 되면 시간을 23으로 바꿔줌
#         hour = 23

#     return hour, minute

# H = input("시간 : ")
# if H.isdigit():
#     hour = int(H)
#     if 0 <= hour <= 23:
#         pass
#     else:
#         print("시간이 맞지 않습니다. 0부터 23 사이의 숫자를 입력해주세요.")
#         exit()
# else:
#     print("숫자를 입력해주세요.")
#     exit()

# M = input("분 : ")
# if M.isdigit():
#     minute = int(M)
#     if 0 <= minute <= 59:
#         pass
#     else:
#         print("분이 맞지 않습니다. 0부터 59 사이의 숫자를 입력해주세요.")
#         exit()
# else:
#     print("숫자를 입력해주세요.")
#     exit()

# hour, minute = change_alarm(hour, minute)

# print("변경된 알람 시각: %02d:%02d" % (hour, minute))
