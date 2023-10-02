def solve(n, a):
    ans = 0.0
    for i in range(n):
        for j in range(i + 1, n):
            cur = 0
            if a[j] < a[i]:
                cur += (a[i] - a[j]) * a[j]
                cur += (a[j] * (a[j] - 1)) // 2
            else:
                cur += (a[i] * (a[i] - 1)) // 2
            ans += cur / (a[j] * a[i])
    return ans

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    ans = solve(n, a)
    print("{:.6f}".format(ans))