
# This is a programme to find square root of any positive number 
# Code written By Jatin Phogat

import math
a=float(input("Enter a positive number "))
if (a<0):
   print("Entered number is negative...try again")
else:     
   print("Square root of",a,"is",math.sqrt(a))