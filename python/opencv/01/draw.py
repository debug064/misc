import cv2 as cv
import numpy as np


blank = np.zeros((500, 500, 3), dtype='uint8')
cv.imshow('Bl', blank)
cv.waitKey(0)
blank[:] = 0, 0, 255
cv.imshow('Bl', blank)
cv.waitKey(0)

blank[150:200, 200:250] = 255, 0, 255
cv.imshow('Bl', blank)
cv.waitKey(0)


cv.rectangle(blank, (25, 25), (400, 400), (0, 255, 0), thickness=2)
cv.imshow('Bl', blank)
cv.waitKey(0)

cv.rectangle(blank, (425, 425), (450, 450), (0, 255, 255), thickness=cv.FILLED)
cv.imshow('Bl', blank)
cv.waitKey(0)

(text_width, text_height), baseline = cv.getTextSize("Hello", cv.FONT_HERSHEY_TRIPLEX, 1, 2)

cv.putText(blank, "Hello", (500 - text_width, 225), cv.FONT_HERSHEY_TRIPLEX, 1, (255, 255, 255),2)
cv.imshow('Bl', blank)
cv.waitKey(0)


cv.destroyAllWindows()