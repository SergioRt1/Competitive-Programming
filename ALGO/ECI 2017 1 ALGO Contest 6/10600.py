from sys import stdin,stdout
from operator import itemgetter
from collections import deque
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def find(x):
    while par[x] != x: x = par[x]
    return x
def union(x,y):
    px = find(x)
    py = find(y)
    if px == py: return
    if rank[px] < rank[py]: par[px] = py
    else:
        par[py] = px
        if rank[py] == rank[px]: rank[px] += 1
def BFS():
    Q = deque((0,))
    nvi = n
    vis = {0}
    while Q:
        x = Q.popleft()
        nvi -= 1
        for ad in graf[x]:
            if not ad in vis and graf[x][ad]:
                vis.add(ad)
                Q.append(ad)
    if nvi: return True
    return False
def main():
    global par, rank, n,graf
    for cas in range(1,int(stdin.readline())+1):
        n,m = map(int,stdin.readline().split())
        graf = [{} for k in range(n)]
        par = [k for k in range(n)] 
        rank = [0]*n
        nod = []
        for k in range(m):
            u,v,w = map(int,stdin.readline().split())
            u -= 1; v-= 1
            nod.append((u,v,w))
            if v in graf[u]: graf[u][v] += 1; graf[v][u] += 1
            else: graf[u][v] = 1; graf[v][u] = 1
        ans = []
        nod.sort(key = itemgetter(2))
        i = 0
        e = 0
        N = n-1
        while e < N:
            x = find(nod[i][0])
            y = find(nod[i][1])
            if x != y:
                e += 1
                ans.append(nod[i])
                union(x,y)
            i += 1
        sec = 99999999999999999
        mej = sum(k[2] for k in ans)
        for no in ans:
            sans = []
            graf[no[0]][no[1]] -= 1
            graf[no[1]][no[0]] -= 1
            if BFS():
                graf[no[0]][no[1]] += 1
                graf[no[1]][no[0]] += 1
                continue
            par = [k for k in range(n)]
            rank = [0]*n
            i = 0
            e = 0
            while e < N:
                if nod[i] == no: i += 1
                x = find(nod[i][0])
                y = find(nod[i][1])
                if x != y:
                    e += 1
                    sans.append(nod[i])
                    union(x,y)
                i += 1
            tem = sum(k[2] for k in sans)
            if sec > tem: sec = tem
            graf[no[0]][no[1]] += 1
            graf[no[1]][no[0]] += 1
        stdout.write("{} {}\n".format(mej,sec))
main()
