w = float(input())
h = float(input())

bmi = w /(h*h)

if bmi > 25:
    print("Overweight")
elif 18.5<=bmi:
    print("Normal weight")
else:
    print("Underweight")