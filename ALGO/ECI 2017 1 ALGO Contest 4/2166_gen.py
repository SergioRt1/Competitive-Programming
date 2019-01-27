from random import randint as ri
for k in range(200):
    m = []
    for t in range(3):
        t = ri(1,150)
        m.append(t)
    for i in range(3):
        m.append(ri(1,m[i]))
    for i in range(-1,-4,-1):
        m.append(m[i*2+1])
    print(*m)
print(*[0]*9)
