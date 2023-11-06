# 지하철 퇴근시간 하차 최대 인원
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
    for i in range(31, 36, 2):  # 톼근시간 (17:00 PM ~ 20:00 AM) 하차 인원
        row[i] = row[i].replace(',', '')
        row[i] = int(row[i])
    #print(name + ", " + str(row[31:36:2]) + str(sum(row[31:36:2])))
    station[name] += sum(row[31:36:2])

df = pd.DataFrame(index = station.keys(), columns=['승객 수'], data=station.values())
print('[17:00 ~ 20:00] 하차역 [{0}] : {1}'.format(df['승객 수'].idxmax(), df['승객 수'].max()))