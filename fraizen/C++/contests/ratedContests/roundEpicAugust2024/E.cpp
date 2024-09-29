#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
ll n;
void solve() {
    cin >> n;
    vector<tuple<ll,ll,ll> > t;
    fr(0,n){
        tuple<ll,ll,ll> tuple;
        ll a,b; cin >> a >> b;
        tuple = {a,b,i};
        t.pb(tuple);
    }
    ll mini = 0;
    bool usado[n]; fr(0,n) usado[i] = false;
    ll iter = 0;
    // fr(0,n){
    //     cout << usado[i] << ' ';
    // }
    // cout << endl;
    ll contador = 0;
    while(true){
        if (iter == 6){
            break;
        }
        iter++;
        //agarro el primero del array
        cout << "TUPLAS: " << endl;
        fr(0,t.size()){
            cout << "{" << get<0>(t[i]) <<","<< get<1>(t[i]) <<","<< get<2>(t[i]) << "}\n";
        }

        ll cant = get<0>(t[0]);
        ll num = get<1>(t[0]);
        ll i = get<2>(t[0]);
        map<ll,ll> m;
        m[num] = cant;
        vector<ll> a;
        a.pb(-1);
        ll actual = cant;
        ll cur = cant;
        contador += cant;
        fr(1,t.size()){
            // cout << "cur = " << cur << endl;
            if (m[get<1>(t[i])] > 0){
                //ya tiene uno anterior, entonces hay que ver la diferencia para pushear al array
                ll dif = cur - m[get<1>(t[i])];
                a.pb(dif);
                //ahora el mapa lo actualizo con el ultimo valor
                m[get<1>(t[i])] = cur + get<0>(t[i]);
                //  cout << "pongo m[" <<get<1>(t[i]) <<"] = " << cur + get<0>(t[i]) << endl;
            } else {
                //no hay nada antes
                a.pb(-1);
                //pongo el de ahora
                m[get<1>(t[i])] = cur + get<0>(t[i]);
                // cout << "pongo m[" <<get<1>(t[i]) <<"] = " << cur + get<0>(t[i]) << endl;
            }
            //actualizo el current
            cur += get<0>(t[i]);
        }
        // fr(1,t.size()){
        //     if (m[get<1>(t[i])] > 0){
        //         // tengo que ver cuantos tengo atras digamos: 
        //         //toy parado en actual? 
        //         ll dif = cur+2 - m[get<1>(t[i])];
        //         m[get<1>(t[i])] = cur + get<0>(t[i]);
        //         // actual += m[get<1>(t[i])];
        //         a.pb(dif);
        //     } else {
        //         m[get<0>(t[i])] = cur;
        //         a.pb(-1);
        //     }
        //     cur+=get<0>(t[i]);
        // }
        cout << "ARRAY QUEDO: " << endl;
        fr(0,a.size()){
            cout << a[i] << " ";
        }
        cout << endl;
        //pa mi tengo que voler a armar el vector t
        vector<tuple<ll,ll,ll>> t2;
        fr(0,t.size()){
            ll eliminar;
            eliminar = get<0>(t[0]);
            if (a[i]!=-1){
                eliminar = min(eliminar, a[i]);
            }
            // cout << "eliminar = " << eliminar << endl;
            if (get<0>(t[i]) <= eliminar){
                // cout << "tengo que eliminar el " << i << endl;
                //este se elimina digamos
                usado[get<2>(t[i])] = true;
                // cout << "LO MARCO COMO USADO AL " << get<2>(t[i]) << endl;
                // cout << "USADOS " << endl;
                // rep(j,0,n){
                //     cout << usado[j] << " ";
                // }
                // cout << endl;
                ll j = get<2>(t[i]);
                if (j == mini){
                    while(usado[j]){
                        cout << contador << " ";
                        j++;
                    }
                    mini = j;
                }
                // cout << "primero sin usar es mini " << mini << endl;
                if (j == n){
                    exit(0);
                }
            } else { //queda, hay que borrarle los que podamos y eso lo metemos en t2.
                //cantidad de veces es disminuida cantidad digamos
                t2.pb({get<0>(t[i])-eliminar, get<1>(t[i]), get<2>(t[i])});
                // cout << "el i lo dejo con "<< get<0>(t[i])-eliminar << endl;
            }
        }
        // cout << "TUPLAS T2: " << endl;
        // fr(0,t2.size()){
        //     cout << "{" << get<0>(t2[i]) <<","<< get<1>(t2[i]) <<","<< get<2>(t2[i]) << "}\n";
        // }

        //aca tendria que pasar el t2 al t y limpiar el t;
        t = t2;
        t2.clear();
        m.clear();
    }
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}