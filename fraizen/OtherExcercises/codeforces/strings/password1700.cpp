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
int z[MAXN];

void z_function(string s){
    int n = s.size();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}  

void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    z_function(s);
    // fr(0,n){
    //     cout << z[i];
    // }
    set<pair<int,int>> sufijos;
    set<pair<int,int>> medios;
    fr(0,n){
        if (z[i] + i == n){
            sufijos.insert(mp(z[i],i));
        }
        if (z[i] != 0){
            medios.insert(mp(z[i],i));
        }
    }
    if (medios.size() <= 1){
        cout("Just a legend");
        return 0;
    }
    pair<int,int> maximo;
    pair<int,int> maximo2;
    for (auto it = sufijos.rbegin(); it != sufijos.rend(); it++){
        maximo = *medios.rbegin();
        if (maximo.second == it->second){
            auto it2 = medios.rbegin();
            it2++;
            maximo = *it2;
        }
        if (maximo.first >= it->first){
            fr(it->second, it->second + it->first){
                cout << s[i];
            }
            cout(' ')
            return 0;
        }
    }
    cout("Just a legend");
}