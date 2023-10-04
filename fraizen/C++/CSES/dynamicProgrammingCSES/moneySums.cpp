#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define MAXN 100008

// NO FUNCIONA. Este era con dp(i,k) = true solo si es posible
// sumar k usando los primeros i numeros. 

bitset<MAXN> dp;

void solve(int k) {
    vector<int> res;
    fr(0,k+1){
        rep(j,1,i/2 + 1){
            if (dp[i]){
                break;
            }
            dp[i] = (dp[i-j] & dp[j]) | dp[i];
        }
    }
    fr(0,k+1){
        cout << dp[i] << ' ';
    }
    // fr(0,k+1){
    //     if (dp[i]){
    //         cout << i << ' ';
    //     }
    // }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    dp.reset();
    int n;
    cin >> n;
    fr(0,n){
        dp[i] = 0;
    }
    int k = 0;
    fr(0,n){
        int a;
        cin >> a;
        k += a;
        while (dp[a] == 1){
            a += a;
        }
        dp[a] = 1;
    }

    solve(k);
}