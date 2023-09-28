# csv 파일 읽기 -> 강수량 높은날 출력
import csv

f = open('seoul_rain_csv.csv', encoding='cp949')
data = csv.reader(f)
next(data)
rain = []

for row in data:
    cut = row[0].split('-')
    year = int(cut[0])
    month = int(cut[1])
    day = int(cut[2])
    rainfall = float(row[2]) 
    rain.append((year, month, day, rainfall))


sorted_rain = sorted(rain, key=lambda x: x[3], reverse=True)

for i, (year, month, day, rainfall) in enumerate(sorted_rain[:3]):
    print(f"강수량{i + 1}번째로 높은 날 : {year}년 {month}월 {day}일 - 강수량: {rainfall} mm")
