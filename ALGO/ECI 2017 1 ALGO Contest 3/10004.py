from collections import deque
from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def bfs():
    Q = deque()
    for k in range(n):
        if m[0][k] and vis[k]:
            Q.append(k)
            color[k] = not color[0]
    while Q:
        t = Q.popleft()
        for k in range(n):
            if m[t][k]:
                if vis[k]:
                    vis[k] = False
                    Q.append(k)
                    color[k] = not color[t]
                else:
                    if color[k] ==  color[t]: return False
    return True 
def main():
    global color,vis,m,n
    while True:
        n = int(stdin.readline())
        if n == 0: break
        color = [False]*n
        vis = [True]*n
        m = [[False]*n for k in range(n)]
        for k in range(int(stdin.readline())):
            e,d = map(int,stdin.readline().split())
            m[e][d] = True
            m[d][e] = True
        if bfs(): stdout.write("BICOLORABLE.\n")
        else: stdout.write("NOT BICOLORABLE.\n")
main()
