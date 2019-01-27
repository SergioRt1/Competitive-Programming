from sys import stdin, stdout
from collections import deque
from math import inf
dx = (-1,0,0,1)
dy = (0,-1,1,0)
def main():
    for cas in range(int(stdin.readline())):
        N = int(stdin.readline())
        M = int(stdin.readline())
        maze = [[int(x) for x in stdin.readline().split()] for k in range(N)]
        dis = {(0,0):maze[0][0]}
        vis = set()
        act = 0
        bt = [deque() for k in range(11)]
        bt[0].append((0,0))
        ob = (N-1,M-1)
        fin = False
        while True:
            while not bt[act]:
                act += 1
                if act > 10: act = 0
            while bt[act]:
                Min = bt[act].popleft()
                vis.add(Min)
                if Min == ob:
                    fin = True
                    break
                for k in range(4):
                    X, Y = Min[0] + dx[k],  Min[1] + dy[k]
                    if X >= 0 and Y >= 0 and X < N and Y < M:
                        ad = (X,Y)
                        if not ad in vis:
                            if not ad in dis: dis[ad] = inf
                            if dis[ad] > dis[Min] + maze[X][Y]:
                                dis[ad] = dis[Min] + maze[X][Y]
                                bt[(act+maze[X][Y])%10].append(ad)
            if fin: break
        print(dis[ob])
main()

