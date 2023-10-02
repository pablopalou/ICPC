#include <bits/stdc++.h>
 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;
typedef map<int, string> mis;
typedef unordered_map<int, string> umis;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

ll modular_expo(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            res = ((res % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
        n = n / 2;
    }
    return res % mod;
}

void solve(int n, int m, int k) {
    ll res = 0;
    if (k == 1 || k>n){
        res = modular_expo(m,n);
    } else if (k == n){
        res = modular_expo(m, (n+1)/2 );
    } else if (k & 1){
        res = m * m;
    } else {
        res = m;
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    // int a[n]; 
    // fr(0,n){
    //     cin >> a[i];
    // }
    solve(n,m,k);
}
