from sys import stdin,stdout
from operator import itemgetter
from math import sqrt
#Sergio Andres Rodriguez Torres
#Veredicto: TimeLimit(Python) 
def f(x,le):
    if le < 2:
        return 2047483647
    if le == 2:
        return (x[0][0]-x[1][0])**2+(x[0][1]-x[1][1])**2
    n = le//2
    a = f(x[:n],n)
    b = f(x[n:],le-n)
    d = min(a,b)
    dr = sqrt(d)
    di = x[n][0]-dr
    df = x[n][0]+dr
    Y = [k for k in y if di < k[0] < df]
    leY = len(Y)
    for p in range(leY):
        for com in range(1,7):
            if com+p < leY:
                cal = (Y[p][0]-Y[com+p][0])**2+(Y[p][1]-Y[com+p][1])**2
                if d > cal:
                    print("mejoro",d,"->",cal)
                    d = cal
            else: break
    return d
def main():
    global y
    while True:
        n = int(stdin.readline())
        if n == 0: break
        P = sorted(([float(x) for x in stdin.readline().split()] for k in range(n)),key = itemgetter(0))
        y = sorted(P,key = itemgetter(1))
        ans = f(P,n)
        if ans >= 100000000: stdout.write("INFINITY\n")
        else:stdout.write("{:.4f}\n".format(sqrt(ans)))
main()
