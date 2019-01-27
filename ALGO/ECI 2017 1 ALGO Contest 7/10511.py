from sys import stdin,stdout
from collections import deque
inf = 1<<30
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def main():
    cn = int(stdin.readline())
    stdin.readline()
    for cas in range(cn):
        cap = [{},{}]
        noint = 0
        g = 2
        par = {}
        rep = {}
        cl = {}
        rt = [0,1]
        if cas:stdout.write('\n')
        while True:
            n = stdin.readline().split()
            if not n: break
            if n[1] not in par:
                rt.append(n[1])
                par[n[1]] = g
                cap.append({})
                g += 1
            if not n[0] in rep:
                rt.append(n[0])
                rep[n[0]] = g
                cap.append({})
                g += 1
            cap[par[n[1]]][rep[n[0]]] = 1
            cap[rep[n[0]]][par[n[1]]] = 0
            for C in range(2,len(n)):
                if n[C] not in cl:
                    rt.append(n[C])
                    cl[n[C]] = g
                    cap.append({})
                    g += 1
                    noint += 1
                cap[rep[n[0]]][cl[n[C]]] = 1
                cap[cl[n[C]]][rep[n[0]]] = 0
                cap[cl[n[C]]][1] = 1
                cap[1][cl[n[C]]] = 0
        val = noint//2-1 if noint//2 == noint/2 else noint//2
        for pa in par: cap[0][par[pa]] = val;cap[par[pa]][0] = 0
        flu = [{} for c in range(len(cap))]
        for i in range(len(cap)):
            for j in cap[i]:
                flu[i][j] = 0
        maxf = 0
        while True:
            end = False
            Q = deque((0,))
            pad = {0:0}
            while Q:
                x = Q.popleft()
                for ad in cap[x]:
                    if cap[x][ad]-flu[x][ad] > 0 and ad not in pad:
                        Q.append(ad)
                        pad[ad] = x
                        if ad == 1:
                            end = True;break
                if end:break
            else: break
            minf = 1
            ob = 1
            while True:
                if ob == pad[ob]:break
                flu[pad[ob]][ob] += minf
                flu[ob][pad[ob]] -= minf
                ob = pad[ob]
            maxf += minf
        if maxf == noint:
            for per in rep:
                for pu in cap[rep[per]]:
                    if flu[rep[per]][pu] > 0: print(per,rt[pu])
        else:stdout.write('Impossible.\n')
main()
