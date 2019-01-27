from sys import stdin,stdout
from collections import deque,defaultdict
inf = 1 << 30
#Sergio Andres Rodriguez Torres
#Veredicto: Wrong answer
def main():
    while True:
        n = stdin.readline().strip()
        if not n: break
        n,m = map(int,n.split())
        N = n+n
        cap = [[0]*N for x in range(N)]
        flu = [[0]*N for x in range(N)]
        ini = {k for k in range(n)}
        obj = {k for k in range(n)}
        entr = defaultdict(lambda: defaultdict(int))
        #flu = defaultdict(lambda: defaultdict(int))
        for k in range(m):
            a,b = map(int,stdin.readline().split())
            cap[a+n][b] = inf
            entr[b][a+n] = 1
            #flu[a+n][b] = 0
            if a in obj:obj.remove(a)
            if b in ini:ini.remove(b)
        print(ini,obj)
        ini = ini.pop()
        obj = obj.pop()
        for k in range(n): cap[k][k+n] = 1;entr[k+n][k]
        cap[ini][ini+n] = cap[obj][obj+n] = inf
        Nants = 0
        while True:
            pad = {ini:ini}
            Q = deque((ini,))
            end = False
            while Q:
                x = Q.popleft()
                for ad in range(N):
                    if cap[x][ad]-flu[x][ad] > 0 and ad not in pad:
                        Q.append(ad)
                        pad[ad] = x
                        if ad == obj:
                            end = True;break
                if end: break
            else:break
            ob = obj
            while True:
                if ob == pad[ob]:break
                flu[pad[ob]][ob] += 1
                flu[ob][pad[ob]] -= 1
                for arc in entr[pad[ob]]:
                    if arc == ini and ob == obj:cap[arc][ob] = 0
                    else:cap[arc][ob] = 1
                    print('conecto',arc,ob,entr[pad[ob]])
                print(ob,pad[ob])
                ob = pad[ob]
            print('orm')
            Nants += 1
        print(Nants)
            
main()
        
        
