#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    string s1; string s2; cin >> s1 >> s2;
    if (s1.size() > s2.size()){
        //pongo 0's adelante del s2.
        string zeros(s1.size() - s2.size(),'0'); 
        s2 = zeros + s2;
    } else {
        string zeros(s2.size() - s1.size(),'0'); 
        s1 = zeros + s1;
    }
    //mismo tamano.
    bool s1mayor = false;
    bool s2mayor = false;
    string res1, res2;
    fr(0,s1.size()){
        if (s1mayor || s2mayor){
            if (s1mayor){
                if (s1[i] -'0'> s2[i]-'0'){
                    res1.pb(s2[i]);
                    res2.pb(s1[i]);
                } else {
                    res1.pb(s1[i]);
                    res2.pb(s2[i]);
                }
            } else { //s2 tengo que poner lo mas chico
                if (s1[i] -'0'> s2[i]-'0'){
                    res1.pb(s1[i]);
                    res2.pb(s2[i]);
                } else {
                    res1.pb(s2[i]);
                    res2.pb(s1[i]);
                }
            }
        } else {
            if (s1[i] != s2[i]){
                if (s1[i]-'0' > s2[i]-'0'){
                    s1mayor = true;
                } else {
                    s2mayor = true;
                }
            }
            if (s1[i] != '0'){
                res1.pb(s1[i]);
            }
            if (s2[i] != '0'){
                res2.pb(s2[i]);
            }
        }
    }
    cout << res1 << "\n";
    cout << res2 << "\n";
    //acordarse de recortar los 0 del principio.
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