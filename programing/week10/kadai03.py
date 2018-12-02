

def rand_val(minval = 0.0, maxval = 1.0):
    x = 1
    a = 1664525
    c = 1013904223
    m = 4294967296
    while True:
        xnext = (a * x + c) % m
        yield minval + (maxval - minval) * xnext / m
        x = xnext

class RandomWalk:
    def __init__(self, x0, p):
        self.x0 = x0
        self.xn = x0
        self.p = p
        self.r = rand_val()

    def next_step(self):
        if next(self.r) <= self.p:
            self.xn += 1
        else:
            self.xn -= 1
        return self.xn

    def gem_traj(self):
        for n in range(1000):
            print(str(n) + " : " + str(self.next_step()))

rw = RandomWalk(0, 0.5)
rw.gem_traj()
