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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<pair<char,char>> v;
    vector<pair<char,char>> res;

    //leo las 52 cartas y las guardo en el vector v.
    fr(0,52){
        string s;
        cin >> s;
        pair<char, char> p = mp(s[0], s[1]);
        v.pb(p);
    }

    fr(0,52){
        if (res.size() < 2){ //si tengo 0 o 1 elementos, simplemente pusheo
            res.pb(v[i]);
            continue;
        } else { //ya tengo que chequear los anteriores...
            res.pb(v[i]);
            if (res[res.size()].first == res[res.size()-3].first){ //saco los 4 y chau
                fr(0,4){
                    res.pop_back();
                }
            } else if (res[res.size()].second == res[res.size()-3].second){ // aca hay que tener cuidado, solo sacar 2 extremos y nos fijamos para adentro
                res.pop_back();
                pair<char, char> ant = res.back();
                res.pop_back();
                pair<char, char> ant2 = res.back();
                res.pop_back();
                res.pop_back();
                res.pb(ant2);
                res.pb(ant);
                if (res.size() <= 3){
                    continue;
                }
                int cant;
                if (res.size() == 4){
                    cant = 1;
                } else {
                    cant = 3;
                }
                while (cant > 0){
                    //acutalizar cant en cada caso!
                    if (cant == 3){

                    } else if (cant == 1){ //solo quequear el ultimo
                        if (res[res.size()].first == res[res.size() - 3].first){
                            fr(0,4){
                                res.pop_back();
                            }
                            cant = 0;
                            break;
                        } else if (res[res.size()].second == res[res.size() - 3].second){
                            res.pop_back();
                            ant = res.back();
                            res.pop_back();
                            ant2 = res.back();
                            res.pop_back();
                            res.pop_back();
                            res.pb(ant2);
                            res.pb(ant);
                            if (res.size() <= 3){
                                break;
                            }
                            int cant;
                            if (res.size() == 4){
                                cant = 1;
                            } else {
                                cant = 3;
                            }
                        }
                    } else if (cant == 2) { // solo chequear el penultimo
                        if (res[res.size()-1].first == res[res.size() - 4].first){
                            ant = res.back();
                            fr(0,5){
                                res.pop_back();
                            }
                            res.pb(ant);
                            cant = 1;
                        } else if (res[res.size()-1].second == res[res.size() - 4].second){
                            pair<char,char> ultimo = res.back();
                            res.pop_back();
                            res.pop_back();
                            ant = res.back();
                            res.pop_back();
                            ant2 = res.back();
                            res.pop_back();
                            res.pop_back();
                            res.pb(ant2);
                            res.pb(ant);
                            res.pb(ultimo);
                            if (res.size() <= 3){
                                break;
                            }
                            int cant;
                            if (res.size() == 4){
                                cant = 1;
                            } else {
                                cant = 3;
                            }
                        }
                    }
                }
            }
        }
    }

    //imprimo lo que quedo en el vector res
    cout << res.size() << ' ';
    fr(0,res.size()){
        cout << res[i].first << res[i].second << ' '; 
    }
}