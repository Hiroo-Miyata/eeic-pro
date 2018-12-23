import random

def nestlist(f, x0, n):
    result = [x0]
    while (n > 0):
        x = result[-1]
        result.append(f(x))
        n = n - 1
    return result

l = nestlist(lambda x: x + (-1)**random.randint(0, 1), 0, 1000)
print(l)
