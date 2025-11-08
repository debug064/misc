import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread("opencv/photos/golf.jpg")
scale_ratio = 0.4
new_width = int(img.shape[1] * scale_ratio)
new_height = int(img.shape[0] * scale_ratio)
img = cv.resize(img, (new_width, new_height))
cv.imshow('One', img)
cv.waitKey(0)


average = cv.blur(img, (7, 7))
cv.imshow('One', average)
cv.waitKey(0)


gauss = cv.GaussianBlur(img, (7, 7), 0)
cv.imshow('One', gauss)
cv.waitKey(0)

medium = cv.medianBlur(img, 7)
cv.imshow('One', medium)
cv.waitKey(0)

cv.setWindowTitle('One', 'Original')
cv.imshow('One', img)
cv.waitKey(0)

cv.setWindowTitle('One', 'bilateralFilter')
for i in range(5, 55):
    bilater = cv.bilateralFilter(img, i, 55, 75)
    cv.imshow('One', bilater)
cv.waitKey(0)

