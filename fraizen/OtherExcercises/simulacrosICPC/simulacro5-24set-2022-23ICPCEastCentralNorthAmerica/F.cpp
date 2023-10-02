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
#define M_PI       3.14159265358979323846

void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b , c;
    cin >> a >> b >> c;
    ld res = (2.0 * a * M_PI) / (b * c);
    ll entera = floor(res);
    res -= entera;
    if (res > 0.5){
        res = 1-res;
    }

    tuple<int,int,int> ans = {250,500,1000};
    double best = res;
    long double cur;
    fr(2,251){
        for(int j = 2; j*i <= 500; j++){
            for(int k = 2; i*k*j <=1000; k++){
                // cur = 1.0;
                // cur = cur / i;
                // cur -= (1.0 / j);
                // cur += (1.0 / k);
                // k y j ahora son multiplicadores
                cur = static_cast<long double>(1.0 + k * (j - 1)) / static_cast<long double>(i * j * k); 
                // cout(cur);
                // cout(fabs((j - 1) * k + 1.0 / (i * j * k) - res));
                // cout(fabs(cur-res));
                // if (i==250 && j == 2 && k == 2){
                //     prDouble(cur);
                // }
                if ( fabs(cur - res) < best){
                    // cout("NADIE");
                    best = fabs(cur - res);
                    ans = {i,j*i,k*j*i};
                } 
            }
        }
    }
    int i,j,k;
    tie(i,j,k) = ans;
    cout << i << ' ' << j <<  ' ' << k << "\n";
}