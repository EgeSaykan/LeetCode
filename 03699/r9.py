nums = [91, 371, 1547, 6405, 26585, 110254, 457379, 1897214, 7869927]
a1, a2, a3, a4, a5,a6, a7, a8, a9 = nums
for c, i in enumerate(nums):
    print(c+1, end="   ")
    for k in range(1, 7):
        print(i*k, end=" ")
    print()
num = a8 + a7 + (a8 - a6) + (2*a7 - a5) + (a8 - (3*a6-a4)) + (3*a7 - 6*a5 + 0*a3) + (a8 - (5*a6 + 8*a4 + 1*a2)) + (a8)
print(num)
# num = 3*a6 + 3*a5 - 4*a4 - a3 +a2
rem = a9 - num
print("rem: ",rem)
# print(a7 - rem)
# print(a7 - rem - 5*a5)
# print(a7 - rem - 5*a5 -3*a4  - 3*a3 - 11*a1)
# print(3*a5-4*a3+a1)