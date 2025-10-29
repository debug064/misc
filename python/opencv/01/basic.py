import cv2 as cv

img = cv.imread("opencv/photos/golf.jpg")
cv.imshow('Golf', img)
cv.waitKey(0)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Golf', gray)
cv.waitKey(0)

bl = cv.GaussianBlur(img, (3,3), cv.BORDER_DEFAULT)
cv.imshow('Golf', bl)
cv.waitKey(0)

edge = cv.Canny(img, 115, 185)
cv.imshow('Golf', edge)
cv.waitKey(0)

edge = cv.Canny(bl, 115, 185)
cv.imshow('Golf', edge)
cv.waitKey(0)

#Dilating
dil = cv.dilate(edge, (3, 3), iterations=1)
cv.imshow('Golf', dil)
cv.waitKey(0)

dil = cv.dilate(edge, (9, 9), iterations=1)
cv.imshow('Golf', dil)
cv.waitKey(0)

#Eroding
erod = cv.erode(dil, (3,3), iterations=1)
cv.imshow('Golf', erod)
cv.waitKey(0)

#resize
resize = cv.resize(img, (500, 400))
cv.imshow('Golf', resize)
cv.waitKey(0)

resize = cv.resize(img, (800, 600), interpolation=cv.INTER_CUBIC)
cv.imshow('Golf', resize)
cv.waitKey(0)


crop = resize[100:250, 250:350]
cv.imshow('Golf', crop)
cv.waitKey(0)

cv.destroyAllWindows()