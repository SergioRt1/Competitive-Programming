from sys import stdin,stdout
from collections import deque
from math import inf
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def main():
    for cas in range(1,int(stdin.readline())+1):
        stdout.write("Test Case {}.\n".format(cas))
        n = int(stdin.readline())
        graf = {}
        cit = set()
        for t in range(n):
            tem = stdin.readline().split()
            a = int(tem[2])
            fin = int(tem[3])
            b = (a+fin)%24
            if fin <= 12 and (a >= 18 or a < 6) and (b > 18 or b <= 6):
                cit.add(tem[0])
                cit.add(tem[1])
                a = a+24 if a < 18 else a
                b = b+24 if b < 18 else b
                if tem[0] in graf:
                    if tem[1] in graf[tem[0]]: graf[tem[0]][tem[1]].append((a,b))
                    else: graf[tem[0]][tem[1]] = [(a,b)]
                else: graf[tem[0]] = {tem[1]:[(a,b)]}
        ini, fin = stdin.readline().split()
        dis = {n:(inf,inf) for n in cit}
        dis[ini]= (0,18)
        vis = set()
        Q = deque((ini,))
        while Q:
            u = Q.popleft()
            vis.add(u)
            if u in graf:
                for v in graf[u]:
                    if not v in vis:
                        dd = (200,200)
                        for k in graf[u][v]:
                            di = (dis[u][0]+1,k[1]) if dis[u][1] > k[0] else (dis[u][0],k[1])
                            if di < dd: dd = di
                        if dis[v] > dd:
                            dis[v] = dd
                            Q.append(v)
        if fin in dis and dis[fin][0] != inf:stdout.write("Vladimir needs {} litre(s) of blood.\n".format(dis[fin][0]))
        else:stdout.write("There is no route Vladimir can take.\n")
main()
