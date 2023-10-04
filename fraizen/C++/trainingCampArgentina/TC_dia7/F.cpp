#include <bits/stdc++.h>
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

void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll cases, n, m;
    cin >> cases;
    ll cantPar = 0;
    ll cantImpar = 0;
    ll cantParB = 0;
    ll cantImparB = 0;
    ll res;
    ll p;
    while (cases){
        cin >> n;
        cantPar = 0;
        cantImpar = 0;
        cantParB = 0;
        cantImparB = 0;
        fr(0,n){
            cin >> p;
            if (p & 1){
                cantImpar += 1;
            } else {
                cantPar += 1;
            }
        }
        cin >> m;
        fr(0,m){
            cin >> p;
            if (p & 1){
                cantImparB += 1;
            } else {
                cantParB += 1;
            }
        }
        res = 0;
        res = cantPar * cantParB + cantImpar * cantImparB;
        cout(res);
        cases-=1;
    }

    // solve(n,m,k,a);
}