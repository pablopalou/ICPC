#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n,q; cin >> n >> q;
    string s1,s2; cin >> s1 >> s2;
    vector<vector<int>> cant1(26, vector<int>(s1.size(),0));
    vector<vector<int>> cant2(26, vector<int>(s2.size(),0));
    fr(0,s1.size()){
        if (i > 0){
            rep(j,0,26){
                cant1[j][i] = cant1[j][i-1];
            }
        }
        cant1[s1[i] - 'a'][i] += 1;
    }
    // rep(j,0,5){
    //     fr(0,s1.size()){
    //         cout << cant1[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    fr(0,s2.size()){
        if (i > 0){
            rep(j,0,26){
                cant2[j][i] = cant2[j][i-1];
            }
        }
        cant2[s2[i] - 'a'][i] += 1;
    }
    // rep(j,0,5){
    //     fr(0,s2.size()){
    //         cout << cant2[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;
    fr(0,q){
        ll l,r; cin >> l >> r; r--; l--;
        ll res = r - l + 1;
        ll iguales = 0;
        rep(j,0,26){
            ll del1 = cant1[j][r];
            if (l > 0){
                del1 -= cant1[j][l-1];
            }
            // cout <<"letra " << j << " en palabra 1 tiene " << del1 << endl;
            ll del2 = cant2[j][r];
            if (l > 0){
                del2 -= cant2[j][l-1];
            }
            // cout <<"letra " << j << " en palabra 2 tiene " << del1 << endl;
            // cout << "Minimo es = " << min(del1, del2) << endl;
            iguales += min(del1, del2);
        }
        res -= iguales;
        cout << res << '\n';
    }
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