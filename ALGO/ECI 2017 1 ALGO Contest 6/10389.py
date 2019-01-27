from sys import stdin,stdout
from math import sqrt,inf
from heapq import heappush, heappop
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def MaxHeap(A,i):
    l = 2*i
    r = (2*i) + 1
    large = l if l < len(A) and A[l] < A[i] else i
    if r < len(A) and A[r] < A[large]:  large =  r
    if large != i:
        A[i],A[large] = A[large],A[i]
        MaxHeap(A,large)

def BuildHeap(A):
    for x in range(len(A)//2,0,-1):MaxHeap(A,x)

def HeapIncrease(A,i,key):
    A[i] = key
    while i > 1 and A[i//2] > A[i]:
        A[i],A[i//2] = A[i//2],A[i]
        i //= 2

def InsertHeap(A,key):
    A.append(0)
    HeapIncrease(A,len(A)-1,key)
        
def DelFirst(A):
    retval = A[1]
    A[1] = A[len(A)-1]
    A.pop()
    MaxHeap(A,1)
    return retval

def main():
    N = int(stdin.readline())
    stdin.readline()
    for cas in range(N):
        if cas:stdout.write("\n")
        a,b,c,d = [int(x) for x in stdin.readline().split()]
        nod = [(a,b),(c,d)]
        x = 1
        y = 2
        graf = {}
        while True:
            est = (int(x) for x in stdin.readline().split())
            try:val = next(est)
            except StopIteration:break
            nod.append((val,next(est)))
            while True:
                val = next(est)
                if val == -1: break
                nod.append((val,next(est)))
                x1 = nod[-2][0]
                y1 = nod[-2][1]
                x2 = nod[-1][0]
                y2 = nod[-1][1]
                x += 1
                y += 1
                if not x in graf: graf[x] = {}
                if not y in graf: graf[y] = {}
                graf[x][y] = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
                graf[y][x] = graf[x][y]
            x += 1
            y += 1
        for i in range(y):
            for j in range(y):
                if not i in graf:
                    graf[i] = {}
                    graf[i][j] = sqrt( (nod[i][0]-nod[j][0])*(nod[i][0]-nod[j][0]) + (nod[i][1]-nod[j][1])*(nod[i][1]-nod[j][1]) )*4
                elif not j in graf[i]:
                    graf[i][j] = sqrt( (nod[i][0]-nod[j][0])*(nod[i][0]-nod[j][0]) + (nod[i][1]-nod[j][1])*(nod[i][1]-nod[j][1]) )*4
        Q = [(0,0),(0,0)]
        vis = set()
        dis = [inf]*y
        dis[0] = 0
        while Q:
            x = heappop(Q)
            vis.add(x[1])
            if x[1] == 1:break
            for ad in graf[x[1]]:
                if not ad in vis and dis[ad] > dis[x[1]] + graf[x[1]][ad]:
                    dis[ad] = dis[x[1]] + graf[x[1]][ad]
                    heappush(Q,(dis[ad],ad))
        print(int(dis[1]*6/4000+0.5))
                     
main()
