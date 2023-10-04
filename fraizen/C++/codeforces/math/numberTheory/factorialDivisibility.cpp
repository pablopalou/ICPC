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
#define MAXN 500008
int cant[MAXN];

void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    memset(cant, 0, sizeof(cant));
    fr(0,n){
        int a;
        cin >> a;
        cant[a]++;
    }
    
    fr(0,k){
        while (cant[i] > i){
            cant[i] -= i+1;
            cant[i+1]++;
        }
    }
    fr(0,k){
        if (cant[i] != 0){
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
}