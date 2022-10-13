import cv2, re
from pytesseract import pytesseract

pytesseract.tesseract_cmd = "C:\\Program Files\\Tesseract-OCR\\tesseract.exe"

img = cv2.imread("coba.jpg")
words_in_image = pytesseract.image_to_string(img)
# print(words_in_image)

cari = (re.findall(r'\w+',words_in_image)[re.findall(r'\w+',words_in_image).index('By')-1])
print(cari)