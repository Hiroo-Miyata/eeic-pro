import matplotlib.pyplot as plt

def logistic(a, x0):
    if a < 0 or a > 4:
        raise ValueError('Variable "a" needs to be in the range of [0, 4]')
    elif x0 < 0 and x0 > 1:
        raise ValueError('Variable "x0" needs to be in the range of [0, 1]')
    else:
        xn = x0
        while True:
            xn = a * xn * (1 - xn)
            yield xn

for _a in range(0, 401, 1):
    a = _a / 100
    g = logistic(a = a, x0 = 0.1)
    for n in range(10):
        next(g)
    for n in range(90):
        print(str(a) + " " + str(next(g)))
        xs  =  [6.0  *  n  /100  for  n  in  range(100)]
        ys  =  [x**2  for  x  in  xs]
        plt.scatter(xs,ys,s=0.1)
