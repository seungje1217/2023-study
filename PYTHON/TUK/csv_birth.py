# csv 파일읽기 -> 년도 별 생일 최저기온과 최고기온, 그래프  
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
        


birth_years = [int(row[0].split('-')[0]) for row in birth]
birth_max_temperatures = [float(row[4]) for row in birth]
birth_min_temperatures = [float(row[3]) for row in birth]


for i in range(len(birth_years)):
    year = birth_years[i]
    date = f'{year}년 5월 7일'
    min_temp = birth_min_temperatures[i]
    max_temp = birth_max_temperatures[i]
    print(f'{date}\t최저기온 : {min_temp:.1f}도\t최고기온 : {max_temp:.1f}도')

plt.title('임승제의 년도별 생일 최저기온과 최고기온')


plt.plot(birth_years, birth_max_temperatures, marker='o', color='red', label='최고기온')


plt.plot(birth_years, birth_min_temperatures, marker='o', color='blue', label='최저기온')

plt.xlabel('Year')
plt.ylabel('°C')
plt.xticks(birth_years, rotation=90)
plt.legend()  

plt.rc('font', family='Malgun Gothic')  
plt.show()