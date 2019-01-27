from sys import stdin,stdout
from operator import itemgetter
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
def main():
    con = 0
    while True:
        con += 1
        graf = {}
        val = []
        N = nextint()
        R = nextint()
        if N == 0 == R: break
        for k in range(R):
            ls = [nextint() for x in range(3)]
            val.append(ls)
            if ls[0] in graf: graf[ls[0]][ls[1]] = ls[2]
            else: graf[ls[0]] = {ls[1]:ls[2]}
            if ls[1] in graf: graf[ls[1]][ls[0]] = ls[2]
            else: graf[ls[1]] = {ls[0]:ls[2]}
        lst = [nextint() for x in range(3)]
        val.sort(key = itemgetter(2),reverse = True)
        end = False
        maxv = 0
        for k in val:
            if end: break
            vis = set()
            Q = deque((k[0],))
            while Q:
                x = Q.popleft()
                vis.add(x)
                if lst[0] in vis and lst[1] in vis:
                    end = True
                    maxv = k[2]
                    break
                for v in graf[x]:
                    if not v in vis and graf[x][v] >= k[2]:
                        Q.append(v)
        ans = lst[2]/(maxv-1)
        stdout.write("Scenario #{}\n".format(con))
        if ans == int(ans):stdout.write("Minimum Number of Trips = {}\n\n".format(int(ans)))
        else:stdout.write("Minimum Number of Trips = {}\n\n".format(int(ans)+1))
main()
