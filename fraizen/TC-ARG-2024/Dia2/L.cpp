#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n; cin >> n;
    int a[n]; fr(0,n) cin >> a[i];
    int bits[31];
    memset(bits, 0, sizeof(bits));
    bool todoCero = true;
    fr(0,n){
        if (a[i]!=0){
            todoCero = false;
        }
    }
    if (todoCero){
        fr(1,n+1){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    fr(0,n){
        rep(j,0,31){
            if (a[i] & (1<<j)){
                bits[j]++;
            }
        }
    }
    // la solucion va hasta n
    // int mini = 1e9;
    // fr(0,31){
    //     if (bits[i]!=0){
    //         mini = min(mini, bits[i]);
    //     }
    // }
    // if (mini == 1){
    //     cout << 1 << '\n'; return;
    // }
    //tengo que poner todos los divisores. 
    vector<ll> res;
    fr(1,n+1){
        bool vale = true;
        rep(j,0,31){
            if (bits[j] != 0 && (bits[j] % i != 0)){
                vale = false;
                break;
            }
        }
        if (vale){
            res.pb(i);
        }
    }
    fre(res){
        cout << e << ' ';
    }
    cout << '\n';
    return;

    //mini es distinto de 1, hay que ver si divide al resto
    // bool divide = true;
    // fr(0,n){
    //     if ((bits[i] != 0) && (bits[i] % mini != 0)){
    //         divide = false;
    //     }
    // }
    // // cout << "mini " << mini << endl;
    // // cout << "divide " << divide << endl;
    // if (!divide){
    //     cout << 1 << '\n';
    //     return;
    // }
    // //tendria que agarrar todos los divisores me parece de este mini
    // set<int> res;
    // res.insert(1);
    // res.insert(mini);
    // // cout << "her3eee " << endl;
    // fr(2,sqrt(mini)+1){
    //     // cout << "here" << endl;
    //     if (mini % i == 0){
    //         res.insert(i);
    //         res.insert(mini/i);
    //     }
    // }
    // fre(res){
    //     cout << e << ' ';
    // }
    // cout << '\n';
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}