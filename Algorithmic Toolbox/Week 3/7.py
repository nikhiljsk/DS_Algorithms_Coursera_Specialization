import sys
input = sys.stdin.read()
data = input.split()
a = data[1:]

def is_greater(maxi, ele):
    return maxi+ele >= ele+maxi

def max_number(a):
    maxi = ""
    i=0
    while i<len(a):
        if (is_greater(maxi, a[i])):
            maxi += a[i]
        else:
            maxi = a[i]+maxi
        i+=1
    return maxi

print(max_number(sorted(a)))