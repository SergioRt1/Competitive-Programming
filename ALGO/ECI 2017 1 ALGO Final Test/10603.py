from sys import stdin,stdout
from collections import deque,defaultdict
ad = {0:(1,2),1:(0,2),2:(0,1)}
inf = 1 << 30
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def ady(x,cost):
    if cost >= ans[d] or cost >= cs[x]: return []
    cs[x] = cost
    if ans[x[0]] > cost: ans[x[0]] = cost
    if ans[x[1]] > cost: ans[x[1]] = cost
    if ans[x[2]] > cost: ans[x[2]] = cost
    for v in range(3):
        for k in ad[v]:
            jar = list(x)
            if x[k]+x[v] <= can[k]:
                jar[k] = x[v]+x[k]
                jar[v] = 0
            else:
                jar[k] = can[k]
                jar[v] = x[v]+x[k]-can[k]
            jar = tuple(jar)
            if jar[0] == x[0]:
                t = abs(jar[1]-x[1])+cs[x]
            elif jar[2] == x[2]:
                t = abs(jar[0]-x[0])+cs[x]
            elif jar[1] == x[1]:
                t = abs(jar[2]-x[2])+cs[x]
            yield jar,t
def main():
    global can,cs,d,ans
    for k in range(int(stdin.readline())):
        ans = defaultdict(lambda: inf)
        cs = defaultdict(lambda: inf)
        a,b,c,d = map(int,stdin.readline().split())
        can = (a,b,c)
        ini = (0,0,c)
        Q = deque((ini,))
        cos = deque((0,))
        if d in ini:stdout.write('0 {}\n'.format(d));continue
        while Q:
            x = Q.popleft()
            ps = cos.popleft()
            for v,adyp in ady(x,ps):
                Q.append(v)
                cos.append(adyp)
        while not d in ans or ans[d] == inf:
            d -= 1
        print(ans[d],d)
main()
