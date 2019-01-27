from sys import stdin,stdout
from collections import deque
inf = 1 << 30
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def main():
    while True:
        m,w = map(int,stdin.readline().split())
        if m+w == 0:break
        M = m+m
        cap = [[0]*M for k in range(M)]
        flu = [[0]*M for k in range(M)]
        for k in range(m-2):
            a,b  = map(int,stdin.readline().split())
            a -= 1
            cap[a<<1][(a<<1)+1]= b
        cap[0][1] = cap[1][0] = cap[M-1][M-2] = cap[M-2][M-1] = inf
        for k in range(w):
            a,b,c  = map(int,stdin.readline().split())
            a,b = (b,a) if a > b else (a,b)
            a -= 1;b -= 1
            cap[(a<<1)+1][b<<1] = c
            cap[(b<<1)+1][a<<1] = c
        maxf = 0
        ob = M-2
        while True:
            end = False
            Q = deque((0,))
            pad = {0:0}
            ob = M-2
            while Q:
                x = Q.popleft()
                for ad in range(M):
                    if cap[x][ad]-flu[x][ad] > 0 and ad not in pad:
                        Q.append(ad)
                        pad[ad] = x
                        if ad == ob:
                            end = True;break
                if end:break
            if not end: break
            minf = inf
            while True:
                if pad[ob] == ob:break
                minf = min(minf,cap[pad[ob]][ob]-flu[pad[ob]][ob])
                ob = pad[ob]
            ob = M-2
            while True:
                if pad[ob] == ob:break
                flu[pad[ob]][ob] += minf
                flu[ob][pad[ob]] -= minf
                ob = pad[ob]
            maxf += minf
        print(maxf)        
main()
