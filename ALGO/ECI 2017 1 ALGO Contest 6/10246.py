from sys import stdin,stdout
from math import inf
#Sergio Andres Rodriguez Torres
#Veredicto: Wrong Answer
def main():
    cas = 0
    im = False
    while True:
        c,r,q = map(int,stdin.readline().split())
        if 0 == c == r == q: break
        if cas: stdout.write("\n")
        cas += 1
        cos = [int(x) for x in stdin.readline().split()]
        graf = [[inf]*c for k in range(c)]
        for k in range(r):
            c1,c2,d = map(int,stdin.readline().split())
            c1-=1; c2-=1
            if d < graf[c1][c2]:
                ma = max(cos[c1],cos[c2])
                graf[c1][c2] = d+ma
                graf[c2][c1] = d+ma
        for k in range(c):
            for i in range(c):
                for j in range(c):
                    if graf[i][j] > graf[i][k] + graf[k][j]:
                        graf[i][j] = graf[i][k] + graf[k][j]
        stdout.write("Case #{}\n".format(cas))
        for k in range(q):
            c1,c2 = map(int,stdin.readline().split())
            d = graf[c1-1][c2-1]
            if d == inf: stdout.write("-1\n")
            else: print(d)
main()
