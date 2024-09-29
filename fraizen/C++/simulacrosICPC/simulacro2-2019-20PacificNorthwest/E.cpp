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
#define mod 11092019
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008
map<int, int> m;

ll modular_expo(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            res = ((res % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
        n = n / 2;
    }
    return res % mod;
}

// NO FUNCIONA.

void solve(string s) {
    int left, right;
    left = 0;
    right = 1;
    int cantEliminar = 0;
    int n = s.size();
    m[s[left] - 'a'] = 1;
    int ultI = -1;
    while (right < n){
        cout(left);
        cout(right);

        for(auto it = m.cbegin(); it != m.cend(); ++it)
        {
            cout << it->first << " " << it->second << "\n";
        }
        // if (right == 2){
        //     cout(m.count(s[right] - 'a'));
        //     return;
        // }
        if (m.count(s[right] - 'a') > 0){
            //eliminar del mapa todas las anteriores a la pos del mapa
            int nextLeft = m[s[right] - 'a'];
            cout << "Next left " << nextLeft << endl;
            while (left < nextLeft -1){
                m.erase(s[left] - 'a');
                left++;
            }
            cout("Fraizen");
            for(auto it = m.cbegin(); it != m.cend(); ++it)
            {
                cout << it->first << " " << it->second << "\n";
            }
            // sumar a cantEliminar
            // cout("se viene");
            // cout((nextLeft-ultI ));
            // cout((n - right));
            // cout << "cant a eliminar ahora" << ((nextLeft-1-ultI) * (n - right) % mod) % mod << endl;
            cout << "aaaa" << modular_expo(2, (((nextLeft-1-ultI)- 1) + ((n - right)-1) % mod)) + 1 << endl;
            cantEliminar = (cantEliminar +  modular_expo(2, (((nextLeft-1-ultI)- 1) + ((n - right)-1) % mod)) + 1) % mod;
            cout << "cant eli: " << cantEliminar << endl;
            // cantEliminar = (cantEliminar + (nextLeft-1-ultI) * (n - right) % mod) % mod; //fijarse
            // cout << "Cant Eliminar " << cantEliminar << "\n";
            // actualizar la i
            ultI = nextLeft-1;
            // eliminar del mapa y actualizar posicion.
            int medio = right - m[s[nextLeft-1] - 'a'] -1;
            cout << "medio" << medio << endl;
            cantEliminar =( cantEliminar % mod + modular_expo(2, medio)) % mod;
            m.erase(nextLeft-1);
            m[s[nextLeft-1] - 'a'] = right + 1;
            //actualizamos left y right; 
            left++;
            right++;
        } else { //listo
            //actualizar el mapa
            m[s[right] - 'a'] = right + 1;
            right += 1;
        }
    }
    // cout("Fraizen2");
    //         for(auto it = m.cbegin(); it != m.cend(); ++it)
    //         {
    //             cout << it->first << " " << it->second << "\n";
    //         }
    // cout('a');
    
    //hacer 2 a la n shifteando con mod... (usar mod expo) quizas.
    ll potencia = modular_expo(2,n);
    cout(potencia);
    cout(cantEliminar);
    // restar cantidad
    ll total = ((potencia % mod - cantEliminar % mod) + mod) % mod;
    cout(total);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    string s;
    cin >> s;
    
    solve(s);
}