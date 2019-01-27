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
        #cap = [[0]*n for x in range(n)]
        #flu = [[0]*n for x in range(n)]
        ini = {k for k in range(n)}
        obj = {k for k in range(n)}
        entr = defaultdict(lambda: defaultdict(int))
        flu = defaultdict(lambda: defaultdict(int))
        cap = defaultdict(lambda: defaultdict(int))
        for k in range(m):
            a,b = map(int,stdin.readline().split())
            cap[a][b] = 1
            entr[b][a] = 1
            flu[a][b] = 0
            if a in obj:obj.remove(a)
            if b in ini:ini.remove(b)
        print(ini,obj)
        ini = ini.pop()
        obj = obj.pop()
        Nants = 0
        while True:
            pad = {ini:ini}
            Q = deque((ini,))
            end = False
            while Q:
                x = Q.popleft()
                for ad in flu[x]:
                    if cap[x][ad]-flu[x][ad] > 0 and ad not in pad:
                        Q.append(ad)
                        pad[ad] = x
                        if ad == obj:
                            end = True;break
                if end: break
            else:break
            ob = obj
            cam = []
            while True:
                if ob == pad[ob]:break
                flu[pad[ob]][ob] += 1
                flu[ob][pad[ob]] -= 1
                cam.append(ob)
                print(ob,pad[ob])
                ob = pad[ob]
            for nod in reversed(cam):
                print("Nodo",nod,'Sali',dict(cap[nod]),'ent',dict(entr[nod]))
                for sal in cap[nod]:
                    for ent in entr[nod]:
                        cap[ent][sal] = 1
                        flu[ent][sal] = 0
                        print(ent,'->',sal)
            print(cam)
            print('orm')
            Nants += 1
        print(Nants)
            
main()
        
        
