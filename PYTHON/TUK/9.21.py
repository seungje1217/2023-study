# 한글은 2번 돌려야함
import matplotlib.pyplot as plt
plt.title('마커')
plt.plot([10,20,30,40],'r.--',label='원')
plt.plot([40,30,20,10],'g^-',label='삼각형')
plt.legend(loc=5)
plt.rc('font',family='Malgun Gothic')
plt.show()



import matplotlib.pyplot as plt 
import csv
f=open('seoul_csv.csv', encoding='cp949')
data=csv.reader(f)
next(data) #읽어들인것에서 날짜 주기 이런것들을 날림
result=[] #빈 리스트 초기화

for row in data:
    if row[-1]!='':
        result.append(float(row[-1]))
print(result)
plt.plot(result,'r')
plt.show()