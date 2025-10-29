import cv2 as cv
import numpy as np


img = cv.imread("opencv/photos/golf.jpg")
cv.imshow('Golf', img)
cv.waitKey(0)


# translate
def translate (img, x, y):
    translMat = np.float32([[1, 0, x],[0, 1, y]])
    dims = (img.shape[1], img.shape[0])
    return cv.warpAffine(img, translMat, dims)


translated = translate(img, 100, 100)
cv.imshow('Golf', translated)
cv.waitKey(0)

translated = translate(img, -100, 100)
cv.imshow('Golf', translated)
cv.waitKey(0)

# rotate

def rotate(img, angle, rotPt=None):
    (height, width) = img.shape[:2]
    if rotPt is None:
        rotPt = (width // 2, height // 2)
    rotMat = cv.getRotationMatrix2D(rotPt, angle, 1.0 )
    dims = (width, height)
    return cv.warpAffine(img, rotMat, dims)


rotated = rotate(img, -45)
cv.imshow('Golf', rotated)
cv.waitKey(0)

#flip

flip = cv.flip(img, 0)
cv.imshow('Golf', flip)
cv.waitKey(0) # hor axis

flip = cv.flip(img, 1)
cv.imshow('Golf', flip)
cv.waitKey(0) # vert  axis

flip = cv.flip(img, -1)
cv.imshow('Golf', flip)
cv.waitKey(0) # both


#crop

cropped = img[200: 600, 200:300]
cv.imshow('Golf', cropped)
cv.waitKey(0) # both

cv.destroyAllWindows()