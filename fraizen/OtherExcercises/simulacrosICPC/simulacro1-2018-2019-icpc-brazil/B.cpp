#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
int grundy[102][102];

int mex(vector<int> v)
{
    set<int> s;
    for(int i=0;i<v.size();i++)
    {
        s.insert(v[i]);
    }
    for(int i=0;i<1000;i++)
    {
        if(s.count(i)==0) return i;
    }
    return 1000;
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n;
    cin >> n;
    vector<pii> pos(n);
    fr(0,n){
        int a,b;
        cin >> a >> b;
        pos[i] =(mp(a,b));
    }

    //inicializo toda la matriz
    fr(0,102){
        rep(j,0,102){
            grundy[i][j] = 0;
        }
    }
    //pongo valores iniciales
    fr(1,102){
        grundy[i][i] = 1000;
        grundy[i][0] = 1000;
        grundy[0][i] = 1000;
    }
    //calculo matriz de grundy
    fr(1,102){
        rep(j,1,102){
            if (grundy[i][j] == 1000){
                continue; 
            }
            //calculo mex (agarro todos los anteriores de arriba y la izquierda y los de la diagonal)
            vector<int> v;
            rep(h,1,i){
                v.pb(grundy[h][j]);
            }
            rep(h,1,j){
                v.pb(grundy[i][h]);
            }
            rep(h,1, min(i,j)){
                v.pb(grundy[i-h][j-h]);
            }
            grundy[i][j] = mex(v);
        }
    }

    //hago el xor de las posiciones
    int res = 0;
    fr(0,n){
        res ^= grundy[pos[i].first][pos[i].second];
    }

    // fr(0,102){
    //     rep(j,0,102){
    //         cout << grundy[i][j] << ' ';
    //     }
    //     cout(' ');
    // }

    //imprimo resultado
    cout << ((res == 0) ? ("N") : ("Y"));
}