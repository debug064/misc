import cv2 as cv

def readImage():
    img = cv.imread("opencv/photos/golf.jpg")
    cv.imshow('Golf', img)

    cv.waitKey(0)

    width = int(img.shape[1] * 0.5)
    height = int(img.shape[0] * 0.2)
    img = cv.resize(img, (width, height))

    cv.imshow('Golf', img)

    cv.waitKey(0)



def readVideo():
    capture = cv.VideoCapture("opencv/photos/golf.jpg")
    while True:
        isFinished, frame = capture.read()
        if isFinished :
            break
        cv.imshow('VIdeo', frame)

        if cv.waitKey(20) &0xFF == ord('z'):
            break

    capture.release()

readImage()
cv.destroyAllWindows()