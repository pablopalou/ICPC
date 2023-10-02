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
#define M_PI 3.14159265358979323846

void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b , c;
    cin >> a >> b >> c;
    ld res = (2 * a * M_PI) / (b * c);
    ll entera = floor(res);
    res -= entera;
    if (res > 0.5){
        res = 1-res;
    }

    tuple<int,int,int> ans = {250,500,1000};
    double best = res;
    long double cur;
    fr(2,250){
        for(int j = i*2; j <= 500; j+=i){
            for(int k = 2*j; k <=1000; k+=j){
                cur = 1.0;
                cur = cur / i;
                cur -= (1.0 / j);
                cur += (1.0 / k);
                if ( abs(cur - res) < best){
                    best = abs(cur - res);
                    ans = {i,j,k};
                } 
            }
        }
    }
    int i,j,k;
    tie(i,j,k) = ans;
    cout << i << ' ' << j <<  ' ' << k << "\n";
}