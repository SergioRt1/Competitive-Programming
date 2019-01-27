from sys import stdin,stdout
def main():
    dic = {}
    while True:
        ln = stdin.readline().strip()
        if not ln: break
        a,b=ln.split()
        dic[b]=a
    while True:
        ln = stdin.readline().strip()
        if not ln: break
        if ln in dic: print(dic[ln])
        else: print("eh")
main()
