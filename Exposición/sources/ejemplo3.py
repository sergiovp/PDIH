import cv2

# Cargamos clasificadores para cara y ojos
cara = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
ojo = cv2.CascadeClassifier('haarcascade_eye_tree_eyeglasses.xml')

camara = cv2.VideoCapture(-1)

while camara.isOpened():
    _, img = camara.read()
    color = cv2.cvtColor(img, cv2.COLOR_BGR2BGRA)
    faces = cara.detectMultiScale(color, 1.1, 4)

    for (x, y , w ,h) in faces:
        cv2.rectangle(img, (x,y), (x + w, y + h), (255, 0 , 0), 3)

        eyes = ojo.detectMultiScale(color[y:y+h, x:x+w])
        for (ex, ey ,ew, eh) in eyes:
            # Dibujamos rectángulo en los ojos
            cv2.rectangle(img[y:y+h, x:x+w], (ex,ey), (ex + ew, ey + eh), (0, 255, 0), 5)

    cv2.imshow('img', img)
    key = cv2.waitKey(1)
    if key == 27:
        break

camara.release()
cv2.destroyAllWindows()
