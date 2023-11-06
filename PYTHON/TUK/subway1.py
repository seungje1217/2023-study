# 지하철 출근시간 승차 최대 인원
import csv
import pandas as pd

f = open('subway.csv', encoding='EUC-KR')
data = csv.reader(f) # csv 파일 읽어온 후 첫 두행 건너뜀 
next(data)
next(data)

station = {} # 승객 수를 저장하기 위한 빈 딕셔너리 초기화

for row in data:
    name = row[3]
    if name not in station:
        station[name] = 0
    for i in range(8, 15, 2):  # 출근시간 (6:00 AM ~ 10:00 AM) 승차 인원 
        row[i] = row[i].replace(',', '') # 쉼표제거
        row[i] = int(row[i]) # 정수변환
     #print(name + ", " + str(row[8:15:2]) + str(sum(row[9:16:2])))  # 각 역명 인원
    station[name] += sum(row[8:15:2]) # 승객 수 누적

df = pd.DataFrame(index = station.keys(), columns=['승객 수'], data=station.values())
print('[06:00 ~ 10:00] 승차역 [%s] : %d' % (df['승객 수'].idxmax(), df['승객 수'].max()))