from sys import stdin,stdout
from collections import deque
from math import sqrt
from operator import itemgetter
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def main():
    while True:
        v,m = map(int,stdin.readline().split())
        if v == 0 == m: break
        F = 1/(60*v)
        dmax = v*60*m
        graf = {}
        nod = []
        while True:
            tm = (tuple(float(x) for x in stdin.readline().split()))
            if not tm:break
            nod.append(tm)
        ini = nod[0]
        ob = nod[1]
        nod.sort(key = itemgetter(0))
        le = len(nod)
        busi = True
        buso = True
        for i in range(le):
            if busi and nod[i] == ini: pi = i;busi = False
            if buso and nod[i] == ob: pb = i;buso = False
            for j in range(i+1,le):
                t = sqrt((nod[i][0]-nod[j][0])*(nod[i][0]-nod[j][0])+(nod[i][1]-nod[j][1])*(nod[i][1]-nod[j][1]))*F
                if t <= m:
                    if not i in graf: graf[i] = []
                    if not j in graf: graf[j] = []
                    graf[i].append(j)
                    graf[j].append(i)
                else:
                    if nod[j][0]-nod[i][0] > dmax: break
        pad = {pi:pi}
        Q = deque((pi,))
        fin = False
        while Q:
            x = Q.popleft()
            if x in graf:
                for ad in graf[x]:
                    if not ad in pad:
                        Q.append(ad)
                        pad[ad] = x
                        if ad == pb: fin = True;break
                if fin:break
        else: stdout.write("No.\n")
        if fin:
            can = 0
            ob = pb
            while True:
                if pad[ob] == pi:break
                ob = pad[ob]
                can += 1
            stdout.write("Yes, visiting {} other holes.\n".format(can))
main()
