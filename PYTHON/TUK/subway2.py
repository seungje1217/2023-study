# 지하철 출근시간 하차 최대인원
import csv
import pandas as pd

f = open('subway.csv', encoding='EUC-KR')
data = csv.reader(f)
next(data)
next(data)
station = {}

for row in data:
    name = row[3]
    if name not in station:
        station[name] = 0
    for i in range(9, 16, 2):  # 출근시간 (6:00 AM ~ 10:00 AM) 하차 인원
        row[i] = row[i].replace(',', '')
        row[i] = int(row[i])
    #print(name + ", " + str(row[9:16:2]) + str(sum(row[9:16:2])))
    station[name] += sum(row[9:16:2])

df = pd.DataFrame(index = station.keys(), columns=['승객 수'], data=station.values())
print('[06:00 ~ 10:00] 하차역 [{0}] : {1}'.format(df['승객 수'].idxmax(), df['승객 수'].max()))