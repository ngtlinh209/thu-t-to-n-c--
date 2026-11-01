import cv2

cap=cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)  
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)   


while True:
    _,frame=cap.read()
    frame=cv2.flip(frame,1)
    frame=cv2.resize(frame,(640,480))
    
    hsv_frame=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    
    # Tạo tâm tròn giữa camera
    height,width,_=frame.shape
    x=int(width/2)
    y=int(height/2)
    center=hsv_frame[y,x]
    center_color=center[0]
    s=center[1]
    v=center[2]

    color="NOT KNOW"
    # Phân loại màu 
    if v<40:
        color="BLACK"
    elif s<51 and v>200:
        color="WHITE"
    elif s < 40 and 40 <= v <= 200:
        color = "GRAY"
    else:
      if center_color<4:
         color="RED"
      elif 4<=center_color<21:
        color="ORANGE"
      elif 21<=center_color<37:
        color="YELLOW"
      elif 37<=center_color<71:
        color="GREEN"
      elif 73<center_color<81:
        color="MINT"
      elif 83<center_color<103:
        color="SKYBLUE"
      elif 104<=center_color<128:
        color="BLUE"
      elif 130<=center_color<138:
        color="PURPLE"
      elif 138<=center_color<169:
        color="PINK"
      else:
        color="RED"
    
    print(center)
    cv2.putText(frame,color,(10,50),0,1,(255,0,0),2)

    cv2.circle(frame,(x,y),5,(255,0,0),3)
    cv2.imshow("Frame",frame)
    key=cv2.waitKey(1)
    if key==27:
        break
cap.release()
cv2.destroyAllWindows()
