from PIL import Image
import argparse
import sys
 
parser = argparse.ArgumentParser(description="Print the resolution of an image")
 
parser.add_argument("image", nargs="?", help="Image", default=None)
 
arguments = parser.parse_args()
 
use_arguments = True if arguments.image is not None else False
 
while True:
    if use_arguments:
        image = arguments.image
    else:
        image = input("Enter the image file name: ")
 
    try:
        im = Image.open(image)
    except:
        print('Invalid image')
        if use_arguments:
            sys.exit()
        continue
    break
 
print('Image resolution is (w, h): ' + str(im.size))
