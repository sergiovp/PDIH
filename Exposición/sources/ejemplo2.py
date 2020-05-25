import cv2

# Cargamos clasificador para la cara https://github.com/opencv/opencv/tree/master/data/haarcascades
cara = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Abrimos la cámara
camara = cv2.VideoCapture(-1)

while camara.isOpened():
    # Cargamos en img lo capturado por la cámara
    _, img = camara.read()

    # Espacio de colores
    color = cv2.cvtColor(img, cv2.COLOR_BGR2BGRA)

    # Detectamos la cara
    faces = cara.detectMultiScale(color, 1.1, 4)

    # Pintamos el rectángulo sobre la cara
    for (x, y , w ,h) in faces:
        cv2.rectangle(img, (x,y), (x+w, y+h), (255, 0 , 0), 3)

    # Lo mostramos mientras no pulsemos 'esc'
    cv2.imshow('img', img)
    key = cv2.waitKey(1)
    if key == 27:
        break

camara.release()
cv2.destroyAllWindows()
