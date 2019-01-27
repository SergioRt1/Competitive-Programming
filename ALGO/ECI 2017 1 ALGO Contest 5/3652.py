from sys import stdin,stdout
from collections import deque
from math import inf
#Sergio Andres Rodriguez Torres
#Veredicto: TimeLimit
#Implementando Bucket Dijkstra
dx = (-2,-2,-2,-2,-2,
      -1,-1,-1,-1,-1,
      0,0,0,0,
      1,1,1,1,1,
      2,2,2,2,2)
dy = (-2,-1,0,1,2,
      -2,-1,0,1,2,
      -2,-1,1,2,
      -2,-1,0,1,2,
      -2,-1,0,1,2)
cal = (7,6,5,6,7,
       6,3,2,3,6,
       5,2,2,5,
       6,3,2,3,6,
       7,6,5,6,7)
def ady(x,y):
    for k in range(24):
        X, Y = x + dx[k], y + dy[k]
        if X >= 0 and Y >= 0 and X < R and Y < C:
            if not (X,Y) in vis:
                yield (X, Y), cal[k]    
def main():
    global C, R,vis
    while True:
        C, R = map(int,stdin.readline().split())
        if C == 0 == R: break
        vis = set()
        yr, xr, yt, xt = (int(k)-1 for k in stdin.readline().split())
        for charco in (stdin.readline().split() for k in range(int(stdin.readline()))):
            c1,r1,c2,r2 = map(int,charco)
            for i in range(r1-1,r2): [vis.add((i,j)) for j in range(c1-1,c2)]
        ob = (xt,yt)
        bt = [deque() for k in range(8)]
        dis = {(xr,yr):0}
        act = 0
        bt[0].append((xr,yr))
        fin = False
        sal = 0
        while True:
            while not bt[act]:
                if sal > 8:
                    fin = True
                    break
                sal += 1
                act += 1
                if act > 7:
                    act = 0
            else: sal = 0      
            while bt[act]:
                Min = bt[act].popleft()
                vis.add(Min)
                if Min == ob:
                    fin = True
                    break
                for ad in ady(*Min):
                    if not ad[0] in dis: dis[ad[0]] = inf
                    if dis[ad[0]] > dis[Min] + ad[1]:
                        dis[ad[0]] = dis[Min] + ad[1] 
                        bt[(act+ad[1])&7].append(ad[0])
            if fin: break
        if ob in dis:
            print(dis[ob])
        else: stdout.write('impossible\n')
main()
