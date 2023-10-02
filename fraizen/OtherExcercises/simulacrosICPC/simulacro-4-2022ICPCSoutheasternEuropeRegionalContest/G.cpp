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
ll pos [MAXN];
ll rad [MAXN];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    ll sumaDoble = 0;
    map<ll,ll> m;
    fr(0,n){
        ll a;
        cin >> a;
        pos[i] = a;  
    }
    fr(0,n){
        ll a;
        cin >> a;
        rad[i] = a;
        sumaDoble += a * 2;  
        m[a]++; 
    }
    ll dif [n];
    fr(0,n-1){
        dif[i] = pos[i+1] - pos[i];
        // cout << dif[i] << ' ';
    }
    ll sumaDif = 0;
    fr(0,n-1){
        sumaDif += dif[i];
    }
    // voy fijando
    fr(0,n){
        //fijo a i
        ll quiero = sumaDif - rad[i]; 
        ll ult = sumaDoble - rad[i] * 2 - quiero;
        // cout(ult);
        map<ll,ll> m2;
        m2[rad[i]]++;
        m2[ult]++;
        bool rompo = false;
        if (m2[ult] > m[ult]){
            continue;
        }
        ll tengo = rad[i];
        fr(0,n-1){
            int diff = dif[i] - tengo;
            if (i == n-2 && diff != ult){
                rompo = true;
                break;
            }
            if (diff <= 0){
                rompo = true;
                break;
            }
            if (i == n-2){
            } else {
                m2[diff]++;
                if (m2[diff] > m[diff]){
                    rompo = true;
                    break;
                }
            }
            tengo = diff;
        }
        if (! rompo){ //secuencia valida, imprimo
            tengo = rad[i];
            cout << tengo << ' ';
            fr(0,n-1){
                int diff = dif[i] - tengo;
                tengo = diff;
                cout << diff << ' ';
            }
            break;
        }
    }
}