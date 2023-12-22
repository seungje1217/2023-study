import os, time
import cv2
import pyautogui
from PIL import ImageChops

# 원쪽 원본 이미지
# 시작 좌표 (833,63)

# 비교 대상 이미지
# 시작 좌표 (833,712)

while True:
    result = pyautogui.confirm('틀린 그림 찾기', buttons=['시작', '종료'])
    if result == '종료':
        break # 프로그램 종료
    
    width, height= 803, 643
    x_pos=833

    # 원본 이미지
    src=pyautogui.screenshot(region=(x_pos,63,width,height))
    #src.save('src.jpg')

    # 비교 이미지
    dest=pyautogui.screenshot(region=(x_pos,712,width,height))
    #dest.save('dest.jpg')

    diff=ImageChops.difference(src, dest)
    diff.save('diff.jpg')  # 서로 다른 점을 픽셀 단위로 보는 것

    # 파일 생성 대기
    while not os.path.exists('diff.jpg'):
        time.sleep(1)

    # src_img=cv2.imread('src.jpg')
    # dest_img=cv2.imread('dest.jpg')
    diff_img=cv2.imread('diff.jpg')

    gray = cv2.cvtColor(diff_img, cv2.COLOR_BGR2GRAY)
    gray=(gray>25)*gray
    contours, _ = cv2.findContours(gray, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    COLOR=(0,200,0)
    for cnt in contours:
        if cv2.contourArea(cnt) > 100:
            x ,y , width, height = cv2.boundingRect(cnt)
            #cv2.rectangle(src_img, (x,y), (x + width, y + height), COLOR, 2)
            #cv2.rectangle(dest_img, (x,y), (x + width, y + height), COLOR, 2)
            #cv2.rectangle(diff_img, (x,y), (x + width, y + height), COLOR, 2)

            to_x = x + (width//2) + x_pos
            to_y = y + (height//2)
            pyautogui.moveTo(to_x, to_y, duration=0.3)
            pyautogui.click(to_x, to_y)
            time.sleep(1)


# cv2.imshow('src', src_img)
# cv2.imshow('dest', dest_img)
# cv2.imshow('diff', diff_img)

# cv2.waitKey(0)
# cv2.destroyAllWindows()