from sys import stdin, stdout
from collections import deque
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
lst=[]
index = 0
def nextint():
    global lst,index
    while index == len(lst):
        index = 0
        lst = [int(x) for x in stdin.readline().split()]
    index += 1
    return lst[index-1]
def bfs(x,pad,ob):
    if x == ob:
        pad[ob] = x
        return True
    Q = deque()
    Q.append(x)
    while Q:
        x = Q.popleft()
        for k in (((x[0]+1)%10,x[1],x[2],x[3]),(x[0],(x[1]+1)%10,x[2],x[3]),(x[0],x[1],(x[2]+1)%10,x[3]),(x[0],x[1],x[2],(x[3]+1)%10),
                 ((x[0]-1)%10,x[1],x[2],x[3]),(x[0],(x[1]-1)%10,x[2],x[3]),(x[0],x[1],(x[2]-1)%10,x[3]),(x[0],x[1],x[2],(x[3]-1)%10)):
            if not k in pad:
                pad[k] = x
                if k == ob: return True
                Q.append(k)
    return False
def main():
    for k in range(nextint()):
        ini = tuple(nextint() for x in range(4))
        ob = tuple(nextint() for x in range(4))
        pad = {ini:ini}
        for k in range(nextint()):
            t = tuple(nextint() for x in range(4))
            pad[t] = None
        if bfs(ini,pad,ob):
            ans = 0
            while True:
                if pad[ob] == ob: break
                ob = pad[ob]
                ans += 1
            print(ans)
        else: stdout.write("-1\n")
        stdin.readline()
main()
