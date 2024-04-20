#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

const int MAXN = 11;
char m1[MAXN][MAXN], m2[MAXN][MAXN], m3[MAXN][MAXN];

bool rot90(int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(m1[i][j], m1[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(m1[i][j], m1[i][n-j-1]);
        }
    }
    fr(0,n){
        rep(j,0,n){
            if (m2[i][j] != m1[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool rot902(int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(m3[i][j], m3[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(m3[i][j], m3[i][n-j-1]);
        }
    }
    fr(0,n){
        rep(j,0,n){
            if (m2[i][j] != m3[i][j]){
                return false;
            }
        }
    }
    return true;
}



// Copiar obligatoriamente 0
void solve() {
    int n;
    int caso = 0;
    while(cin >> n){
        caso++;
        bool iguales = true;
        fr(0,n){
            string s1, s2;
            cin >> s1 >> s2;
            if (s1 != s2){
                iguales = false;
            }
            rep(j,0,n){
                m1[i][j] = s1[j];
                m2[i][j] = s2[j];
            }
        }
        fr(0,n){
            rep(j,0,n){
                m3[i][j] = m1[i][j];
            }
        }  
        if (iguales){
            cout << "Pattern " << caso << " was preserved.\n"; continue;
        }
        if (rot90(n)){
            cout << "Pattern " << caso << " was rotated 90 degrees.\n"; continue;
        }
        if (rot90(n)){
            cout << "Pattern " << caso << " was rotated 180 degrees.\n"; continue;
        }
        if (rot90(n)){
            cout << "Pattern " << caso << " was rotated 270 degrees.\n"; continue;
        }
        //tengo que meter el vertical aca en la m3.
        fr(0,n/2){
            swap(m3[i], m3[n-1-i]);
        }
        bool vert = true;
        fr(0,n){
            rep(j,0,n){
                if (m3[i][j] != m2[i][j]){
                    vert = false;
                }
            }
        }
        if (vert){
            cout << "Pattern " << caso << " was reflected vertically.\n"; continue;
        }
        // fr(0,n){
        //     rep(j,0,n){
        //         cout << m3[i][j];
        //     }
        //     cout << endl;
        // }  

        if (rot902(n)){
            cout << "Pattern " << caso << " was reflected vertically and rotated 90 degrees.\n"; continue;
        }
        if (rot902(n)){
            cout << "Pattern " << caso << " was reflected vertically and rotated 180 degrees.\n"; continue;
        }
        if (rot902(n)){
            cout << "Pattern " << caso << " was reflected vertically and rotated 270 degrees.\n"; continue;
        }
        cout << "Pattern " << caso << " was improperly transformed.\n";


        // fr(0,n){
        //     rep(j,0,n){
        //         cout << m1[i][j] << ' ';
        //     }
        //     cout << endl;
        // }    
        // cout <<endl;
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