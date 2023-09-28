# csv 파일 읽기 -> 가뭄 최대 일자 구하기
import csv

f = open('seoul_rain_csv.csv', encoding='cp949')
data = csv.reader(f)
next(data)

rain = []
current_drought = 0
longest_drought = 0
longest_drought_start = None
longest_drought_end = None

for row in data:
    cut = row[0].split('-')
    year = int(cut[0])
    month = int(cut[1])
    day = int(cut[2])
    rainfall = float(row[2])

    if rainfall == 0:
        current_drought += 1
        if current_drought == 1:
            drought_start = (year, month, day)
        if current_drought > longest_drought:
            longest_drought = current_drought
            longest_drought_start = drought_start
            longest_drought_end = (year, month, day)
    else:
        current_drought = 0

if longest_drought_start:
    start_year, start_month, start_day = longest_drought_start
    end_year, end_month, end_day = longest_drought_end
    print(f"역대 가뭄이 가장 길었던 날: {start_year}년 {start_month}월 {start_day}일부터 {end_year}년 {end_month}월 {end_day}일까지, 연속 {longest_drought}일 동안 강수량 0 mm")
print("\n임승제")
