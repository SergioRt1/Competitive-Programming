from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Time limit exceeded
def main():
    v = [0]*3 
    for l in stdin.readlines():
        l = l.strip()
        c = v[1] = v[2] = 0
        v[0] = 1
        r = 0
        for i in l:
            if not i.isdigit():
                c = v[1] = v[2] = 0
                v[0] = 1
                continue
            c = (c + int(i))%3
            r += v[c]
            v[c] += 1
        print(r)
main()
