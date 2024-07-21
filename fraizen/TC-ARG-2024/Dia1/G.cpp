#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MOD 1000000007

ll dp[50][10002];

ll expMod(ll b, ll e, ll m = MOD) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
    b = b * b % m;                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

int inverso(int x) {                    // O(log MOD)
  return expMod(x, MOD - 2);            // si mod es primo
}

void solve() {
    ll n,k; cin >> n >> k;
	ll nReal = n;
    map<ll,ll> f;
	for(ll i=2;i*i<=n;i++){
		while(n%i==0){
			f[i]++;
			n/=i;
		}
	}
    if(n>1) f[n]++;
    n = nReal;
    ll ans = 1;
    //aca ya tengo la factorizacion.
    //ahora necesito por cada primo de la factorizacion, hacer la dp.
    fre(f){
        memset(dp, 0, sizeof(dp));
        //aca tengo que hacer la dp
        ll primo = e.first;
        ll alpha = e.second;
        dp[alpha][0] = 1;
        fr(0,alpha){
            dp[i][0] = 0;
        }
        // fr(0,k+1){
        //     dp[0][i] = 1;
        // }
        cout << "primo " << primo << endl;
        cout << "alpha " << alpha << endl;
        fr(1,alpha+1){
            rep(steps, 1, k+1){
                cout << "I = " << i << " steps = " << steps << endl;
                ll cur2 = 1;
                rep(beta, 0, i){
                    cur2 *= ((dp[i-beta][steps-1] % MOD) * expMod(e.first, beta) ) % MOD; //(inverso(i-beta) % MOD)
                }
                dp[i][steps] = cur2;
            }
        }
        fr(0,e.second){
            rep(steps, 0, k){
                cout << dp[i][steps] << " ";
            }
            cout << endl;
        }
        //calculo esta dp:
        ll cur = 1;
        rep(beta,0,e.second){
            cur = (cur * (((dp[beta][k] % MOD)) % MOD)) % MOD;
        }
        ans = (ans * (cur % MOD)) % MOD;
    }
    cout << ans << '\n';
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}