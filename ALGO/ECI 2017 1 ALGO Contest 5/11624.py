from sys import stdin,stdout
from collections import deque
dx = (0,-1,1,0)
dy = (1,0,0,-1)
def dfsJ(ini):
    global padj
    Q = deque()
    pos = deque()
    pos.append(0)
    for k in range(4):
        X, Y = dx[k] + ini[0], dy[k] +ini[1]
        if X >= 0 and Y >= 0 and X < R and Y < C:
            ad = (X,Y)
            if not ad in padj and graf[X][Y] == ".":
                padj[ad] = ini
                Q.append(ad)
                pos[-1]+= 1
        else:
            yield 1
    while Q:
        x = Q.popleft()
        pos.append(0)
        pos[0]-=1
        if not pos[0]:
            pos.popleft()
            yield 0
        for k in range(4):
            X, Y = dx[k] + x[0], dy[k] +x[1]
            if X >= 0 and Y >= 0 and X < R and Y < C:
                ad = (X,Y)
                if not ad in padj and graf[X][Y] == ".":
                    padj[ad] = x
                    Q.append(ad)
                    pos[-1]+= 1
            else:
                c = 1
                ob = x
                while True:
                    if padj[ob] == ob:break
                    ob = padj[ob]
                    c += 1
                yield c
        
def dfsF(fu):
    Q = deque()
    pos = deque()
    pos.append(0)
    for k in range(4):
        X, Y = dx[k] + fu[0], dy[k] +fu[1]
        if X >= 0 and Y >= 0 and X < R and Y < C:
            ad = (X,Y)
            if graf[X][Y] == ".":
                padj[ad] = fu
                Q.append(ad)
                pos[-1]+= 1
    while Q:
        x = Q.popleft()
        pos.append(0)
        pos[0] -= 1
        graf[x[0]][x[1]] = "F"
        if not pos[0]:
            pos.popleft()
            yield
        for k in range(4):
            X, Y = dx[k] + x[0], dy[k] +x[1]
            if X >= 0 and Y >= 0 and X < R and Y < C:
                ad = (X,Y)
                if graf[X][Y] == ".":
                    Q.append(ad)
                    pos[-1]+= 1
    
def main():
    global graf,padj,padf,R,C
    for k in range(int(stdin.readline())):
        R,C = map(int,stdin.readline().split())
        graf=[None]*R
        bus,busf = True,True
        for k in range(R):
            graf[k] = stdin.readline().strip()
            if bus:
                p = graf[k].find("J")
                if p != -1:
                    bus = False
                    ini = (k,p)
            if busf:
                p = graf[k].find("F")
                if p != -1:
                    busf = False
                    fu = (k,p)
            graf[k] = list(graf[k])
        padj = {ini:ini}
        padf = {fu:fu}
        J = dfsJ(ini)
        F = dfsF(fu)
        s = True
        while True:
            if s:
                try:next(F)
                except StopIteration:s=False
            try:ans = next(J)
            except StopIteration:stdout.write("IMPOSSIBLE\n");break
            if ans:
                print(ans);break
main()
