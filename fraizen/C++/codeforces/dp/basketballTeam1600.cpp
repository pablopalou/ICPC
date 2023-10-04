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
#define MAXN 1005
int teams[MAXN];

void solve(int n, int m, int h, int total) {
    if (total < n){ // no llego a la cant suficiente de jugadores
        cout(-1);
        return;
    }
    if (teams[h] == 0){ //no tengo jugadores en el equipo
        cout(0);
        return;
    }
    if ((n-1) > total - (teams[h] + 1)){ // si o si tengo que poner los del equipo h porque sino no llego 
        cout(1);
        return;
    }

    //caso normal, sacamos probabilidades
    ld res = 1.0;
    ld productoria = 1.0;
    int cantDistintoH = total - (teams[h] + 1);
    total--;
    fr(1,n){ //necesito n-1 jugadores, xq hay uno que ya esta
        productoria *= ((ld)cantDistintoH / (ld)total);
        total--;
        cantDistintoH--;
    }
    res = res - productoria;
    cout << fixed << setprecision(6) << res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n, m, h;
    cin >> n >> m >> h;
    int total = 0;
    fr(1,m+1){
        int a;
        cin >> a;
        total += a;
        teams[i] = a;
        if (i == h){
            teams[i] -= 1;
        }
    }
    
    solve(n,m,h,total);
}