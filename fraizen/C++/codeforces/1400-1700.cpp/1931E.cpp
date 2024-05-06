#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

int digits(int n){
    int d=0;
    while(n){
        d++;
        n/=10;
    }
    return d;
}

int endZeros(int n){
    int d=0;
    while(n && (n%10 == 0)){
        d++;
        n/=10;
    }
    return d;
}


// Copiar obligatoriamente 0
void solve() {
    int n,m; cin >> n >> m;
    int cantDigits = 0;
    vector<int> v;
    fr(0,n){
        int num; cin >> num;
        cantDigits += digits(num);
        v.pb(endZeros(num));
    }
    sort(v.begin(), v.end(), greater<int>());
    fr(0,v.size()){
        if (i%2 == 0){
            cantDigits -= v[i];
        }   
    }
    if (cantDigits > m){
        cout << "Sasha\n";
    } else {
        cout << "Anna\n";
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