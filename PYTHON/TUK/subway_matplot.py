# 지하철 퇴근시간 승차 최대인원 그래프
import csv
import pandas as pd
import matplotlib.pyplot as plt

f = open('subway.csv', encoding='EUC-KR')
data = csv.reader(f)
next(data)
next(data)

station_name = []
station_17 = []
station_18 = []
station_19 = []

for row in data :
    if row[2] and int(row[2]) >= 419 and int(row[2]) <= 433 and row[1] == '4호선':
        name = row[3]
        for i in range(30, 35, 2) : # 톼근시간 (17:00 PM ~ 20:00 AM) 승차 인원
            row[i] = row[i].replace(',','')
            row[i] = int(row[i])
        station_name.append(name)
        station_17.append(row[30])
        station_18.append(row[32])
        station_19.append(row[34])
        
plt.title('4호선 퇴근시간대 지하철 승차인원')
plt.ylabel('인원')
plt.xlabel('역')
plt.rc('font', family='Malgun Gothic')
plt.xticks(rotation=90, fontsize=10)
plt.plot(station_name, station_17, label='17시')
plt.plot(station_name, station_18, label='18시')
plt.plot(station_name, station_19, label='19시')

plt.legend(loc='best')  