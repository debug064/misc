import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread("opencv/photos/minecraft.jpg")
scale_ratio = 0.4
new_width = int(img.shape[1] * scale_ratio)
new_height = int(img.shape[0] * scale_ratio)
img = cv.resize(img, (new_width, new_height))
cv.imshow('One', img)
cv.waitKey(0)

plt.imshow(img)
plt.show()
cv.waitKey(0)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('One', gray)
cv.waitKey(0)

rgb = cv.cvtColor(img, cv.COLOR_BGR2RGB)
cv.imshow('One', rgb)
cv.waitKey(0)


hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
cv.imshow('One', hsv)
cv.waitKey(0)

lab = cv.cvtColor(img, cv.COLOR_BGR2LAB)
cv.imshow('One', lab)
cv.waitKey(0)

