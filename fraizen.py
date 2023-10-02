def solve(n, l):
    vacias = []
    ocupadas = []
    ans = 0
    for i, val in enumerate(l):
        if val:
            if len(vacias) > 0:
                ans += abs(i - vacias[-1])
                print('sumo ', abs(i - vacias[-1]))
                vacias.pop()
            else:
                ocupadas.append(i)
        else:
            if len(ocupadas) > 0:
                ans += abs(i-ocupadas[-1])
                print('sumo ', abs(i - ocupadas[-1]))
                ocupadas.pop()
            else:
                vacias.append(i)
    
    print(ans)  


solve(int(input()), list(map(int, input().split())))