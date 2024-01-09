import math
def calculate(no):
    sin = math.sin(3.14*no/180)
    cos = math.cos(3.14*no/180)
    return sin,cos
no = int(input("Enter the value :"))
sin,cos = calculate(no)
print(f"The value of sin {no} is :",sin)
print(f"The value of cos {no} is :",cos)