#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
 
 //ESTE DA AC
int n;
string ask(int l, int r){
    if (l >= 0 && l < n && r >= 0 && r < n){
        cout << l+1 << ' ' << r+1 << endl;
        string res; cin >> res;
        return res;
    } else {
        return "";
    }
}

void solve() {
    int k; cin >> n >> k;
    fr(0,n){
        rep(j,0,n){
            if ((i+j)%5 == 0){
                string ans = ask(i, j);
                if (ans != "miss"){
                    if (ans == "sunk"){
                        k--;
                        if (k == 0) return;
                    }
                    //tengo que fijarme todos los otros...
                    rep(fraizen,1,5){
                        string ans1 = ask(i, j + fraizen);
                        string ans2 = ask(i, j - fraizen);
                        string ans3 = ask(i + fraizen, j);
                        string ans4 = ask(i - fraizen, j);
                        if (ans1 == "sink"){
                            k--;
                        }
                        if (ans2 == "sink"){
                            k--;
                        }
                        if (ans3 == "sink"){
                            k--;
                        }
                        if (ans4 == "sink"){
                            k--;
                        }
                        if (k == 0) return;
                    }
                }
            }
        }
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}