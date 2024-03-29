import numpy as np

array=np.ones(81).reshape(9,9) # 81개 9x9 배열 모두 1로 초기화
array[[1,7],1:8]=0 # 0:1번 행과 7번 행의 1열부터 7열까지 0
array[1:8,[1,7]]=0 # 0:1변 열과 7번열의 1에서 7행까지 0
array[[3,5],3:6]=0 # 0:3번 행과 5번 행의 3열부터 5열까지 0
array[3:6,[3,5]]=0 # 0:3변 열과 5번열의 3에서 5행까지 0

print(array) 