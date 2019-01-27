from sys import stdin,stdout
from collections import deque
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def enum(sec):
    n = 0
    for el in sec: yield el ,n; n+=1
def bfs(x):
    global vis
    Q = deque((p[x],))
    while Q:
        x = Q.popleft()
        print("vis",x)
        vis[x[1]] = True
        dm = 9999999
        m1 = x
        m2 = x
        for k in (-6,-5,-4,-3,-2,-1,1,2,3,4,5,6):
            ind = x[1]+k
            print(ind)
            if 0 <= ind < n:
                d2 = (p[ind][0][0]-x[0][0])**2+(p[ind][0][1]-x[0][1])**2
                print("dis",x,p[ind],d2)
                if d2 < dm:
                    dm = d2
                    m2 = m1
                    m1 = p[ind]
        if not vis[m1[1]] and m1 != x:
            Q.append(m1)
            if not vis[m1[1]] and m2 != m1 and m2 != x:
                Q.append(m2)
            
def main():
    global p,n,vis
    while True:
        n = int(stdin.readline())
        if n == 0: break
        ent = map(int,stdin.readline().split())
        p = [()]*n
        ind = 0
        for k in ent: p[ind] = (k,next(ent)); ind += 1
        print(p)
        ini = p[0]
        vis = [False]*n
        p.sort()
        ini = p.index(ini)
        p = list(enum(p))
        print(p)
        bfs(ini)
        for k in vis:
            if not k: stdout.write("There are stations that are unreachable.\n"); break
        else: stdout.write("All stations are reachable.\n")
main()
