import cv2

camara = cv2.VideoCapture('gente2.mp4')

_, img1 = camara.read()
_, img2 = camara.read()

print(img1.shape)
while camara.isOpened():
    diff = cv2.absdiff(img1, img2)
    color = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(color, (5,5), 0)
    _, thresh = cv2.threshold(blur, 20, 255, cv2.THRESH_BINARY)
    dilated = cv2.dilate(thresh, None, iterations = 4)

    # Contornos personas en movimiento
    contornos, _ = cv2.findContours(dilated, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Dibujamos rectángulos
    for contorno in contornos:
        (x, y, w, h) = cv2.boundingRect(contorno)

        if cv2.contourArea(contorno) < 900:
            continue
        cv2.rectangle(img1, (x, y), (x+w, y+h), (0, 255, 0), 2)

    # Lo mostramos
    cv2.imshow('img', img1)
    img1 = img2
    _, img2 = camara.read()

    if cv2.waitKey(40) == 27:
        break

cv2.destroyAllWindows()
camara.release()
out.release()
