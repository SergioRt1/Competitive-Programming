from sys import stdin,stdout
def main():
    stdin.readline()
    ans = ""
    while True:
        line = stdin.readline().strip()
        if line[0]=='_':break
        bi = ""
        for k in range(2,10):
            if line[k] == '.':continue
            if line[k] == 'o':
                bi+="1"
            else: bi += "0"
        ans += chr(int(bi,2))
    stdout.write(ans)
main()
