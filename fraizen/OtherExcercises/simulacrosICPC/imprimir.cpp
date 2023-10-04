SIMULACROS

SIMULACRO 1 ICPC 2018-2019 BRAZIL

GAMES 

int grundy[102][102];

int mex(vector<int> v)
{
    set<int> s;
    for(int i=0;i<v.size();i++)
    {
        s.insert(v[i]);
    }
    for(int i=0;i<1000;i++)
    {
        if(s.count(i)==0) return i;
    }
    return 1000;
}


int main() {
    // Parsing
    int n;
    cin >> n;
    vector<pii> pos(n);
    fr(0,n){
        int a,b;
        cin >> a >> b;
        pos[i] =(mp(a,b));
    }

    //inicializo toda la matriz
    fr(0,102){
        rep(j,0,102){
            grundy[i][j] = 0;
        }
    }
    //pongo valores iniciales
    fr(1,102){
        grundy[i][i] = 1000;
        grundy[i][0] = 1000;
        grundy[0][i] = 1000;
    }
    //calculo matriz de grundy
    fr(1,102){
        rep(j,1,102){
            if (grundy[i][j] == 1000){
                continue; 
            }
            //calculo mex (agarro todos los anteriores de arriba y la izquierda y los de la diagonal)
            vector<int> v;
            rep(h,1,i){
                v.pb(grundy[h][j]);
            }
            rep(h,1,j){
                v.pb(grundy[i][h]);
            }
            rep(h,1, min(i,j)){
                v.pb(grundy[i-h][j-h]);
            }
            grundy[i][j] = mex(v);
        }
    }

    //hago el xor de las posiciones
    int res = 0;
    fr(0,n){
        res ^= grundy[pos[i].first][pos[i].second];
    }

    //imprimo resultado
    cout << ((res == 0) ? ("N") : ("Y"));
}

STATISTICS TREE

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;

int main()
{
    long long h, v;
    cin >> h >> v >> h >> v;
    vector<pair<int, int>> horizontais(h), verticais(v);
    for(auto &it : horizontais)
        cin >> it.first >> it.second;
    sort(horizontais.begin(), horizontais.end());

    for(auto &it : verticais)
        cin >> it.first >> it.second;
    sort(verticais.begin(), verticais.end());

    long long r = (h + 1) * (v + 1);
    statisticsTree th, tv;
    for(auto &it : horizontais)
    {
        r += th.order_of_key(it.second);
        th.insert(it.second);
    }
    for(auto &it : verticais)
    {
        r += tv.order_of_key(it.second);
        tv.insert(it.second);
    }
    cout << r << endl;
}

SIMULACRO 2 Y 5

DP + math

map<char, ll> cant;
char CARTAS[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
ll cant_cartas = 13;
ll dp[102][27];

void solve(ll n, vector<char> cartas) {
    fr(0, n) {
        cant[cartas[i]] += 1;
    }
    // Cuento pares
    ll pares = 0;
    fre(CARTAS) {
        pares += (cant[e]*(cant[e]-1))/2;
    }

    ll runs = 0;
    ll largo = 0;
    ll runs_local = 1;
    fre(CARTAS) {
        if (cant[e] > 0) {
            largo += 1;
            runs_local *= cant[e];
        } else {
            if (largo >= 3){
                runs += runs_local * largo;
            }
            largo = 0;
            runs_local = 1;
        }
    }
    if (largo > 2){
        runs += runs_local * largo;
    }

    vector<ll> cartasValor;
    cartasValor.pb(0);
    fre(cartas){
        if (e == 'A'){
            cartasValor.pb(1);
        } else if (e == 'T' || e == 'J' || e == 'K' || e == 'Q'){
            cartasValor.pb(10);
        } else {
            cartasValor.pb(e-'0');
        }
    }
    
    fr(0,n+1){
        rep(j,0,16){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    fr(1,n+1){
        rep(j,0,16){
            if (j - cartasValor[i] >= 0){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-cartasValor[i]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << runs + pares * 2 + dp[n][15] * 2 << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<char> cartas(n);
    fr(0, n) {
        char c; cin >> c;
        cartas[i] = c;
        cant[c] = 0;
    }

    solve(n, cartas);
}

MATH, DOUBLES

int main() {
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
                cur = static_cast<long double>(1.0 + k * (j - 1)) / static_cast<long double>(i * j * k); 
                // cout(cur);
                // cout(fabs((j - 1) * k + 1.0 / (i * j * k) - res));
                // cout(fabs(cur-res));
                // if (i==250 && j == 2 && k == 2){
                //     prDouble(cur);
                // }
                if ( fabs(cur - res) < best){
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

MAPA DE LETRAS

int main() {
    string ini, fin;
    cin >> ini >> fin;
    string cur = ini;
    vector<string> numbers;

    int res = 1;
    while (cur != fin){
        string number = "";
        res++;
        map<int, int> m;
        fr(0,cur.size()){
            m[cur[i] - '0']++;
        }
        fr(0,10){
            if (m[i] > 0){
                number = number + to_string(m[i]);
                number = number + to_string(i);
            }
        }
        if (number == fin){
            cout << res << endl;
            return 0;
        }
        //ver si encuentro al coso en el vector
        fr(0,numbers.size()){
            if (numbers[i] == number){
                int dif = numbers.size() - i;
                if (dif <= 100){
                    cout << "Does not appear";
                    return 0;
                } else {
                    cout << "I'm bored";
                    return 0;
                }
            }
        }
        numbers.pb(number);
        cur = number;
    }
    cout(1);
}

SIMULACRO 4

USO DE LOWER BOUND

int main() {
    string s,t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    fr(0,n){
        v[s[i]-'a'].insert(i);
    }
    ll res = 1;
    ll pos = -1;
    fr(0,m){
        auto it = v[t[i]-'a'].lower_bound(pos+1);
        if (it != v[t[i]-'a'].end()){
            pos = *it;
        } else {
            if (i != m-1){
                pos = *v[t[i]-'a'].lower_bound(-1);
            }
            res+=1;
        }
    }
    cout(res);
}

SIMULACRO 6

USO DE TIE Y GETLINE

void solve() {
    int n, k;
    cin >> n >> k;
    map<string, pair<int,int>> m;
    string a;
    getline(cin,a); // para limpiar el buffer
    priority_queue<tuple<pair<int,int>, string>> pq;
    fr(0,3*n){
        // cout(i);
        string s;
        getline(cin , s);
        // cout(s);
        pair<int,int> p;
        if (m.find(s) != m.end()){
            auto it = m.find(s);
            p = mp(it->second.first + 1, i);
        } else {
            p = mp(1, i);
        }
        m[s] = p;
    }
    for (auto it = m.rbegin(); it != m.rend(); ++it){
        pq.push(tuple(it->second, it->first));
    } 
    while(k>0 && !pq.empty()){
        pair<int, int> p2;
        string s2;
        tie(p2,s2) = pq.top();
        pq.pop();
        cout << s2 << "\n";
        k-=1;
    }
}

UNION FIND + BUSQUEDA BINARIA EN FLOATS

class UnionFind { // OOP style
    private: vi p, rank; // remember: vi is vector<int>
    public:
        UnionFind(int N) { 
            rank.assign(N, 0);
            p.assign(N, 0); 
            for (int i = 0; i < N; i++) p[i] = i; 
        }
        
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else { p[x] = y;
            if (rank[x] == rank[y]) rank[y]++; }
            } 
        } 
};

ld res;

bool hayCamino(ld mid, tuple<ld, ld>* puntos, ll n,ld x, ld y){
    UnionFind u(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++){
            ld x1 = get<0>(puntos[i]);
            ld y1 = get<1>(puntos[i]);
            ld x2 = get<0>(puntos[j]);
            ld y2 = get<1>(puntos[j]);
            if (sqrt(((x2 - x1) * ((x2 - x1)) + (y2 - y1) * (y2 - y1))) < (mid * 2.0)){
                // cout << "Uno " << "(" << x1 << ',' << y1 << ") con (" << x2 << ',' << y2 << ')' << endl;
                u.unionSet(i,j);
            }
            // cout << "(" << get<0>(puntos[i]) << ", " << get<1>(puntos[i]) << ")" << endl;
        }
    }
    map<int, set<tuple<ld,ld>>> component_points;
    for (int i = 0; i < n; i++) {
        int component_rep = u.findSet(i);
        component_points[component_rep].insert(puntos[i]);
    }
    
    //chequeo las componentes y si alguna intersecta el NW o el SE retorno false
    for (auto component: component_points){
        int component_rep = component.first;
        // cout << component_rep << endl;
        set<tuple<ld,ld>> points = component.second;
        bool tocaWN = false;
        bool tocaSE = false;
        for(auto point: points){
            //actualizar si tocaWN y tocaSE
            ld x1 = get<0>(point);
            ld y1 = get<1>(point);
            if (x1 - mid <= 0){
                tocaWN = true;
            }
            if (y1 - mid <= 0){
                tocaSE = true;
            }
            if (x1 + mid >= x){
                tocaSE = true;
            }
            if (y1 + mid >= y){
                tocaWN = true;
            }
            if (tocaWN && tocaSE){
                return false;
            }
        }
    }

    return true;
}

void solve() {
    ld x,y; cin >> x >> y;
    int n; cin >> n;
    tuple<ld,ld> puntos[n]; 
    fr(0,n){
        ld x1,y1; cin >> x1 >> y1;
        puntos[i] = {x1,y1};
        if (x1 == x && y1 == y || x1 == 0.0 && y1 == 0.0){
            prDouble(0.0);
            return;
        }
    }
    ld left = 0.0;
    ld right = x + y;
    res = right;
    ld epsilon = 1e-14;
    while (right - left > epsilon){
        ld mid = left + (right - left) / 2.0;
        // debug(mid);
        if (hayCamino(mid, puntos, n, x, y)){
            res = mid;
            left = mid + epsilon;
        } else {
            right = mid - epsilon;
        }
    }
    prDouble(res);
}

int main() {
    int cases = 1;
    while(cases--){
        solve();
    }
}

HASHES 

#define p 256
string res;
string s;

vi precompute_hashes(const string& s){
    vi hashes(s.size() + 1, 0);
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++) {
        hash = (hash * p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}

ll get_hash(const vi& hashes, ll l, ll r, const vi& potencias){ // Added potencias as a parameter
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod)+ mod) % mod);
}

bool existe(ll mid,vi hashes,vi potencias, ll largo){
    unordered_map<ll,pair<ll,ll>> m; //guardar cantidad, posicion donde arranca
    // ll hashInicial = hashes[mid];
    // m[hashInicial]=mp(1,0);
    pair<ll, ll> p2;
    fr(0, largo - mid + 1){
        ll curHash = get_hash(hashes, i+1, i+mid, potencias);
        if (m.find(curHash) != m.end()){
            p2 = m[curHash];
            m[curHash] = mp(p2.first + 1, i);
        } else {
            m[curHash] = mp(1LL, i);
        }
    }
    // debug(m);
    // veo si alguno tiene uno y la posicion en donde arranca
    bool hay = false;
    ll posInicial = 10000000;
    for(auto e: m){
        if (e.second.first == 1){
            hay = true;
            posInicial = min(e.second.second, posInicial);
        }
    }
    // debug(mid);
    // debug(hay);
    if (hay){
        res = s.substr(posInicial, mid);
        return true;
    } else {
        return false;
    }
}

void solve() {
    cin >> s;
    vi hashes = precompute_hashes(s);
    vi potencias(s.size()); // Moved potencias array to local scope and made its size dynamic
    potencias[0] = 1;
    for (ll i = 1; i < s.size(); i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }
    // debug(hashes);

    res = s;
    ll left = 1;
    ll right = s.size();
    while (left <= right){
        ll mid = (left) + (right-left) /2;
        if (existe(mid, hashes, potencias,s.size())){
            right = mid -1;
        } else {
            left = mid + 1;
        }
    }
    cout << res;
}

int main() {
    int cases = 1;
    while(cases--){
        solve();
    }
}

RATED CONTESTS

MATH (DIVISORES)

// Function to get the divisors
vector<int> getDivisors(int n)
{
    vector<int> res;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                res.pb(i);
  
            else // Otherwise print both
                res.pb(i);
                res.pb(n/i);
                // cout << " "<< i << " " << n/i;
        }
    }
    return res;
}


void solve() {
    ll n, m;
    cin >> n >> m;
    n %= m;
    if (n == 0){
        cout(0);
        return;
    }
    ll cur = 0;
    ll cantCortes = 0;
    ll curFraizen = 1;
    bool haySolucion = false;
    auto divisores = getDivisors(n);
    fr(0, divisores.size()){
        curFraizen = divisores[i];
        fr(0,32){
            if (curFraizen < m){
                curFraizen *= 2;
            } else if (curFraizen == m){
                haySolucion = true;
            } else {
                break;
            }
        }
        if (haySolucion){
            break;
        }
    }
    if (! haySolucion){
        curFraizen = 2;
        fr(0,32){
            if (curFraizen != m){
                curFraizen *= 2;
            } else {
                haySolucion = true;
            }
        }
        if (! haySolucion){
            cout(-1);
            return;
        }
    }

    while(true){
        cur = n;
        n *= 2;
        if (n >= m){
            n -= m;
            cantCortes += cur;
            if (n == 0){
                cout(cantCortes);
                return;
            }
        } else {
            // pedazos.insert(n);
            cantCortes += cur;
        }
    }
}

int main() {
    int cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }
}

SUMA DE GAUSS

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    ll minimo = k * (k+1) / 2;
    ll limInf = n-k;
    ll maximo = n * (n+1) / 2 - (limInf * (limInf+1) / 2);
    if(x >= minimo && x <= maximo){
        cout("YES");
    } else {
        cout("NO");
    }
}

QUERIES CON BITSETS Y BUSQUEDA BINARIA


void solve() {
    int n;
    cin >> n;
    int prefix[n+1][32];
    int arr[n+1];
    fr(1,n+1){
        cin >> arr[i];
    }
    //precomputo
    fr(0,n+1){
        rep(j,0,32){
            prefix[i][j] = 0;
        }
    }
    fr(1,n+1){
        //agarramos el numero arr[i] y le sumamos lo que ya teniamos. 
        int number = arr[i];
        int pos = 0;
        rep(j,0,32){
            prefix[i][j] = prefix[i-1][j];
        }
        while(number > 0){
            if (number & 1){
                prefix[i][pos]++;
            }
            pos++;
            number/=2;
        }
    }

    int q;
    cin >> q;
    fr(0,q){
        int a,b;
        cin >> a >> b;
        if (arr[a] < b){
            cout << "-1 ";
            continue;
        }
        int left = a;
        int right = n;
        int numero;
        int valid = -1;
        while(left <= right){
            // debug(left);
            // debug(right);
            int med = left + (right - left) / 2;
            int arrMed[32];
            // debug(med);
            // debug(a);
            rep(j,0,32){
                arrMed[j] = prefix[med][j] - prefix[a-1][j];
            }
            // rep(j,0,32){
            //     cout << arrMed[j] << ' ';
            // }
            numero = 0;
            rep(j,0,32){
                if (arrMed[j] == med - a + 1){
                    numero |= (1 << j); 
                }
            }
            // debug(numero);
            if (numero >= b){
                valid = max(med,valid);
                // debug(valid);
                left = med+1;
            } else {
                right = med-1;
            }
        }
        cout << valid << ' ';
    }
    cout << "\n";
}

int main() {
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
