from sys import stdin,stdout
from collections import deque,defaultdict
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def main():
    while True:
        nk, np = map(int,stdin.readline().split())
        if not np+nk:break
        cap = defaultdict(lambda : defaultdict(int))
        V = nk+np+2
        flu = defaultdict(lambda : defaultdict(int))
        n = stdin.readline().split()
        tm = nk+np+1
        totf = 0
        for cat in range(nk):
            f = int(n[cat])
            cap[cat+np+1][tm] = f
            flu[cat+np+1][tm] = 0
            totf += f
        for k in range(1,1+np):cap[0][k] = 1;flu[0][k] = 0
        for pr in range(np):
            n = stdin.readline().split()
            for k in range(1,len(n)):
                cap[pr+1][int(n[k])+np] = 1
                flu[pr+1][int(n[k])+np] = 0
        maxf = 0
        while True:
            end = False
            pad = {0:0}
            Q = deque((0,))
            while Q:
                x = Q.popleft()
                for ad in flu[x]:
                    if cap[x][ad]-flu[x][ad] > 0 and ad not in pad:
                        pad[ad] = x
                        Q.append(ad)
                        if ad == tm:
                            end = True;break
                if end:break
            else:break
            minf = 1
            ob = tm
            while True:
                if ob == pad[ob]:break
                flu[pad[ob]][ob] += 1
                flu[ob][pad[ob]] -= 1
                ob = pad[ob]
            maxf += minf
        if maxf == totf:
            stdout.write('1\n')
            for k in range(np+1,np+nk+1):
                im = False
                for cp in flu[k]:
                    if flu[k][cp] < 0:
                        if im:stdout.write(' ')
                        stdout.write(str(cp))
                        im = True
                stdout.write('\n')
        else:stdout.write('0\n')
main()
