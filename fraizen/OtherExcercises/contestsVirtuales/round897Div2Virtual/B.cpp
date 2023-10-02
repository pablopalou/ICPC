#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double d;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
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
#define MAXN 1000008

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    bool impar = false;
    if (n&1){
        impar = true;
    }
    int distintos = 0;
    int iguales = 0;
    fr(0,n/2){
        if (s[i] == s[n-1-i]){
            iguales ++;
        } else {
            distintos++;
        }
    }
    fr(0,n+1){
        if (i < distintos){
            cout << '0';
        } else if (i==distintos){
            cout << '1';
        } else {
            if (impar){
                if (i <= distintos + iguales * 2 + 1){
                    cout << '1';
                } else {
                    cout << '0';
                }
            } else {
                if (i <= distintos + iguales * 2){
                    if (distintos % 2 == i % 2){
                        cout << '1';
                    } else {
                        cout << '0';
                    }
                } else {
                    cout << '0';
                }
            }
        }
    }
    cout(' ');
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}