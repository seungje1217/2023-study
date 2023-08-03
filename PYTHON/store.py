iceP=1000
noodleP=1500
snackP=2000
breadP=1500

ice=int(input("아이스크림의 개수 : "))
noodle=int(input("라면의 개수 : "))
snack=int(input("과자의 개수 : "))
bread=int(input("빵의 개수 : "))

totalP=ice*iceP+noodle*noodleP+snack*snackP+bread*breadP

print("총 금액 : %d" % totalP)
# print("총 금액 :", totalP)