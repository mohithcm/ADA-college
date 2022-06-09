t = int(input())
for _ in range(t):
    n = int(input())
    m = int(input())
    if m>n*n:
        print("Not Possible")
        exit(0)
    ans = ""
    for i in range(1,n+1):
        ans += chr(64 + m//pow(n, i-1))
        
    print(ans)