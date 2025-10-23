import cv2 as cv

img = cv.imread("opencv/photos/golf.jpg")
cv.imshow('Golf', img)

cv.waitKey(0)

width = int(img.shape[1] * 0.5)
height = int(img.shape[0] * 0.2)
img = cv.resize(img, (width, height))

cv.imshow('Golf', img)

cv.waitKey(0)
