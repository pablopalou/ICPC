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
#define MAXN 100008
int a[MAXN];
int pos[MAXN];
bool dp[MAXN];

// NO ANDA. 
// La idea estaba bien pero no como iba procesando los nodos, hay que hacer un reverse topological ordering.
void solve(int n) {
    int curPos;
    dp[pos[n]] = false;
    cout << "Pongo dp[" << pos[n] << "] = " << dp[pos[n]] << endl;
    for(int i = n-1; i > 0; i--){
        curPos = pos[i];
        int offset = a[curPos];
        int cur = offset;
        bool llegoPosPerdedora = false;
        bool entre = false;

        while (curPos + cur <= n-1){   
            if (a[curPos+cur] > offset){
                entre = true;
                if (! dp[a[curPos+cur]]){
                    if (curPos == 0){
                        cout(a[curPos+cur]);
                    }
                    llegoPosPerdedora = true;
                }
            }     
            cur += offset;
        }

        cur = offset;
        while (curPos - cur >= 0){
            if (curPos == 0){
                cout("no deberia imprimir esto");
            }
            if (a[curPos-cur] > offset){
                entre = true;
                if (! dp[a[curPos-cur]]){
                    llegoPosPerdedora = true;
                }
            }
            cur += offset;
        }

        if (!entre){
            dp[curPos] = false;
        } else {
            // cout(llegoPosPerdedora);
            dp[curPos] = llegoPosPerdedora;
        }
        cout << "Pongo dp[" << curPos << "] = " << dp[curPos] << endl;
    }
    fr(0,n){
        cout << (dp[i]?"A":"B") << ' ';
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    memset(dp, false, sizeof(dp));
    fr(0,n){
        int b;
        cin >> b;
        a[i] = b;
        pos[b] = i;
    }
    // fr(0,n+1){
    //     cout << a[i] << ' ';
    // }
    // cout(' ');
    // fr(0,n+1){
    //     cout << dp[i] << ' ';
    // }
    // cout(' ');
    // return 0;
    solve(n);
}