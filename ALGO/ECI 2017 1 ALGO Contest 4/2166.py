from sys import stdin,stdout
from collections import deque
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
ad = {0:(1,2),1:(0,2),2:(0,1)}
def ady(x):
    for v in range(3):
        for k in ad[v]:
            jar = list(x)
            if x[k]+x[v] <= can[k]:
                jar[k] = x[v]+x[k]
                jar[v] = 0
            else:
                jar[k] = can[k]
                jar[v] = x[v]+x[k]-can[k]
            yield tuple(jar)

def main():
    global can
    while True:
        c1, c2, c3, a1, a2, a3, b1, b2, b3 = map(int, stdin.readline().split())
        if c1 == 0: break
        ini = (a1,a2,a3)
        ob = (b1,b2,b3)
        #if sum(ini) != sum(ob):stdout.write("-1\n");continue
        if ini == ob: stdout.write("0\n");continue
        can = (c1,c2,c3)
        pad = {ini:ini}
        Q = deque([ini])
        flag = True
        while Q and flag:
            x = Q.popleft()
            for v in ady(x):
                if v not in pad:
                    pad[v] = x
                    if v == ob:
                        flag = False
                        break
                    Q.append(v)
        if flag: stdout.write("-1\n")
        else:
            t = 0
            while ob != pad[ob]:
                ob = pad[ob]
                t+=1
            print(t)
                    
main()
        
