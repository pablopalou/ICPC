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
#define MAXN 1000008
#define p 256

vi precompute_hashes(const string&s){
    vi hashes(s.size()+1,0);
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++){
        hash = (hash*p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}

ll get_hash(const vi& hashes, ll l, ll r, const vi& potencias){
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod) + mod) %mod);
}

// no anda en un caso medio borde que deberia arreglar pero me da paja. el resto funciona
void solve(string s, string t) {
    int n = s.size();
    int m = t.size();
    if (n < m){
        cout(s);
        return;
    }
    int sufijo = 0;
    int cant1tPostSufijo = 0;
    if (m > 1){
        vi hashes = precompute_hashes(t);
        vi potencias(m);
        potencias[0] = 1;
        for (ll i = 1; i < m; i++) {
            potencias[i] = (potencias[i-1] * p) % mod;
        }

        // fr(0,hashes.size()){
        //     cout << hashes[i] << ' ';
        // }
        // cout(' ');
        int i = 1;
        sufijo = 0;
        // cout << "get hashes solos: " << endl;
        // fr(0,m+1){
        //     cout << get_hash(hashes, i, i, potencias) << ' ';
        // }
        // cout('a');
        // cout(get_hash(hashes, 1, i, potencias));
        // cout(get_hash(hashes, m + 1 - i, m, potencias));
        while (get_hash(hashes, 1, i, potencias) == get_hash(hashes, m + 1 - i, m, potencias)){
            sufijo++;
            i++;
        }
        // cout<< "Sufijo " << sufijo << endl;
        cant1tPostSufijo = 0;
        fr(sufijo,m){
            if(t[i] == '1'){
                cant1tPostSufijo++;
            }
        }
    }
    int cant1s = 0;
    int cant1t = 0;
    fr(0,n){
        if(s[i] == '1'){
            cant1s++;
        }
    }
    fr(0,m){
        if(t[i] == '1'){
            cant1t++;
        }
    }
    // cout(cant1tPostSufijo);
    // cout(cant1s);
    // cout(cant1t);
    vector<char> res(n);
    if (cant1t == 0 && cant1s > 0){
        int j = 0;
        int aux = cant1s;
        while(cant1s > 0){
            res[j] = '1';
            j+=1;
            cant1s--;
        }
        fr(aux,n){
            res[i] = '0';
        }
        fr(0,n){
            cout << res[i];
        }
        return;
    }

    int largo = 0;
    int cant1actual = 0;
    if (cant1t + cant1actual <= cant1s && largo + m <= n){
        fr(0,m){
            res[i] = t[i];
        }
        largo = m;
        cant1actual += cant1t;
    } else {
        cout(s);
        return;
    }

    if (m==1){
        cout(s);
        return;
    } else {
        int largoSufijo = m - sufijo;
        if (largoSufijo == 0){
            while(cant1actual < cant1s){
                res[largo] = '1';
                largo++;
                cant1actual ++;
            }
            while(largo <= n-1){
                res[largo] = '0';
                largo++;
            }
        } else {
            while(cant1tPostSufijo + cant1actual <= cant1s && largo + largoSufijo <= n){
                fr(sufijo, m){
                    res[largo] = t[i];
                    largo++;
                }
                cant1actual+=cant1tPostSufijo;
            }
            
            // puede faltar unos
            while(cant1actual < cant1s){
                res[largo] = '1';
                largo++;
                cant1actual ++;
            }
            while(largo <= n-1){
                res[largo] = '0';
                largo++;
            }
        }

    }
    fr(0,n){
        cout << res[i];
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    
    solve(s,t);
}