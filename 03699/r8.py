nums = [7, 28, 140, 658, 3164, 15106, 72302, 345775]
a1, a2, a3, a4, a5,a6, a7, a8 = nums
for c, i in enumerate(nums):
    print(c+1, end="   ")
    for k in range(1, 6):
        print(i*k, end=" ")
    print()
num = a7 + a6 + (a7 - a5) + (2*a6 - a4) + (a7 - (3*a5-a3)) + (3*a6 - 6*a4 + 0*a2) + (a7 - (5*a5 + 8*a3 + 1*a1))
print(num)
# num = 3*a6 + 3*a5 - 4*a4 - a3 +a2
rem = a8 - num
print("rem: ",rem)
# print(a7 - rem)
# print(a7 - rem - 5*a5)
# print(a7 - rem - 5*a5 -3*a4  - 3*a3 - 11*a1)
# print(3*a5-4*a3+a1)