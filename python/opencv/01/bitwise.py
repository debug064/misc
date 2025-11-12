import cv2 as cv
import numpy as np


blank = np.zeros((400, 400), dtype='uint8')

rect = cv.rectangle(blank.copy(), (30, 30), (370, 370), 255, -1)

circle = cv.circle(blank.copy(), (200, 200), 200, 255, -1)

cv.imshow('One', rect)
cv.waitKey(0)

cv.imshow('One', circle)
cv.waitKey(0)

#bitwise AND

bitwise_and = cv.bitwise_and(rect, circle)
cv.imshow('One', bitwise_and)
cv.waitKey(0)

bitwise_or = cv.bitwise_or(rect, circle)
cv.imshow('One', bitwise_or)
cv.waitKey(0)

bitwise_xor = cv.bitwise_xor(rect, circle)
cv.imshow('One', bitwise_xor)
cv.waitKey(0)

bitwise_not = cv.bitwise_not(rect)
cv.imshow('One', bitwise_not)
cv.waitKey(0)

bitwise_not = cv.bitwise_not(circle)
cv.imshow('One', bitwise_not)
cv.waitKey(0)