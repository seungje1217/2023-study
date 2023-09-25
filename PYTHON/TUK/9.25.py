# 생일 년도 별 최고기온 출력 / 그래프 
import matplotlib.pyplot as plt
import csv

f = open('seoul_csv.csv', encoding='cp949')
data = csv.reader(f)
next(data)
birth = []

for row in data:
    cut = row[0].split('-')
    year = int(cut[0])
    month = int(cut[1])
    day = int(cut[2])
    if year >= 1999 and month == 12 and day == 17:
        birth.append(row)
        
for row in birth:
    date_parts = row[0].split('-')
    formatted_date = f"{date_parts[0]}년 {date_parts[1]}월 {date_parts[2]}일"
    print(formatted_date +"\t" + row[4] + "도")
 
birth_years = [int(row[0].split('-')[0]) for row in birth] # 생일 연도 목록 생성
birth_temperatures = [float(row[4]) for row in birth] # 최고기온 온도 생성

plt.title('임승제의 년도별 생일 최고기온')    

plt.plot(birth_years, birth_temperatures, marker='o', color='blue')
plt.xlabel('Year')
plt.ylabel('°C')
plt.xticks(birth_years, rotation=270)

plt.rc('font',family='Malgun Gothic') # 한글 사용
plt.show()