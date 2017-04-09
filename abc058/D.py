"""Note: this codes calculates the answer to a problem correctly. However, the two nested
for-loops make it too slow (got TLE).

"""
n, m = map(int, raw_input().split())
X = map(int, raw_input().split())
Y = map(int, raw_input().split())

mdl = 1000000007

numx = n - 1
numy = m - 1

A = 0
incrx = numx
multx = 0
for ix in xrange(numx/2 + numx%2):
    multx += incrx
    multy = 0
    incry = numy
    for iy in xrange(numy/2 + numy%2):
        multy += incry
        ly = (Y[-1 - iy] - Y[iy])
        lx = (X[-1 - ix] - X[ix])
        A += (((lx * ly)%mdl) * incrx * incry)%mdl
        incry -= 2
    incrx -= 2
print A % mdl
