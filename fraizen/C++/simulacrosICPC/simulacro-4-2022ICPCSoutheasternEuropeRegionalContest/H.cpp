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
#define MAXN 502
int a[MAXN];

int main() {
    vector<int> v1,v2,v3;
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; 
    cin >> n;
    fr(0,n){
        int b;
        cin >> b;
        v1.pb(b);
    }
    vector<int> movs; // 1 significa 1 2, 2 significa 1 3, 3 significa 2 3, 4 significa, 5 significa, 6 significa 3 a 1.
    while (! v1.empty()){
        // cout << "Paso " << endl;
        // fr(0,v1.size()){
        //     cout << v1[i] << ' ';
        // }
        // cout(' ');
        // fr(0,v2.size()){
        //     cout << v2[i] << ' ';
        // }
        // cout(' ');
        // fr(0,v3.size()){
        //     cout << v3[i] << ' ';
        // }
        // cout(' ');
        if (! v3.empty()){
            if (v1.back() < v3.back()){ //pongo 1 a 3
                int meter = v1.back();
                v3.pb(meter);
                v1.pop_back();
                movs.pb(2);
            } else {
                // paso del 1 al 2
                v2.pb(v1.back());
                v1.pop_back();
                movs.pb(1);
                int cur = v2.back();
                int ult = v3.back();
                //muevo del 3 al 1
                int cant = 0;
                // cout(ult);
                while (ult < cur){
                    v1.pb(v3.back());
                    v3.pop_back();
                    movs.pb(6);
                    cant++;
                    if (v3.empty()){
                        break;
                    }
                    ult = v3.back();
                }
                //muevo del 2 al 3
                v3.pb(v2.back());
                v2.pop_back();
                movs.pb(3);
                // cout(cant);
                //muevo del 1 al 3
                while(cant--){
                    v3.pb(v1.back());
                    v1.pop_back();
                    movs.pb(2);
                }
            }
        } else {
            //muevo del 1 al 3
            v3.pb(v1.back());
            v1.pop_back();
            movs.pb(2);
        }
    }
    cout(movs.size());
    fr(0,movs.size()){
        if (movs[i] == 1){
            cout << "1 2" << "\n";
        } else if (movs[i] == 2){
            cout << "1 3" << "\n";
        } else if (movs[i] == 3){
            cout << "2 3" << "\n";
        } else if (movs[i] == 4){
            // cout << "2 3" << "\n";
        } else if (movs[i] == 5){
            // cout << "2 3" << "\n";
        } else {
            cout << "3 1" << "\n";
        }      
    }

}