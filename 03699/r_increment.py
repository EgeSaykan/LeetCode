s = "a7 + a6 + (a7 - a5) + (2*a6 - a4) + (a7 - (3*a5-a3)) + (3*a6 - 6*a4 + 0*a2) + (a7 - (5*a5 + 8*a3 + 1*a1))"

for i in range(len(s) - 1):
    if s[i] == "a" and s[i+1].isdigit():
        s = s[:i+1] + str(int(s[i+1]) -2) + s[i+2:]

print(s)