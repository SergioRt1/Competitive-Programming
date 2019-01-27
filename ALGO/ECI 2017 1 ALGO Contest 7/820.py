from sys import stdin, stdout
from collections import deque
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
inf = 1<<30
def main():
    cas = 0
    while True:
        cas += 1
        n = int(stdin.readline())
        if not n: break
        cap = [[0]*n for k in range(n)]
        flu = [[0]*n for k in range(n)]
        ini,obj,ca = map(int,stdin.readline().split())
        ini -= 1; obj -= 1
        for k in range(ca):
            a,b,c = map(int,stdin.readline().split())
            a -= 1; b -= 1
            cap[b][a] += c
            cap[a][b] += c
        maxf = 0
        while True:
            end = False
            pad = {ini:ini}
            Q = deque((ini,))
            while Q:
                x = Q.popleft()
                for ad in range(n):
                    if cap[x][ad]-flu[x][ad] > 0 and ad not in pad:
                        Q.append(ad)
                        pad[ad] = x
                        if ad == obj:
                            end = True;break
                if end:break
            if not end:break
            minf = inf
            ob = obj
            while True:
                if ob == pad[ob]:break
                minf = min(minf,cap[pad[ob]][ob]-flu[pad[ob]][ob])
                ob = pad[ob]
            ob = obj
            while True:
                if ob == pad[ob]:break
                flu[pad[ob]][ob] += minf
                flu[ob][pad[ob]] -= minf
                ob = pad[ob]
            maxf += minf
        stdout.write("Network {}\nThe bandwidth is {}.\n\n".format(cas,maxf))
main()
