from sys import stdin, stdout
from collections import deque
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def main():
    while True:
        n = stdin.readline().strip()
        if not n:break
        cap = [[0]*38 for k in range(38)]
        flu = [[0]*38 for k in range(38)]
        totf = 0
        for pc in range(1,11):cap[0][pc] = 1
        tr = []
        while True:
            act = ord(n[0])-54
            tr.append(act)
            num = int(n[1])
            totf += num
            cap[act][37] = num
            for pc in range(3,len(n)-1):
                cap[int(n[pc])+1][act] = 1
            n = stdin.readline().strip()
            if not n:break
        maxf = 0
        while True:
            end = False
            pad = {0:0}
            Q = deque((0,))
            while Q:
                x = Q.popleft()
                for ad in range(38):
                    if cap[x][ad]-flu[x][ad] > 0 and ad not in pad:
                        Q.append(ad)
                        pad[ad] = x
                        if ad == 37:
                            end = True;break
                if end:break
            if not end:break
            mflu = 99999999
            ob = 37
            while True:
                if pad[ob] == ob:break
                mflu = min(mflu,cap[pad[ob]][ob]-flu[pad[ob]][ob])
                ob = pad[ob]
            ob = 37
            while True:
                if pad[ob] == ob:break
                flu[pad[ob]][ob] += mflu
                flu[ob][pad[ob]] -= mflu
                ob = pad[ob]
            maxf += mflu
        if maxf == totf:
            ans = ['_']*10
            for pc in range(1,11):
                for act in tr:
                    if flu[pc][act] > 0:
                        ans[pc-1] = chr(act+54)
            print("".join(ans))
        else:print('!')
main()
