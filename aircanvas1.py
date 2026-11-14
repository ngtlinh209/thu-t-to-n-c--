import cv2
import mediapipe as mp
from collections import deque
import numpy as np

mp.hands=mp.solutions.hands
mp.drawing=mp.solutions.drawing_utils

de_que=deque(maxlen=512)

Hands=mp.hands.Hands(
    max_num_hands=1,
    min_detection_confidence=0.8,
    min_tracking_confidence=0.9,
)
cap=cv2.VideoCapture(0)
canvas=None
draw_color=(0,0,255)
brush_thickness=5
while True:

    _,frame=cap.read()
    frame=cv2.flip(frame,1)
    frame=cv2.resize(frame,(680,480))
    curr_point=None
    if canvas is None:
        canvas=np.zeros((480,680,3))+255
    w_box=680//4
    cv2.rectangle(frame, (0, 0), (w_box, 80), (0,0,0), cv2.FILLED)
    cv2.putText(frame, "BLACK", (20, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255,255,255), 2)

    # Ô 2: Màu Xanh Dương (BGR: 255, 255, 0)
    cv2.rectangle(frame, (w_box, 0), (2 * w_box, 80), (255, 255, 0), cv2.FILLED)
    cv2.putText(frame, "BLUE", (w_box + 20, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 0), 2)

    # Ô 3: Màu Vàng (BGR: 0, 255, 255)
    cv2.rectangle(frame, (2 * w_box, 0), (3 * w_box, 80), (0, 255, 255), cv2.FILLED)
    cv2.putText(frame, "Yellow", (2 * w_box + 20, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 0), 2)

    # Ô 4: Cục Tẩy (Tô màu xám đại diện cho Tẩy)
    cv2.rectangle(frame, (3 * w_box, 0), (680, 80), (200, 200, 200), cv2.FILLED)
    cv2.putText(frame, "CLEAR", (3 * w_box + 10, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 0), 2)
    frame_rgb=cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
    ket_qua=Hands.process(frame_rgb)
    if ket_qua.multi_hand_landmarks:
        for i in ket_qua.multi_hand_landmarks:
            mp.drawing.draw_landmarks(frame,i,mp.hands.HAND_CONNECTIONS)
        finger=i.landmark
        index_x,index_y=int(finger[8].x*680),int(finger[8].y*480)

        if finger[8].y<finger[6].y and finger[12].y>finger[9].y:
            if index_y < 80:
                    de_que.append(None) # Ngắt nét vẽ cũ khi chạm vào menu
                    
                    if 0 <= index_x < w_box:
                        draw_color = (0,0,0) 
                        brush_thickness = 6
                    elif w_box <= index_x < 2 * w_box:
                        draw_color = (255,0,0) 
                        brush_thickness = 6
                    elif 2 * w_box <= index_x < 3 * w_box:
                        draw_color = (0, 255, 255) 
                        brush_thickness = 6
                    elif 3 * w_box <= index_x <= 680:
                        canvas[::]=255
                        de_que.clear()
            else:
                    curr_point = (index_x, index_y, draw_color, brush_thickness)
                    # Vẽ một vòng tròn nhỏ báo hiệu đầu ngón tay
                    preview_color = (255, 255, 255) if draw_color == (0, 0, 0) else draw_color
                    cv2.circle(frame, (index_x, index_y), brush_thickness, preview_color, cv2.FILLED)
            
            cv2.circle(frame,(index_x,index_y),3,(0,255,0),-1)
        else:
            de_que.append(None)
    else:
        de_que.append(None)
    if curr_point is not None:
        de_que.append(curr_point)
    for i in range(1,len(de_que)):
        if de_que[i-1] is None or de_que[i] is None:
            continue
        #cv2.line(canvas,de_que[i-1],de_que[i],draw_color,brush_thickness)
        #cv2.line(frame,de_que[i-1],de_que[i],draw_color,brush_thickness)
        p1 = (de_que[i - 1][0], de_que[i - 1][1])
        p2 = (de_que[i][0], de_que[i][1])
        p_color = de_que[i][2]
        p_thick = de_que[i][3]
        cv2.line(frame,p1,p2,p_color,p_thick)
        cv2.line(canvas,p1,p2,p_color,p_thick)
    




    
    cv2.imshow("AirCanvas",frame)
    cv2.imshow("canvas",canvas)
    key=cv2.waitKey(1)
    if key==27:
        break

cap.release()
cv2.destroyAllWindows()
