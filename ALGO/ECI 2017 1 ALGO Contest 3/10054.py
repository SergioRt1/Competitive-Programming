from sys import stdin,stdout,setrecursionlimit
setrecursionlimit(999999)
#Sergio Andres Rodriguez Torres
#Veredicto: TimeLimit(Python)
def dfs(x):
    for y in oc[x]:
        if oc[x][y]:
            oc[x][y] -= 1
            oc[y][x] -= 1
            dfs(y)
            print(y,x)
def main():
    global oc
    VAL = int(stdin.readline())
    va = VAL-1
    for t in range(VAL):
        fa = False
        oc = {}
        con = {}
        stdout.write("Case #{}\n".format(t+1))
        for k in range(int(stdin.readline())):
            a,b = map(int,stdin.readline().split())
            if a in con: con[a] += 1
            else: con[a] = 1
            if b in con: con[b] += 1
            else: con[b] = 1
            if a in oc:
                if b in oc[a]: oc[a][b] += 1
                else: oc[a][b] = 1
            else: oc[a] = {b:1}
            if b in oc:
                if a in oc[b]: oc[b][a] += 1
                else: oc[b][a] = 1
            else: oc[b] = {a:1}
        print(oc)
        for i in con:
            if con[i] % 2:
                fa = True
                break
        if fa: stdout.write("some beads may be lost\n")
        else: dfs(i)
        if t != va: stdout.write("\n")
main()
