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
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008
bool longitudes[720];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(longitudes, false, sizeof(longitudes));
    ll n;
    cin >> n;
    ll y1, x1;
    cin >> y1 >> x1;
    ll iniY, iniX;
    x1+=180;
    iniY = y1;
    iniX = x1;
    // cout(x1);
    // cout(x2);

    fr(1,n+1){
        ll y2,x2;
        if (i == n){
            y2 = iniY;
            x2 = iniX;
        } else {
            cin >> y2 >> x2;
            x2+=180;
        }
        //hago los calculos
        if (abs(x2-x1) == 180){
            cout << "yes";
            return 0;
        }
        if (x1==360){
            x1 = 0;
        }
        if (x2 == 360){
            x2 = 0;
        }
        // cout(x1);
        // cout(x2);
        // cout << "x1: " << x1 << ", x2: " << x2 << endl;
        if (x1 < x2){
            if (abs(x2-x1) > 180){
                //pongo todo en true desde el x1 pa atras y del x2 pa adelante
                for (ll i = x1 * 2; i >= 0; i--){
                    // cout << "Pongo longitudes[" << i << "] = true" << endl;
                    longitudes[i] = true;
                }
                for (ll i = x2 * 2; i <= 719; i++){
                    //  cout << "Pongo longitudes[" << i << "] = true" << endl;
                    longitudes[i] = true;
                }
            } else {
                for (ll i = x1 * 2; i <= x2*2; i++){
                    //  cout << "Pongo longitudes[" << i << "] = true" << endl;
                    longitudes[i] = true;
                }
            }
        } else if (x1 > x2){
            // cout << "x2 es mas grande que x1";
            if (abs(x2-x1) > 180){
                // cout("Deberia entrar aca");
                //pongo todo en true desde el x2 pa atras y del x1 pa adelante
                for (ll i = x2 * 2; i >= 0; i--){
                    // cout << "Pongo longitudes[" << i << "] = true" << endl;
                    longitudes[i] = true;
                }
                for (ll i = x1 * 2; i <= 719; i++){
                    //  cout << "Pongo longitudes[" << i << "] = true" << endl;
                    longitudes[i] = true;
                }
            } else {
                // pongo todo en true entre x2 y x1.
                for (ll i = x2 * 2; i <= x1*2; i++){
                    //  cout << "Pongo longitudes[" << i << "] = true" << endl;
                    longitudes[i] = true;
                }
            }
        }

        // pongo el anterior
        x1 = x2;
        y1 = y2;
    }

    // fr(0,720){
    //     cout << "Longitudes de " << i << "=" << longitudes[i] << endl;
    // }
    
    fr(0,720){
        if ( ! longitudes[i]){
            d res = double(double(i)/2) - 180.0;
            cout << "no ";
            cout << fixed << setprecision(1) << res;
            return 0;
        }
    }
    cout << "yes";
}