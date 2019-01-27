from math import sqrt
d = [0]*51
#Generador de la matris de acceso usando precomputo.
def f(k):
    pos = 0
    b = 1
    pila = [[] for x in range(k)]
    while True:
        if not pila[pos]:
            pila[pos].append(b)
            pos = 0
            b += 1
        val = sqrt(pila[pos][-1]+b)
        if val == int(val):
            pila[pos].append(b)
            b += 1
            pos = 0
        else:
            pos += 1
            if pos == k:break
    return b-1
            
for k in range(1,51):
    d[k] = f(k)
print(d)
