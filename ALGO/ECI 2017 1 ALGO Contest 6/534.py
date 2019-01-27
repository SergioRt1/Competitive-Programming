from sys import stdin,stdout
from operator import itemgetter
from math import sqrt
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def find(x):
    if x != par[x]:
        par[x] = find(par[x])
    return par[x]
def union(x,y):
    px = find(x)
    py = find(y)
    if px == py: return
    if rank[px] < rank[py]: par[px] = py
    else:
        par[py] = px
        if rank[py] == rank[px]: rank[px] += 1
def main():
    global par, rank
    cas = 0
    while True:
        cas += 1
        n = int(stdin.readline())
        if not n: break
        par = [k for k in range(n)]
        rank = [0]*n
        pos = [tuple(int(x) for x  in stdin.readline().split()) for k in range(n)]
        nod = []
        for i in range(n):
            for sig in range(i+1,n):
                nod.append((i,sig,sqrt( (pos[i][0] - pos[sig][0]) * (pos[i][0] - pos[sig][0]) + (pos[i][1] - pos[sig][1]) * (pos[i][1] - pos[sig][1]))))
        nod.sort(key = itemgetter(2))
        i = 0
        e = 0
        N = n - 1
        while e < n:
            x = find(nod[i][0])
            y = find(nod[i][1])
            if x != y:
                e += 1
                union(x,y)
            if find(0) == find(1):
                print("Scenario #{}\nFrog Distance = {:.3f}\n".format(cas,nod[i][2]))
                break
            i += 1
        stdin.readline()
main()   
