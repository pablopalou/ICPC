#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define EPS 1e-18

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    ll a,b,c,d; cin >> a >> b >> c >> d;
    string sa = to_string(a); string sb = to_string(b); string sc = to_string(c); string sd = to_string(d);
    ll g = gcd(c,d);
    c/=g; d/=g;
    for(int mask = 0; mask < (1<<18); mask++){
        ll num = 0;
        multiset<ll> tachar;
        fr(0,18){
            if ((mask & (1<<i)) != 0){
                if (i < sa.size()){
                    tachar.insert(sa[i]-'0');
                }
            } else {
                if (i < sa.size()){
                    num *= 10;
                    num += (sa[i] - '0');
                }
            }
        }
        if (num == 0){
            continue;
        }
        ll original = num;
        //aca si ya tengo el numero y tambien lo que tengo que tachar abajo. El numero tiene que dividir si o si a c, para lograr tener un entero
        if (num % c != 0) continue;
        num/=c;
        __int128 nuevoB128 = (__int128)d * num; //OJO CON ESTO, POSIBLE OVERFLOW //del B tenemos que llegar la nuevo B, eliminando los que tenemos en tachar
        if (nuevoB128 > b || nuevoB128 >= __LONG_LONG_MAX__){
            continue;
        }
        ll nuevoB = nuevoB128;
        string snuevoB = to_string(nuevoB);
        int p1 = 0;
        int p2 = 0;
        bool puedo = true;
        while(p1 < snuevoB.size() && p2 < sb.size()){
            if (snuevoB[p1] == sb[p2]){
                p1++;p2++;
            } else {
                if (tachar.find(sb[p2] - '0') ==  tachar.end()){
                    puedo = false;
                    break;
                } else {
                    tachar.erase(tachar.find(sb[p2] - '0'));
                    p2++;
                }
            }
        }
        while(p2<sb.size()){
            if (tachar.find(sb[p2] - '0') == tachar.end()){
                puedo = false;
                break;
            } else {
                tachar.erase(tachar.find(sb[p2] - '0'));
                p2++;
            }
        }
        if (! puedo) continue;
        if (tachar.empty() && p1 == snuevoB.size() && p2 == sb.size()){
            cout << "possible\n";
            cout << original << ' ' << nuevoB << '\n';
            return;
        }
    }
    cout << "impossible\n";
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}