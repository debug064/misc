import cv2 as cv
import numpy as np

img = cv.imread("opencv/photos/minecraft.jpg")
scale_ratio = 0.4
new_width = int(img.shape[1] * scale_ratio)
new_height = int(img.shape[0] * scale_ratio)
img = cv.resize(img, (new_width, new_height))
cv.imshow('One', img)
cv.waitKey(0)


gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('One', gray)
cv.waitKey(0)

blur = cv.GaussianBlur(gray, (5, 5), cv.BORDER_DEFAULT)
cv.imshow('One', blur)
cv.waitKey(0)

canny = cv.Canny(blur, 125, 175)
cv.imshow('One', canny)
cv.waitKey(0)



contours, hierarchies = cv.findContours(canny, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f"contours = {len(contours)}")

blank = np.zeros(img.shape, dtype='uint8')
cv.drawContours(blank, contours, -1, (0, 0, 255), 1)
cv.imshow('One', blank)
cv.waitKey(0)

ret, thresh = cv.threshold(gray, 145, 255, cv.THRESH_BINARY)
contours, hierarchies = cv.findContours(thresh, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f"contours = {len(contours)}")

cv.imshow('One', thresh)
cv.waitKey(0)


blank = np.zeros(img.shape, dtype='uint8')
cv.drawContours(blank, contours, -1, (0, 0, 255), 1)
cv.imshow('One', blank)
cv.waitKey(0)

