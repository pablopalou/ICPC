#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>

#define MAX_N 1000
#define rBOUND(x) (x < n ? r[x] : 0)

int sa[MAX_N], r[MAX_N], n;
string s; // input string, n=s.size()
int f[MAX_N], tmpsa[MAX_N];

void countingSort(int k)
{
    memset(f, 0, sizeof(f));
    forn(i, n) f[rBOUND(i + k)]++;
    int sum = 0;
    forn(i, max(255, n))
    {
        int t = f[i];
        f[i] = sum;
        sum += t;
    }
    forn(i, n)
        tmpsa[f[rBOUND(sa[i] + k)]++] = sa[i];
    memcpy(sa, tmpsa, sizeof(sa));
}

void constructsa()
{
    n = s.size();
    forn(i, n) sa[i] = i, r[i] = s[i];
    for (int k = 1; k < n; k <<= 1)
    {
        countingSort(k), countingSort(0);
        int rank, tmpr[MAX_N];
        tmpr[sa[0]] = rank = 0;
        for (int i = 1; i < n; i++)
        {
            tmpr[sa[i]] = (r[sa[i]] == r[sa[i - 1]] && r[sa[i] + k] == r[sa[i - 1] + k])
                              ? rank
                              : ++rank;
        }
        memcpy(r, tmpr, sizeof(r));
        if (r[sa[n - 1]] == n - 1) break;
    }
}

void print()
{
    forn(i, n)
        cout << i << " " << s.substr(sa[i], s.find('$', sa[i]) - sa[i]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.size();
    constructsa();
    print();
    // Add your test input and function calls here

    return 0;
}