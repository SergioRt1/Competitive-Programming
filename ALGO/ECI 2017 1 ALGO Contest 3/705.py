from sys import stdin,stdout
from collections import deque
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def main():
    cas = 0
    while True:
        cas +=1
        n,m = map(int,stdin.readline().split())
        if n == 0 == m: break
        stdout.write("Maze #{}:\n".format(cas))
        sl = [stdin.readline().strip() for k in range(m)]
        graf = [[[] for k in range(n)] for k in range(m+m-1)]
        for i in range(m+m-1):
            for j in range(n):
                a = i//2
                if not i%2:
                    if sl[a][j] == "/": graf[i][j].append((i+1,j))
                    else: graf[i][j].append((i-1,j))
                    if j+1 < n: 
                        if sl[a][j+1] == "/": graf[i][j].append((i-1,j+1))
                        else: graf[i][j].append((1+i,1+j))
                else:
                    if sl[a][j] == "/": graf[i][j].append((i-1,j))
                    else: graf[i][j].append((i-1,j-1))
                    if a+1 < m:
                        if sl[a+1][j] == "/": graf[i][j].append((i+1,j-1))
                        else: graf[i][j].append((i+1,j))
        vis = {(x,y) for x in range(m+m-1) for y in range(n)}
        bord = {(k*2,n-1) for k in range(m)}
        bord.update({(-1,k) for k in range(n)},{(k,-1) for k in range(0,m+m-1,2)},{(m+m-1,k) for k in range(n)})
        vis -= bord
        Max = -1
        cicl = 0
        while vis:
            ma = 0
            ini = vis.pop()
            Q = deque((ini,))
            cicl += 1
            while Q:
                no = False
                ma += 1
                x = Q.popleft()
                i,j = x
                for v in graf[i][j]:
                    if v in bord:
                        no = True
                    if v in vis:
                        vis.remove(v)
                        Q.append(v)
            if no:
                cicl -= 1
            else:
                if ma > Max:
                    Max = ma
        if cicl == 0: stdout.write("There are no cycles.\n\n")
        else: stdout.write("{} Cycles; the longest has length {}.\n\n".format(cicl,Max))  
main()
