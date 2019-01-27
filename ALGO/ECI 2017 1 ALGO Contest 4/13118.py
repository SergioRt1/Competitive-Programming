from sys import stdin,stdout
from collections import deque
#Sergio Andres Rodriguez Torres
#Veredicto: TimeLimit
#from time import time
#ti = time()
dx = (0,1,-1,0)
dy = (-1,0,0,1)
dy2 = (1,0,0,-1)
def ady(x,y,d):
    for k in range(4):
        x1,y1 = x+dx[k],y+d[k]
        if x1 >= 0 and y1 >= 0:
            try:
                if maze[x1][y1] == ".": yield x1,y1
                else: yield x,y
            except IndexError: yield x,y
        else: yield x,y
        
def ent(x): return int(x)-1
def main():
    global maze
    while True:
        try: X, Y = map(int,stdin.readline().split())
        except ValueError: break
        xl,yl,xg,yg,xm,ym = map(ent,stdin.readline().split())
        maze = [stdin.readline().strip() for k in range(X)]
        if xl == xg == xm and yl == yg == ym: stdout.write("0\n");continue
        ini = ((xg,yg),(xm,ym))
        pad = {ini:ini}
        Q = deque((ini,))
        enc = False
        while Q:
            if enc: break
            v = Q.popleft()
            g = ady(*v[0],dy)
            m = ady(*v[1],dy2)
            for _ in range(4):
                ad = (next(g),next(m))
                if not ad in pad and not ad[::-1] in pad:
                    pad[ad] = v
                    if ad[0][0] == xl == ad[1][0] and ad[1][1] == yl == ad[0][1]: 
                        enc = ad
                        break
                    Q.append(ad)
        if enc:
            c = 0
            while True:
                if pad[enc] == enc: break
                enc = pad[enc]
                c += 1
            print(c)
        else: stdout.write("NO LOVE\n")
            
main()
#ts = time()-ti
#print("Total: {}s --> minutos: {:.0f}, segundos: {}".format(ts,ts//60,ts%60))
