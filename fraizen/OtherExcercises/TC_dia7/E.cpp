#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
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
#define fre(s) for(auto e:s)

void solve(ll n, vi pos) {
    ll l, r;
    l = r = n/2;
    ll res = 0;
    ll medio = pos[n/2];
    int i = 0;
    while (l > 0){
        l -= 1;
        i++;
        res += abs(medio - i - pos[l]);
    }
    int j = 0;
    while (r < n-1){
        r += 1;
        j++;
        res += abs(medio + j - pos[r]);
    }
    cout(res);
    // fr(0,n) {
    //     cout << pos[i] << ' ';
    // }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases > 0){
        int n;
        cin >> n;
        vi s(n);
        string fraizen;
        cin >> fraizen;
        int j = 0;
        fr(0,n){
            char c = fraizen[i];
            if (c == '*'){
                s[j] = i;
                j++;
            }
        }
        solve(j, s);
        cases-=1;
    }
}