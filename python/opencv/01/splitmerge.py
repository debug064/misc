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

blank = np.zeros(img.shape[:2], dtype='uint8')

b, g, r = cv.split(img)
cv.imshow('One', b)
cv.waitKey(0)

cv.imshow('One', g)
cv.waitKey(0)

cv.imshow('One', r)
cv.waitKey(0)

print(img.shape)
print(r.shape)
print(b.shape)
print(b.shape)


merge = cv.merge([r,g,b])
cv.imshow('One', merge)
cv.waitKey(0)

merge = cv.merge([b,blank,blank])
cv.imshow('One', merge)
cv.waitKey(0)