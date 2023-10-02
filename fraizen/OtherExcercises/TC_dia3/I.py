def solve(number): 
    ans = 0
    for s in number:
        if s == '0' or s == '4' or s == '8':
            ans += 1
    for i in range(len(number) - 1):
        if ((int(number[i]) * 10 + int(number[i+1])) % 4 == 0):
            ans += i + 1
    print(ans)
 
 
solve(input())