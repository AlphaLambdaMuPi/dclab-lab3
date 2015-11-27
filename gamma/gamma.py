A = ([82 + 7*x for x in range(10)] 
    + [122 + 3*x for x in range(10, 21)] 
    + [38 + 7*x for x in range(21, 32)])

G = [0, 0, 0, 0, 1, 2, 6, 8, 10, 10, 12,
     1, 4, 5, 5, 5, 5, 4, 4, 3, 3, 2,
     2, 2, 3, 5, 6, 5, 4, 3, 2, 1, 2, 3, 0]
print(A)

mp = {}

z = 0
for i in range(31):
    l, r = A[i], A[i+1]
    g = G[i] + 0.5
    dg = g / (r - l)
    for j in range(l, r+1):
        mp[j] = z + dg * (j - l)
    z += g

tot = mp[255]

T = []

for i in range(32):
    tar = tot / 31 * i
    bv, bs = 1e9, -1
    for x, y in mp.items():
        if bv > abs(y - tar):
            bv = abs(y - tar)
            bs = x
    T.append(bs)
import matplotlib.pyplot as plt
plt.plot(T)
plt.plot((1, 5), (100, 132), '-')
plt.plot((5, 22), (132, 183), '-')
plt.plot((22, 25), (183, 213), '-')
plt.plot((25, 31), (213, 255), '-')

plt.show()
