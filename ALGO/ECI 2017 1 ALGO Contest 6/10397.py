from sys import stdin,stdout,setrecursionlimit
from operator import itemgetter
from math import sqrt
setrecursionlimit(999999)
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
lst=[]
index = 0
def nextint():
    global lst,index
    while index == len(lst):
        index = 0
        lst = [int(x) for x in stdin.readline().split()]
    index += 1
    return lst[index-1]

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
    while True:
        n = stdin.readline()
        if not n: break
        while not n.strip():
            n = stdin.readline()
            if not n: break
        if not n: break
        n = int(n)
        par = [k for k in range(n)]
        rank = [0]*n
        pos = [tuple(nextint() for x  in range(2)) for k in range(n)]
        nod = []
        for i in range(n):
            for sig in range(i+1,n):
                nod.append((i,sig,sqrt( (pos[i][0] - pos[sig][0]) * (pos[i][0] - pos[sig][0]) + (pos[i][1] - pos[sig][1]) * (pos[i][1] - pos[sig][1]))))
        nod.sort(key = itemgetter(2))
        ans = 0
        e = 0
        for m in range(nextint()):
            a = nextint()
            b = nextint()
            if union(a-1,b-1):
                e += 1
        i = 0
        N = n - 1
        while e < N:
            x = find(nod[i][0])
            y = find(nod[i][1])
            if x != y:
                ans += nod[i][2]
                e += 1
                union(x,y)
            i += 1
        stdout.write("{:.2f}\n".format(ans))
main()   
