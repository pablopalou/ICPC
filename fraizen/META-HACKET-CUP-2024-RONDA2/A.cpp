#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

vector<ll> peaks;

void generate_peaks() {
    rep(k,0,9){
        rep(d1, 1, 10){
            ll number = 0;
            fr(0,k+1){
                number = number * 10 + (d1 + i);
            }
            for(ll i = k - 1; i >= 0; i--) {
                number = number * 10 + (d1 + i);
            }
            peaks.push_back(number);
        }
    }
    sort(peaks.begin(), peaks.end());
}



void solve() {
    ll A, B, M;
    cin >> A >> B >> M;
    auto lower = lower_bound(peaks.begin(), peaks.end(), A);
    auto upper = upper_bound(peaks.begin(), peaks.end(), B);
    ll count = 0;
    for (auto it = lower; it != upper; ++it) {
        if ((*it) % M == 0 && (*it <= B)) {
            count++;
        }
    }

    cout << count << endl;
}

// Para compilar: g++ -O2 -Wl,-stack_size,0x20000000 -o A A.cpp
// Para correr: ./A
// Acordate de usar LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    generate_peaks();
    //DESCOMENTAR ESTO PREVIO A BAJAR EL ARCHIVO
    freopen("cottontail_climb_part_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cases = 1;
    cin >> cases;
    rep(i,1,cases+1){
        cout << "Case #" << i << ": "; 
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}