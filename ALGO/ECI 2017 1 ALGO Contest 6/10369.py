from sys import stdin,stdout,setrecursionlimit
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
    if px == py: return False
    if rank[px] < rank[py]: par[px] = py
    else:
        par[py] = px
        if rank[py] == rank[px]: rank[px] += 1
    return True
def main():
    global par, rank
    for k in range(int(stdin.readline())):
        e,n = map(int,stdin.readline().split())
        par = [k for k in range(n)]
        rank = [0]*n
        pos = [tuple(int(x) for x  in stdin.readline().split()) for k in range(n)]
        nod = []
        for i in range(n):
            for sig in range(i+1,n):
                nod.append((i,sig,sqrt( (pos[i][0] - pos[sig][0]) * (pos[i][0] - pos[sig][0]) + (pos[i][1] - pos[sig][1]) * (pos[i][1] - pos[sig][1]))))
        nod.sort(key = itemgetter(2))
        ans = 0
        i = 0
        while e < n:
            x = find(nod[i][0])
            y = find(nod[i][1])
            if x != y:
                e += 1
                union(x,y)
            i += 1
        stdout.write("{:.2f}\n".format(nod[i-1][2]))
main()   
