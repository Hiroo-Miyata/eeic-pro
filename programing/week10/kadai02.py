class Matrix:
    def __init__(self, m11, m12, m21, m22):
        self.m11 = m11
        self.m12 = m12
        self.m21 = m21
        self.m22 = m22

    def add(self, matrix):
        m11 = self.m11 + matrix.m11
        m12 = self.m12 + matrix.m12
        m21 = self.m21 + matrix.m21
        m22 = self.m22 + matrix.m22
        return Matrix(m11, m12, m21, m22)

    def mul(self, matrix):
        m11 = self.m11 * matrix.m11 + self.m12 * matrix.m21
        m12 = self.m11 * matrix.m12 + self.m12 * matrix.m22
        m21 = self.m21 * matrix.m11 + self.m22 * matrix.m21
        m22 = self.m21 * matrix.m12 + self.m22 * matrix.m22
        return Matrix(m11, m12, m21, m22)

    def divide(self, k):
        m11 = self.m11 * k
        m12 = self.m12 * k
        m21 = self.m21 * k
        m22 = self.m22 * k
        return Matrix(m11, m12, m21, m22)

    def __repr__(self):
        s = '[{0}, {1}] \n'.format(self.m11, self.m12)
        s += '[{0}, {1}]'.format(self.m21, self.m22)
        return s

    def exp_k(self, k):
        if k == 0:
            return Matrix(1,0,0,1)
        else:
            return self.exp_k(k - 1).mul(self).divide(1 / k)

    def exp(self):
        matrix = Matrix(0,0,0,0)
        for i in range(0, 100):
            matrix = matrix.add(self.exp_k(i))
        return matrix

print(Matrix(1, 2, 3, 4).exp())
