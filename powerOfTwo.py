#https://codeforces.com/contest/702/problem/B

n = int(input())
numbers = input().split()
numbers = list(map(int, numbers))

ans = 0
s = {}
for x in numbers:
    for i in range(1, 32):
        if 2**i - x in s:
            ans += s[2**i - x]
        
    if x in s:
        s[x] += 1
    else:
        s[x] = 1

print(ans)
