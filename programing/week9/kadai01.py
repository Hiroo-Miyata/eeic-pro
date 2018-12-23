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

g = logistic(a = 3.9, x0 = 0.1)
traj  =  [next(g)  for i in range(100)]
plt.plot(traj)
for n in range(100):
    print(str(n) + " " + str(next(g)))
