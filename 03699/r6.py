nums = [55, 190, 671, 2353, 8272, 29056]
a1, a2, a3, a4, a5,a6= nums
for c, i in enumerate(nums):
    print(c+1, end="   ")
    for k in range(1, 6):
        print(i*k, end=" ")
    print()
num = a5 + a4 + (a5 - a3) + (2*a4 - a2) + (a5 - (3*a3-a1))
print(num)
# num = 3*a6 + 3*a5 - 4*a4 - a3 +a2
rem = a6 - num
print("rem: ",rem)
# print(a7 - rem)
# print(a7 - rem - 5*a5)
# print(a7 - rem - 5*a5 -3*a4  - 3*a3 - 11*a1)
# print(3*a5-4*a3+a1)